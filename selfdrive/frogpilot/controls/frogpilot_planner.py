import cereal.messaging as messaging

from openpilot.common.conversions import Conversions as CV
from openpilot.common.params import Params

from openpilot.selfdrive.controls.lib.drive_helpers import V_CRUISE_UNSET
from openpilot.selfdrive.controls.lib.longitudinal_mpc_lib.long_mpc import A_CHANGE_COST, DANGER_ZONE_COST, J_EGO_COST, STOP_DISTANCE
from openpilot.selfdrive.controls.lib.longitudinal_planner import Lead

from openpilot.selfdrive.frogpilot.controls.lib.conditional_experimental_mode import ConditionalExperimentalMode
from openpilot.selfdrive.frogpilot.controls.lib.frogpilot_acceleration import FrogPilotAcceleration
from openpilot.selfdrive.frogpilot.controls.lib.frogpilot_events import FrogPilotEvents
from openpilot.selfdrive.frogpilot.controls.lib.frogpilot_following import FrogPilotFollowing
from openpilot.selfdrive.frogpilot.controls.lib.frogpilot_vcruise import FrogPilotVCruise
from openpilot.selfdrive.frogpilot.frogpilot_utilities import MovingAverageCalculator, calculate_lane_width, calculate_road_curvature, update_frogpilot_toggles
from openpilot.selfdrive.frogpilot.frogpilot_variables import CRUISING_SPEED, MODEL_LENGTH, NON_DRIVING_GEARS, PLANNER_TIME, THRESHOLD

class FrogPilotPlanner:
  def __init__(self):
    self.params_memory = Params("/dev/shm/params")

    self.cem = ConditionalExperimentalMode(self)
    self.frogpilot_acceleration = FrogPilotAcceleration(self)
    self.frogpilot_events = FrogPilotEvents(self)
    self.frogpilot_following = FrogPilotFollowing(self)
    self.frogpilot_vcruise = FrogPilotVCruise(self)
    self.lead_one = Lead()

    self.tracking_lead_mac = MovingAverageCalculator()

    self.lateral_check = False
    self.lead_departing = False
    self.model_stopped = False
    self.slower_lead = False
    self.taking_curve_quickly = False
    self.tracking_lead = False

    self.model_length = 0
    self.road_curvature = 1
    self.tracking_lead_distance = 0
    self.v_cruise = 0

  def update(self, carState, controlsState, frogpilotCarControl, frogpilotCarState, frogpilotNavigation, modelData, radarless_model, radarState, frogpilot_toggles):
    if radarless_model:
      model_leads = list(modelData.leadsV3)
      if len(model_leads) > 0:
        model_lead = model_leads[0]
        self.lead_one.update(model_lead.x[0], model_lead.y[0], model_lead.v[0], model_lead.a[0], model_lead.prob)
      else:
        self.lead_one.reset()
    else:
      self.lead_one = radarState.leadOne

    v_cruise = min(controlsState.vCruise, V_CRUISE_UNSET) * CV.KPH_TO_MS
    v_ego = max(carState.vEgo, 0)
    v_lead = self.lead_one.vLead

    driving_gear = carState.gearShifter not in NON_DRIVING_GEARS

    distance_offset = max(frogpilot_toggles.increase_stopped_distance + min(10 - v_ego, 0), 0) if not frogpilotCarState.trafficModeActive else 0
    lead_distance = self.lead_one.dRel - distance_offset
    stopping_distance = STOP_DISTANCE + distance_offset

    self.frogpilot_acceleration.update(controlsState, frogpilotCarState, v_cruise, v_ego, frogpilot_toggles)

    run_cem = frogpilot_toggles.conditional_experimental_mode or frogpilot_toggles.force_stops or frogpilot_toggles.green_light_alert or frogpilot_toggles.show_stopping_point
    if run_cem and (controlsState.enabled or frogpilotCarControl.alwaysOnLateralActive) and driving_gear:
      self.cem.update(carState, frogpilotNavigation, modelData, v_ego, v_lead, frogpilot_toggles)
    else:
      self.cem.stop_light_detected = False

    self.frogpilot_events.update(carState, controlsState, frogpilotCarControl, frogpilotCarState, modelData, frogpilot_toggles)
    self.frogpilot_following.update(carState.aEgo, controlsState, frogpilotCarState, lead_distance, stopping_distance, v_ego, v_lead, frogpilot_toggles)

    check_lane_width = frogpilot_toggles.adjacent_lanes or frogpilot_toggles.adjacent_path_metrics or frogpilot_toggles.blind_spot_path or frogpilot_toggles.lane_detection
    if check_lane_width and v_ego >= frogpilot_toggles.minimum_lane_change_speed or frogpilot_toggles.adjacent_lead_tracking_ui:
      self.lane_width_left = calculate_lane_width(modelData.laneLines[0], modelData.laneLines[1], modelData.roadEdges[0])
      self.lane_width_right = calculate_lane_width(modelData.laneLines[3], modelData.laneLines[2], modelData.roadEdges[1])
    else:
      self.lane_width_left = 0
      self.lane_width_right = 0

    if frogpilot_toggles.lead_departing_alert and self.tracking_lead and driving_gear and carState.standstill:
      if self.tracking_lead_distance == 0:
        self.tracking_lead_distance = lead_distance

      self.lead_departing = lead_distance - self.tracking_lead_distance > 1
      self.lead_departing &= v_lead > 1
    else:
      self.lead_departing = False
      self.tracking_lead_distance = 0

    self.lateral_check = v_ego >= frogpilot_toggles.pause_lateral_below_speed
    self.lateral_check |= frogpilot_toggles.pause_lateral_below_signal and not (carState.leftBlinker or carState.rightBlinker)
    self.lateral_check |= carState.standstill

    self.model_length = modelData.position.x[MODEL_LENGTH - 1]
    self.model_stopped = self.model_length < CRUISING_SPEED * PLANNER_TIME
    self.model_stopped |= self.frogpilot_vcruise.forcing_stop

    self.road_curvature = calculate_road_curvature(modelData, v_ego) if not carState.standstill else 1

    if frogpilot_toggles.random_events and v_ego > CRUISING_SPEED and driving_gear:
      self.taking_curve_quickly = v_ego > (1 / self.road_curvature)**0.75 * 2 > CRUISING_SPEED * 2 and abs(carState.steeringAngleDeg) > 30
    else:
      self.taking_curve_quickly = False

    self.tracking_lead = self.set_lead_status(lead_distance, stopping_distance, v_ego)
    self.v_cruise = self.frogpilot_vcruise.update(carState, controlsState, frogpilotCarControl, frogpilotCarState, frogpilotNavigation, modelData, v_cruise, v_ego, frogpilot_toggles)

    if self.frogpilot_events.frame == 1:  # Force update to check the current state of "Always On Lateral" and holiday theme
      update_frogpilot_toggles()

  def set_lead_status(self, lead_distance, stopping_distance, v_ego):
    following_lead = self.lead_one.status
    following_lead &= 1 < lead_distance < self.model_length + stopping_distance
    following_lead &= v_ego > CRUISING_SPEED or self.tracking_lead

    self.tracking_lead_mac.add_data(following_lead)
    return self.tracking_lead_mac.get_moving_average() >= THRESHOLD

  def publish(self, sm, pm, frogpilot_toggles):
    frogpilot_plan_send = messaging.new_message('frogpilotPlan')
    frogpilot_plan_send.valid = sm.all_checks(service_list=['carState', 'controlsState'])
    frogpilotPlan = frogpilot_plan_send.frogpilotPlan

    frogpilotPlan.accelerationJerk = float(A_CHANGE_COST * self.frogpilot_following.acceleration_jerk)
    frogpilotPlan.accelerationJerkStock = float(A_CHANGE_COST * self.frogpilot_following.base_acceleration_jerk)
    frogpilotPlan.dangerJerk = float(DANGER_ZONE_COST * self.frogpilot_following.danger_jerk)
    frogpilotPlan.speedJerk = float(J_EGO_COST * self.frogpilot_following.speed_jerk)
    frogpilotPlan.speedJerkStock = float(J_EGO_COST * self.frogpilot_following.base_speed_jerk)
    frogpilotPlan.tFollow = float(self.frogpilot_following.t_follow)

    frogpilotPlan.adjustedCruise = float(min(self.frogpilot_vcruise.mtsc_target, self.frogpilot_vcruise.vtsc_target) * (CV.MS_TO_KPH if frogpilot_toggles.is_metric else CV.MS_TO_MPH))
    frogpilotPlan.vtscControllingCurve = bool(self.frogpilot_vcruise.mtsc_target > self.frogpilot_vcruise.vtsc_target)

    frogpilotPlan.desiredFollowDistance = self.frogpilot_following.safe_obstacle_distance - self.frogpilot_following.stopped_equivalence_factor
    frogpilotPlan.safeObstacleDistance = self.frogpilot_following.safe_obstacle_distance
    frogpilotPlan.safeObstacleDistanceStock = self.frogpilot_following.safe_obstacle_distance_stock
    frogpilotPlan.stoppedEquivalenceFactor = self.frogpilot_following.stopped_equivalence_factor

    frogpilotPlan.experimentalMode = self.cem.experimental_mode or self.frogpilot_vcruise.slc.experimental_mode

    frogpilotPlan.forcingStop = self.frogpilot_vcruise.forcing_stop

    frogpilotPlan.frogpilotEvents = self.frogpilot_events.events.to_msg()

    frogpilotPlan.laneWidthLeft = self.lane_width_left
    frogpilotPlan.laneWidthRight = self.lane_width_right

    frogpilotPlan.lateralCheck = self.lateral_check

    frogpilotPlan.maxAcceleration = float(self.frogpilot_acceleration.max_accel)
    frogpilotPlan.minAcceleration = float(self.frogpilot_acceleration.min_accel)

    frogpilotPlan.redLight = bool(self.cem.stop_light_detected)

    frogpilotPlan.slcOverridden = bool(self.frogpilot_vcruise.override_slc)
    frogpilotPlan.slcOverriddenSpeed = float(self.frogpilot_vcruise.overridden_speed)
    frogpilotPlan.slcSpeedLimit = self.frogpilot_vcruise.slc_target
    frogpilotPlan.slcSpeedLimitOffset = self.frogpilot_vcruise.slc.offset
    frogpilotPlan.speedLimitChanged = self.frogpilot_vcruise.speed_limit_changed
    frogpilotPlan.unconfirmedSlcSpeedLimit = self.frogpilot_vcruise.slc.desired_speed_limit

    frogpilotPlan.vCruise = self.v_cruise

    pm.send('frogpilotPlan', frogpilot_plan_send)

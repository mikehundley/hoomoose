/****************************************************************************
** Meta object code from reading C++ file 'frogpilot_settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "frogpilot_settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frogpilot_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrogPilotSettingsWindow_t {
    QByteArrayData data[15];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrogPilotSettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrogPilotSettingsWindow_t qt_meta_stringdata_FrogPilotSettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 23), // "FrogPilotSettingsWindow"
QT_MOC_LITERAL(1, 24, 23), // "closeMapBoxInstructions"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 17), // "closeMapSelection"
QT_MOC_LITERAL(4, 67, 17), // "closeParentToggle"
QT_MOC_LITERAL(5, 85, 20), // "closeSubParentToggle"
QT_MOC_LITERAL(6, 106, 23), // "closeSubSubParentToggle"
QT_MOC_LITERAL(7, 130, 22), // "openMapBoxInstructions"
QT_MOC_LITERAL(8, 153, 16), // "openMapSelection"
QT_MOC_LITERAL(9, 170, 9), // "openPanel"
QT_MOC_LITERAL(10, 180, 16), // "openParentToggle"
QT_MOC_LITERAL(11, 197, 19), // "openSubParentToggle"
QT_MOC_LITERAL(12, 217, 22), // "openSubSubParentToggle"
QT_MOC_LITERAL(13, 240, 16), // "updateCarToggles"
QT_MOC_LITERAL(14, 257, 12) // "updateMetric"

    },
    "FrogPilotSettingsWindow\0closeMapBoxInstructions\0"
    "\0closeMapSelection\0closeParentToggle\0"
    "closeSubParentToggle\0closeSubSubParentToggle\0"
    "openMapBoxInstructions\0openMapSelection\0"
    "openPanel\0openParentToggle\0"
    "openSubParentToggle\0openSubSubParentToggle\0"
    "updateCarToggles\0updateMetric"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrogPilotSettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,
      14,    0,   91,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrogPilotSettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrogPilotSettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeMapBoxInstructions(); break;
        case 1: _t->closeMapSelection(); break;
        case 2: _t->closeParentToggle(); break;
        case 3: _t->closeSubParentToggle(); break;
        case 4: _t->closeSubSubParentToggle(); break;
        case 5: _t->openMapBoxInstructions(); break;
        case 6: _t->openMapSelection(); break;
        case 7: _t->openPanel(); break;
        case 8: _t->openParentToggle(); break;
        case 9: _t->openSubParentToggle(); break;
        case 10: _t->openSubSubParentToggle(); break;
        case 11: _t->updateCarToggles(); break;
        case 12: _t->updateMetric(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeMapBoxInstructions)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeMapSelection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeParentToggle)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeSubParentToggle)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeSubSubParentToggle)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openMapBoxInstructions)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openMapSelection)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openPanel)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openParentToggle)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openSubParentToggle)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openSubSubParentToggle)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::updateCarToggles)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::updateMetric)) {
                *result = 12;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FrogPilotSettingsWindow::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_FrogPilotSettingsWindow.data,
    qt_meta_data_FrogPilotSettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrogPilotSettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrogPilotSettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrogPilotSettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int FrogPilotSettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FrogPilotSettingsWindow::closeMapBoxInstructions()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FrogPilotSettingsWindow::closeMapSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FrogPilotSettingsWindow::closeParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FrogPilotSettingsWindow::closeSubParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FrogPilotSettingsWindow::closeSubSubParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FrogPilotSettingsWindow::openMapBoxInstructions()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FrogPilotSettingsWindow::openMapSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void FrogPilotSettingsWindow::openPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void FrogPilotSettingsWindow::openParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void FrogPilotSettingsWindow::openSubParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void FrogPilotSettingsWindow::openSubSubParentToggle()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void FrogPilotSettingsWindow::updateCarToggles()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void FrogPilotSettingsWindow::updateMetric()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

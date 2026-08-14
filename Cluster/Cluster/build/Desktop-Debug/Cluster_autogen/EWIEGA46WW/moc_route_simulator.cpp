/****************************************************************************
** Meta object code from reading C++ file 'route_simulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../route_simulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'route_simulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RouteSimulator_t {
    QByteArrayData data[14];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RouteSimulator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RouteSimulator_t qt_meta_stringdata_RouteSimulator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RouteSimulator"
QT_MOC_LITERAL(1, 15, 15), // "positionChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "headingChanged"
QT_MOC_LITERAL(4, 47, 12), // "speedChanged"
QT_MOC_LITERAL(5, 60, 10), // "updateTick"
QT_MOC_LITERAL(6, 71, 8), // "setRoute"
QT_MOC_LITERAL(7, 80, 11), // "coordinates"
QT_MOC_LITERAL(8, 92, 15), // "startSimulation"
QT_MOC_LITERAL(9, 108, 14), // "stopSimulation"
QT_MOC_LITERAL(10, 123, 15), // "currentPosition"
QT_MOC_LITERAL(11, 139, 14), // "QGeoCoordinate"
QT_MOC_LITERAL(12, 154, 7), // "heading"
QT_MOC_LITERAL(13, 162, 8) // "speedKmh"

    },
    "RouteSimulator\0positionChanged\0\0"
    "headingChanged\0speedChanged\0updateTick\0"
    "setRoute\0coordinates\0startSimulation\0"
    "stopSimulation\0currentPosition\0"
    "QGeoCoordinate\0heading\0speedKmh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RouteSimulator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x02 /* Public */,
       8,    0,   56,    2, 0x02 /* Public */,
       9,    0,   57,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    7,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00495009,
      12, QMetaType::Double, 0x00495001,
      13, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void RouteSimulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RouteSimulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->positionChanged(); break;
        case 1: _t->headingChanged(); break;
        case 2: _t->speedChanged(); break;
        case 3: _t->updateTick(); break;
        case 4: _t->setRoute((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 5: _t->startSimulation(); break;
        case 6: _t->stopSimulation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RouteSimulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RouteSimulator::positionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RouteSimulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RouteSimulator::headingChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RouteSimulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RouteSimulator::speedChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RouteSimulator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QGeoCoordinate*>(_v) = _t->currentPosition(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->heading(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->speedKmh(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RouteSimulator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSpeedKmh(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RouteSimulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RouteSimulator.data,
    qt_meta_data_RouteSimulator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RouteSimulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RouteSimulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RouteSimulator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RouteSimulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RouteSimulator::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RouteSimulator::headingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RouteSimulator::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

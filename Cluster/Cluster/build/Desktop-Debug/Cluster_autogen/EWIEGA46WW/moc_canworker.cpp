/****************************************************************************
** Meta object code from reading C++ file 'canworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../canworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CanWorker_t {
    QByteArrayData data[17];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanWorker_t qt_meta_stringdata_CanWorker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CanWorker"
QT_MOC_LITERAL(1, 10, 15), // "canDataReceived"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "speed"
QT_MOC_LITERAL(4, 33, 7), // "battery"
QT_MOC_LITERAL(5, 41, 19), // "warningDataReceived"
QT_MOC_LITERAL(6, 61, 4), // "left"
QT_MOC_LITERAL(7, 66, 5), // "right"
QT_MOC_LITERAL(8, 72, 3), // "cos"
QT_MOC_LITERAL(9, 76, 3), // "pha"
QT_MOC_LITERAL(10, 80, 4), // "belt"
QT_MOC_LITERAL(11, 85, 15), // "gpsDataReceived"
QT_MOC_LITERAL(12, 101, 3), // "lat"
QT_MOC_LITERAL(13, 105, 3), // "lng"
QT_MOC_LITERAL(14, 109, 5), // "start"
QT_MOC_LITERAL(15, 115, 18), // "sendWarningCommand"
QT_MOC_LITERAL(16, 134, 12) // "readCanFrame"

    },
    "CanWorker\0canDataReceived\0\0speed\0"
    "battery\0warningDataReceived\0left\0right\0"
    "cos\0pha\0belt\0gpsDataReceived\0lat\0lng\0"
    "start\0sendWarningCommand\0readCanFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    5,   49,    2, 0x06 /* Public */,
      11,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   65,    2, 0x0a /* Public */,
      15,    5,   66,    2, 0x0a /* Public */,
      16,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void CanWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CanWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->canDataReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->warningDataReceived((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->gpsDataReceived((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->start(); break;
        case 4: _t->sendWarningCommand((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: _t->readCanFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CanWorker::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanWorker::canDataReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CanWorker::*)(bool , bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanWorker::warningDataReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CanWorker::*)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CanWorker::gpsDataReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CanWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CanWorker.data,
    qt_meta_data_CanWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CanWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CanWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CanWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CanWorker::canDataReceived(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CanWorker::warningDataReceived(bool _t1, bool _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CanWorker::gpsDataReceived(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

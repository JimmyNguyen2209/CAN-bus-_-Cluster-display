/****************************************************************************
** Meta object code from reading C++ file 'clustermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../clustermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clustermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClusterManager_t {
    QByteArrayData data[36];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClusterManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClusterManager_t qt_meta_stringdata_ClusterManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ClusterManager"
QT_MOC_LITERAL(1, 15, 15), // "canDataReceived"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "speed"
QT_MOC_LITERAL(4, 38, 7), // "battery"
QT_MOC_LITERAL(5, 46, 19), // "warningDataReceived"
QT_MOC_LITERAL(6, 66, 4), // "left"
QT_MOC_LITERAL(7, 71, 5), // "right"
QT_MOC_LITERAL(8, 77, 3), // "cos"
QT_MOC_LITERAL(9, 81, 3), // "pha"
QT_MOC_LITERAL(10, 85, 4), // "belt"
QT_MOC_LITERAL(11, 90, 14), // "spotifyChanged"
QT_MOC_LITERAL(12, 105, 5), // "title"
QT_MOC_LITERAL(13, 111, 6), // "artist"
QT_MOC_LITERAL(14, 118, 8), // "albumArt"
QT_MOC_LITERAL(15, 127, 15), // "loginUrlChanged"
QT_MOC_LITERAL(16, 143, 12), // "loginSuccess"
QT_MOC_LITERAL(17, 156, 16), // "isPlayingChanged"
QT_MOC_LITERAL(18, 173, 18), // "requestPauseResume"
QT_MOC_LITERAL(19, 192, 16), // "requestNextTrack"
QT_MOC_LITERAL(20, 209, 20), // "requestPreviousTrack"
QT_MOC_LITERAL(21, 230, 25), // "requestSendWarningCommand"
QT_MOC_LITERAL(22, 256, 13), // "handleCanData"
QT_MOC_LITERAL(23, 270, 17), // "handleWarningData"
QT_MOC_LITERAL(24, 288, 17), // "handleSpotifyData"
QT_MOC_LITERAL(25, 306, 19), // "handlePlaybackState"
QT_MOC_LITERAL(26, 326, 7), // "playing"
QT_MOC_LITERAL(27, 334, 11), // "setLoginUrl"
QT_MOC_LITERAL(28, 346, 3), // "url"
QT_MOC_LITERAL(29, 350, 18), // "handleLoginSuccess"
QT_MOC_LITERAL(30, 369, 19), // "toggleWarningFromUI"
QT_MOC_LITERAL(31, 389, 11), // "pauseResume"
QT_MOC_LITERAL(32, 401, 9), // "nextTrack"
QT_MOC_LITERAL(33, 411, 13), // "previousTrack"
QT_MOC_LITERAL(34, 425, 8), // "loginUrl"
QT_MOC_LITERAL(35, 434, 9) // "isPlaying"

    },
    "ClusterManager\0canDataReceived\0\0speed\0"
    "battery\0warningDataReceived\0left\0right\0"
    "cos\0pha\0belt\0spotifyChanged\0title\0"
    "artist\0albumArt\0loginUrlChanged\0"
    "loginSuccess\0isPlayingChanged\0"
    "requestPauseResume\0requestNextTrack\0"
    "requestPreviousTrack\0requestSendWarningCommand\0"
    "handleCanData\0handleWarningData\0"
    "handleSpotifyData\0handlePlaybackState\0"
    "playing\0setLoginUrl\0url\0handleLoginSuccess\0"
    "toggleWarningFromUI\0pauseResume\0"
    "nextTrack\0previousTrack\0loginUrl\0"
    "isPlaying"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClusterManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       2,  198, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  114,    2, 0x06 /* Public */,
       5,    5,  119,    2, 0x06 /* Public */,
      11,    3,  130,    2, 0x06 /* Public */,
      15,    0,  137,    2, 0x06 /* Public */,
      16,    0,  138,    2, 0x06 /* Public */,
      17,    0,  139,    2, 0x06 /* Public */,
      18,    0,  140,    2, 0x06 /* Public */,
      19,    0,  141,    2, 0x06 /* Public */,
      20,    0,  142,    2, 0x06 /* Public */,
      21,    5,  143,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    2,  154,    2, 0x0a /* Public */,
      23,    5,  159,    2, 0x0a /* Public */,
      24,    3,  170,    2, 0x0a /* Public */,
      25,    1,  177,    2, 0x0a /* Public */,
      27,    1,  180,    2, 0x0a /* Public */,
      29,    0,  183,    2, 0x0a /* Public */,
      30,    5,  184,    2, 0x0a /* Public */,
      31,    0,  195,    2, 0x0a /* Public */,
      32,    0,  196,    2, 0x0a /* Public */,
      33,    0,  197,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      34, QMetaType::QString, 0x00495001,
      35, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       3,
       5,

       0        // eod
};

void ClusterManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClusterManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->canDataReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->warningDataReceived((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->spotifyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->loginUrlChanged(); break;
        case 4: _t->loginSuccess(); break;
        case 5: _t->isPlayingChanged(); break;
        case 6: _t->requestPauseResume(); break;
        case 7: _t->requestNextTrack(); break;
        case 8: _t->requestPreviousTrack(); break;
        case 9: _t->requestSendWarningCommand((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 10: _t->handleCanData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->handleWarningData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 12: _t->handleSpotifyData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 13: _t->handlePlaybackState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setLoginUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->handleLoginSuccess(); break;
        case 16: _t->toggleWarningFromUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 17: _t->pauseResume(); break;
        case 18: _t->nextTrack(); break;
        case 19: _t->previousTrack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClusterManager::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::canDataReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)(bool , bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::warningDataReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::spotifyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::loginUrlChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::loginSuccess)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::isPlayingChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::requestPauseResume)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::requestNextTrack)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::requestPreviousTrack)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ClusterManager::*)(bool , bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClusterManager::requestSendWarningCommand)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ClusterManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->loginUrl(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isPlaying(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ClusterManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ClusterManager.data,
    qt_meta_data_ClusterManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClusterManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClusterManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClusterManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClusterManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ClusterManager::canDataReceived(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClusterManager::warningDataReceived(bool _t1, bool _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClusterManager::spotifyChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClusterManager::loginUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClusterManager::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ClusterManager::isPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ClusterManager::requestPauseResume()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ClusterManager::requestNextTrack()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ClusterManager::requestPreviousTrack()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ClusterManager::requestSendWarningCommand(bool _t1, bool _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

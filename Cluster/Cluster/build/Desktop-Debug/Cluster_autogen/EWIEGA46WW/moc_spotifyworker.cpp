/****************************************************************************
** Meta object code from reading C++ file 'spotifyworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../spotifyworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spotifyworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpotifyWorker_t {
    QByteArrayData data[20];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpotifyWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpotifyWorker_t qt_meta_stringdata_SpotifyWorker = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SpotifyWorker"
QT_MOC_LITERAL(1, 14, 14), // "spotifyChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "title"
QT_MOC_LITERAL(4, 36, 6), // "artist"
QT_MOC_LITERAL(5, 43, 5), // "album"
QT_MOC_LITERAL(6, 49, 20), // "playbackStateChanged"
QT_MOC_LITERAL(7, 70, 9), // "isPlaying"
QT_MOC_LITERAL(8, 80, 12), // "loginSuccess"
QT_MOC_LITERAL(9, 93, 5), // "start"
QT_MOC_LITERAL(10, 99, 11), // "pauseResume"
QT_MOC_LITERAL(11, 111, 9), // "nextTrack"
QT_MOC_LITERAL(12, 121, 13), // "previousTrack"
QT_MOC_LITERAL(13, 135, 18), // "refreshAccessToken"
QT_MOC_LITERAL(14, 154, 22), // "fetchAndActivateDevice"
QT_MOC_LITERAL(15, 177, 20), // "fetchCurrentPlayback"
QT_MOC_LITERAL(16, 198, 18), // "onPlaybackReceived"
QT_MOC_LITERAL(17, 217, 14), // "QNetworkReply*"
QT_MOC_LITERAL(18, 232, 5), // "reply"
QT_MOC_LITERAL(19, 238, 22) // "onControlReplyFinished"

    },
    "SpotifyWorker\0spotifyChanged\0\0title\0"
    "artist\0album\0playbackStateChanged\0"
    "isPlaying\0loginSuccess\0start\0pauseResume\0"
    "nextTrack\0previousTrack\0refreshAccessToken\0"
    "fetchAndActivateDevice\0fetchCurrentPlayback\0"
    "onPlaybackReceived\0QNetworkReply*\0"
    "reply\0onControlReplyFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpotifyWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       6,    1,   81,    2, 0x06 /* Public */,
       8,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   85,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void SpotifyWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpotifyWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->spotifyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->playbackStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->loginSuccess(); break;
        case 3: _t->start(); break;
        case 4: _t->pauseResume(); break;
        case 5: _t->nextTrack(); break;
        case 6: _t->previousTrack(); break;
        case 7: _t->refreshAccessToken(); break;
        case 8: _t->fetchAndActivateDevice(); break;
        case 9: _t->fetchCurrentPlayback(); break;
        case 10: _t->onPlaybackReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->onControlReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpotifyWorker::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpotifyWorker::spotifyChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpotifyWorker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpotifyWorker::playbackStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpotifyWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpotifyWorker::loginSuccess)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpotifyWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SpotifyWorker.data,
    qt_meta_data_SpotifyWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpotifyWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpotifyWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpotifyWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SpotifyWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SpotifyWorker::spotifyChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpotifyWorker::playbackStateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpotifyWorker::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

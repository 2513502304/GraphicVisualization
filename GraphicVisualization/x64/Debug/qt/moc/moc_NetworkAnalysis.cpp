/****************************************************************************
** Meta object code from reading C++ file 'NetworkAnalysis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../NetworkAnalysis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkAnalysis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkAnalysis_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkAnalysis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkAnalysis_t qt_meta_stringdata_NetworkAnalysis = {
    {
QT_MOC_LITERAL(0, 0, 15) // "NetworkAnalysis"

    },
    "NetworkAnalysis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkAnalysis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void NetworkAnalysis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NetworkAnalysis::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetworkAnalysis.data,
    qt_meta_data_NetworkAnalysis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetworkAnalysis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkAnalysis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkAnalysis.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkAnalysis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ShortestPathPointToPointProxy_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShortestPathPointToPointProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShortestPathPointToPointProxy_t qt_meta_stringdata_ShortestPathPointToPointProxy = {
    {
QT_MOC_LITERAL(0, 0, 29), // "ShortestPathPointToPointProxy"
QT_MOC_LITERAL(1, 30, 34), // "drawShortestPathPointToPointS..."
QT_MOC_LITERAL(2, 65, 0), // ""
QT_MOC_LITERAL(3, 66, 13), // "vector<Place>"
QT_MOC_LITERAL(4, 80, 5), // "place"
QT_MOC_LITERAL(5, 86, 12), // "vector<Path>"
QT_MOC_LITERAL(6, 99, 4) // "path"

    },
    "ShortestPathPointToPointProxy\0"
    "drawShortestPathPointToPointSignal\0\0"
    "vector<Place>\0place\0vector<Path>\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShortestPathPointToPointProxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void ShortestPathPointToPointProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShortestPathPointToPointProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawShortestPathPointToPointSignal((*reinterpret_cast< const vector<Place>(*)>(_a[1])),(*reinterpret_cast< const vector<Path>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShortestPathPointToPointProxy::*)(const vector<Place> & , const vector<Path> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortestPathPointToPointProxy::drawShortestPathPointToPointSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShortestPathPointToPointProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<NetworkAnalysis::staticMetaObject>(),
    qt_meta_stringdata_ShortestPathPointToPointProxy.data,
    qt_meta_data_ShortestPathPointToPointProxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShortestPathPointToPointProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShortestPathPointToPointProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShortestPathPointToPointProxy.stringdata0))
        return static_cast<void*>(this);
    return NetworkAnalysis::qt_metacast(_clname);
}

int ShortestPathPointToPointProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NetworkAnalysis::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ShortestPathPointToPointProxy::drawShortestPathPointToPointSignal(const vector<Place> & _t1, const vector<Path> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

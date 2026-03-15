/****************************************************************************
** Meta object code from reading C++ file 'GraphItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GraphItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphItem_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphItem_t qt_meta_stringdata_GraphItem = {
    {
QT_MOC_LITERAL(0, 0, 9) // "GraphItem"

    },
    "GraphItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphItem[] = {

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

void GraphItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GraphItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GraphItem.data,
    qt_meta_data_GraphItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int GraphItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PointItem_t {
    QByteArrayData data[4];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PointItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PointItem_t qt_meta_stringdata_PointItem = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PointItem"
QT_MOC_LITERAL(1, 10, 13), // "PointSelected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 2) // "id"

    },
    "PointItem\0PointSelected\0\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PointItem[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void PointItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PointItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PointSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PointItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PointItem::PointSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PointItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_PointItem.data,
    qt_meta_data_PointItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PointItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PointItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PointItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int PointItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
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
void PointItem::PointSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_LineItem_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineItem_t qt_meta_stringdata_LineItem = {
    {
QT_MOC_LITERAL(0, 0, 8) // "LineItem"

    },
    "LineItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineItem[] = {

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

void LineItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LineItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_LineItem.data,
    qt_meta_data_LineItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LineItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int LineItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PolylineItem_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolylineItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolylineItem_t qt_meta_stringdata_PolylineItem = {
    {
QT_MOC_LITERAL(0, 0, 12) // "PolylineItem"

    },
    "PolylineItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolylineItem[] = {

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

void PolylineItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PolylineItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_PolylineItem.data,
    qt_meta_data_PolylineItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolylineItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolylineItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolylineItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int PolylineItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RectangleItem_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RectangleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RectangleItem_t qt_meta_stringdata_RectangleItem = {
    {
QT_MOC_LITERAL(0, 0, 13) // "RectangleItem"

    },
    "RectangleItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RectangleItem[] = {

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

void RectangleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RectangleItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_RectangleItem.data,
    qt_meta_data_RectangleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RectangleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RectangleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RectangleItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int RectangleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CircleItem_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CircleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CircleItem_t qt_meta_stringdata_CircleItem = {
    {
QT_MOC_LITERAL(0, 0, 10) // "CircleItem"

    },
    "CircleItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CircleItem[] = {

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

void CircleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CircleItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_CircleItem.data,
    qt_meta_data_CircleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CircleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CircleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CircleItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int CircleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SectorItem_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SectorItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SectorItem_t qt_meta_stringdata_SectorItem = {
    {
QT_MOC_LITERAL(0, 0, 10) // "SectorItem"

    },
    "SectorItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SectorItem[] = {

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

void SectorItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SectorItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_SectorItem.data,
    qt_meta_data_SectorItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SectorItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SectorItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SectorItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int SectorItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PolygonItem_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolygonItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolygonItem_t qt_meta_stringdata_PolygonItem = {
    {
QT_MOC_LITERAL(0, 0, 11) // "PolygonItem"

    },
    "PolygonItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolygonItem[] = {

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

void PolygonItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PolygonItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_PolygonItem.data,
    qt_meta_data_PolygonItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolygonItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolygonItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolygonItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int PolygonItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CurveItem_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurveItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurveItem_t qt_meta_stringdata_CurveItem = {
    {
QT_MOC_LITERAL(0, 0, 9) // "CurveItem"

    },
    "CurveItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurveItem[] = {

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

void CurveItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CurveItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_CurveItem.data,
    qt_meta_data_CurveItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurveItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurveItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurveItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int CurveItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_TextItem_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextItem_t qt_meta_stringdata_TextItem = {
    {
QT_MOC_LITERAL(0, 0, 8) // "TextItem"

    },
    "TextItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextItem[] = {

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

void TextItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TextItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_TextItem.data,
    qt_meta_data_TextItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int TextItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PixmapItem_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PixmapItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PixmapItem_t qt_meta_stringdata_PixmapItem = {
    {
QT_MOC_LITERAL(0, 0, 10) // "PixmapItem"

    },
    "PixmapItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PixmapItem[] = {

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

void PixmapItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PixmapItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_PixmapItem.data,
    qt_meta_data_PixmapItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PixmapItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PixmapItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PixmapItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int PixmapItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ChessBoardItem_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessBoardItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessBoardItem_t qt_meta_stringdata_ChessBoardItem = {
    {
QT_MOC_LITERAL(0, 0, 14) // "ChessBoardItem"

    },
    "ChessBoardItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessBoardItem[] = {

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

void ChessBoardItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ChessBoardItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_ChessBoardItem.data,
    qt_meta_data_ChessBoardItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChessBoardItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessBoardItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessBoardItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int ChessBoardItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ConvexHullItem_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConvexHullItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConvexHullItem_t qt_meta_stringdata_ConvexHullItem = {
    {
QT_MOC_LITERAL(0, 0, 14) // "ConvexHullItem"

    },
    "ConvexHullItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConvexHullItem[] = {

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

void ConvexHullItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ConvexHullItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_ConvexHullItem.data,
    qt_meta_data_ConvexHullItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConvexHullItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConvexHullItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConvexHullItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int ConvexHullItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DecisionTreeItem_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DecisionTreeItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DecisionTreeItem_t qt_meta_stringdata_DecisionTreeItem = {
    {
QT_MOC_LITERAL(0, 0, 16) // "DecisionTreeItem"

    },
    "DecisionTreeItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecisionTreeItem[] = {

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

void DecisionTreeItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DecisionTreeItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_DecisionTreeItem.data,
    qt_meta_data_DecisionTreeItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DecisionTreeItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecisionTreeItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DecisionTreeItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int DecisionTreeItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ShortestPathPointToPointItem_t {
    QByteArrayData data[1];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShortestPathPointToPointItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShortestPathPointToPointItem_t qt_meta_stringdata_ShortestPathPointToPointItem = {
    {
QT_MOC_LITERAL(0, 0, 28) // "ShortestPathPointToPointItem"

    },
    "ShortestPathPointToPointItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShortestPathPointToPointItem[] = {

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

void ShortestPathPointToPointItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ShortestPathPointToPointItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphItem::staticMetaObject>(),
    qt_meta_stringdata_ShortestPathPointToPointItem.data,
    qt_meta_data_ShortestPathPointToPointItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShortestPathPointToPointItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShortestPathPointToPointItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShortestPathPointToPointItem.stringdata0))
        return static_cast<void*>(this);
    return GraphItem::qt_metacast(_clname);
}

int ShortestPathPointToPointItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphItem::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

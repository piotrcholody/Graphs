/****************************************************************************
** Meta object code from reading C++ file 'ggeneratork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ggeneratork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ggeneratork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GGeneratork_t {
    QByteArrayData data[7];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GGeneratork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GGeneratork_t qt_meta_stringdata_GGeneratork = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GGeneratork"
QT_MOC_LITERAL(1, 12, 10), // "returnFunc"
QT_MOC_LITERAL(2, 23, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(3, 42, 0), // ""
QT_MOC_LITERAL(4, 43, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(5, 65, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(6, 87, 6) // "update"

    },
    "GGeneratork\0returnFunc\0std::pair<int,int>\0"
    "\0on_buttonBox_accepted\0on_buttonBox_rejected\0"
    "update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GGeneratork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x08 /* Private */,
       4,    0,   35,    3, 0x08 /* Private */,
       5,    0,   36,    3, 0x08 /* Private */,
       6,    0,   37,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GGeneratork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GGeneratork *_t = static_cast<GGeneratork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { std::pair<int,int> _r = _t->returnFunc();
            if (_a[0]) *reinterpret_cast< std::pair<int,int>*>(_a[0]) = _r; }  break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_buttonBox_rejected(); break;
        case 3: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObject GGeneratork::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GGeneratork.data,
      qt_meta_data_GGeneratork,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GGeneratork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GGeneratork::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GGeneratork.stringdata0))
        return static_cast<void*>(const_cast< GGeneratork*>(this));
    return QDialog::qt_metacast(_clname);
}

int GGeneratork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ggenerator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ggenerator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ggenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GGenerator_t {
    QByteArrayData data[6];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GGenerator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GGenerator_t qt_meta_stringdata_GGenerator = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GGenerator"
QT_MOC_LITERAL(1, 11, 10), // "returnFunc"
QT_MOC_LITERAL(2, 22, 21), // "std::pair<int,double>"
QT_MOC_LITERAL(3, 44, 0), // ""
QT_MOC_LITERAL(4, 45, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(5, 67, 21) // "on_buttonBox_rejected"

    },
    "GGenerator\0returnFunc\0std::pair<int,double>\0"
    "\0on_buttonBox_accepted\0on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GGenerator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    3, 0x08 /* Private */,
       4,    0,   30,    3, 0x08 /* Private */,
       5,    0,   31,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GGenerator *_t = static_cast<GGenerator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { std::pair<int,double> _r = _t->returnFunc();
            if (_a[0]) *reinterpret_cast< std::pair<int,double>*>(_a[0]) = _r; }  break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    }
}

const QMetaObject GGenerator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GGenerator.data,
      qt_meta_data_GGenerator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GGenerator.stringdata0))
        return static_cast<void*>(const_cast< GGenerator*>(this));
    return QDialog::qt_metacast(_clname);
}

int GGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

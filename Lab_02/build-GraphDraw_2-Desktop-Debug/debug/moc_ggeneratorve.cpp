/****************************************************************************
** Meta object code from reading C++ file 'ggeneratorve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lab2/ggeneratorve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ggeneratorve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GGeneratorVE_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GGeneratorVE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GGeneratorVE_t qt_meta_stringdata_GGeneratorVE = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GGeneratorVE"
QT_MOC_LITERAL(1, 13, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(2, 35, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(3, 54, 0), // ""
QT_MOC_LITERAL(4, 55, 6) // "update"

    },
    "GGeneratorVE\0on_buttonBox_accepted\0"
    "std::pair<int,int>\0\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GGeneratorVE[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    3, 0x08 /* Private */,
       4,    0,   25,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,

       0        // eod
};

void GGeneratorVE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GGeneratorVE *_t = static_cast<GGeneratorVE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { std::pair<int,int> _r = _t->on_buttonBox_accepted();
            if (_a[0]) *reinterpret_cast< std::pair<int,int>*>(_a[0]) = _r; }  break;
        case 1: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObject GGeneratorVE::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GGeneratorVE.data,
      qt_meta_data_GGeneratorVE,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GGeneratorVE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GGeneratorVE::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GGeneratorVE.stringdata0))
        return static_cast<void*>(const_cast< GGeneratorVE*>(this));
    return QDialog::qt_metacast(_clname);
}

int GGeneratorVE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

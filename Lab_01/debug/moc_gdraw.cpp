/****************************************************************************
** Meta object code from reading C++ file 'gdraw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gdraw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gdraw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gdraw_t {
    QByteArrayData data[9];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gdraw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gdraw_t qt_meta_stringdata_Gdraw = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Gdraw"
QT_MOC_LITERAL(1, 6, 31), // "on_actionStartDrawing_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 29), // "on_actionImportFile_triggered"
QT_MOC_LITERAL(4, 69, 23), // "on_actionHelp_triggered"
QT_MOC_LITERAL(5, 93, 38), // "on_actionShowRepresentations_..."
QT_MOC_LITERAL(6, 132, 28), // "on_actionSaveGraph_triggered"
QT_MOC_LITERAL(7, 161, 27), // "on_actionGenerate_triggered"
QT_MOC_LITERAL(8, 189, 38) // "on_actionGenerate_Vert_Edges_..."

    },
    "Gdraw\0on_actionStartDrawing_triggered\0"
    "\0on_actionImportFile_triggered\0"
    "on_actionHelp_triggered\0"
    "on_actionShowRepresentations_triggered\0"
    "on_actionSaveGraph_triggered\0"
    "on_actionGenerate_triggered\0"
    "on_actionGenerate_Vert_Edges_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gdraw[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gdraw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gdraw *_t = static_cast<Gdraw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionStartDrawing_triggered(); break;
        case 1: _t->on_actionImportFile_triggered(); break;
        case 2: _t->on_actionHelp_triggered(); break;
        case 3: _t->on_actionShowRepresentations_triggered(); break;
        case 4: _t->on_actionSaveGraph_triggered(); break;
        case 5: _t->on_actionGenerate_triggered(); break;
        case 6: _t->on_actionGenerate_Vert_Edges_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Gdraw::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gdraw.data,
      qt_meta_data_Gdraw,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Gdraw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gdraw::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Gdraw.stringdata0))
        return static_cast<void*>(const_cast< Gdraw*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gdraw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'graphdraw2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphdraw2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphdraw2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphDraw2_t {
    QByteArrayData data[12];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphDraw2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphDraw2_t qt_meta_stringdata_GraphDraw2 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GraphDraw2"
QT_MOC_LITERAL(1, 11, 23), // "on_PBInsertData_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_PBEulerian_clicked"
QT_MOC_LITERAL(4, 58, 25), // "on_PBHamiltonianC_clicked"
QT_MOC_LITERAL(5, 84, 22), // "on_PBRandomize_clicked"
QT_MOC_LITERAL(6, 107, 17), // "on_PBDraw_clicked"
QT_MOC_LITERAL(7, 125, 27), // "on_PBConsistentSubG_clicked"
QT_MOC_LITERAL(8, 153, 37), // "on_actionGenerate_Vert_Edge_t..."
QT_MOC_LITERAL(9, 191, 44), // "on_actionFrom_vertices_probab..."
QT_MOC_LITERAL(10, 236, 36), // "on_actionFrom_k_regularity_tr..."
QT_MOC_LITERAL(11, 273, 18) // "on_PBEuler_clicked"

    },
    "GraphDraw2\0on_PBInsertData_clicked\0\0"
    "on_PBEulerian_clicked\0on_PBHamiltonianC_clicked\0"
    "on_PBRandomize_clicked\0on_PBDraw_clicked\0"
    "on_PBConsistentSubG_clicked\0"
    "on_actionGenerate_Vert_Edge_triggered\0"
    "on_actionFrom_vertices_probability_triggered\0"
    "on_actionFrom_k_regularity_triggered\0"
    "on_PBEuler_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphDraw2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphDraw2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphDraw2 *_t = static_cast<GraphDraw2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PBInsertData_clicked(); break;
        case 1: _t->on_PBEulerian_clicked(); break;
        case 2: _t->on_PBHamiltonianC_clicked(); break;
        case 3: _t->on_PBRandomize_clicked(); break;
        case 4: _t->on_PBDraw_clicked(); break;
        case 5: _t->on_PBConsistentSubG_clicked(); break;
        case 6: _t->on_actionGenerate_Vert_Edge_triggered(); break;
        case 7: _t->on_actionFrom_vertices_probability_triggered(); break;
        case 8: _t->on_actionFrom_k_regularity_triggered(); break;
        case 9: _t->on_PBEuler_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GraphDraw2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GraphDraw2.data,
      qt_meta_data_GraphDraw2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphDraw2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphDraw2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphDraw2.stringdata0))
        return static_cast<void*>(const_cast< GraphDraw2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GraphDraw2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

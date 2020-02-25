/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../header/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "eventFilter"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "watched"
QT_MOC_LITERAL(4, 32, 7), // "QEvent*"
QT_MOC_LITERAL(5, 40, 5), // "Event"
QT_MOC_LITERAL(6, 46, 20), // "MainListboxInsertion"
QT_MOC_LITERAL(7, 67, 19), // "MainListboxDeletion"
QT_MOC_LITERAL(8, 87, 18), // "chbOneStateHandler"
QT_MOC_LITERAL(9, 106, 20), // "chbMonthStateHandler"
QT_MOC_LITERAL(10, 127, 25), // "chbOneTakingsStateHandler"
QT_MOC_LITERAL(11, 153, 27), // "chbMonthTakingsStateHandler"
QT_MOC_LITERAL(12, 181, 24), // "on_actionEnglish_toggled"
QT_MOC_LITERAL(13, 206, 23) // "on_actionGerman_toggled"

    },
    "MainWindow\0eventFilter\0\0watched\0QEvent*\0"
    "Event\0MainListboxInsertion\0"
    "MainListboxDeletion\0chbOneStateHandler\0"
    "chbMonthStateHandler\0chbOneTakingsStateHandler\0"
    "chbMonthTakingsStateHandler\0"
    "on_actionEnglish_toggled\0"
    "on_actionGerman_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x09 /* Protected */,
       6,    0,   64,    2, 0x09 /* Protected */,
       7,    0,   65,    2, 0x09 /* Protected */,
       8,    0,   66,    2, 0x09 /* Protected */,
       9,    0,   67,    2, 0x09 /* Protected */,
      10,    0,   68,    2, 0x09 /* Protected */,
      11,    0,   69,    2, 0x09 /* Protected */,
      12,    1,   70,    2, 0x09 /* Protected */,
      13,    1,   73,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->MainListboxInsertion(); break;
        case 2: _t->MainListboxDeletion(); break;
        case 3: _t->chbOneStateHandler(); break;
        case 4: _t->chbMonthStateHandler(); break;
        case 5: _t->chbOneTakingsStateHandler(); break;
        case 6: _t->chbMonthTakingsStateHandler(); break;
        case 7: _t->on_actionEnglish_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_actionGerman_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

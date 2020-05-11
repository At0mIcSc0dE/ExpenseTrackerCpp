/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../header/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[309];
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
QT_MOC_LITERAL(6, 46, 10), // "closeEvent"
QT_MOC_LITERAL(7, 57, 12), // "QCloseEvent*"
QT_MOC_LITERAL(8, 70, 4), // "evnt"
QT_MOC_LITERAL(9, 75, 20), // "MainListboxInsertion"
QT_MOC_LITERAL(10, 96, 19), // "MainListboxDeletion"
QT_MOC_LITERAL(11, 116, 12), // "UpdateLabels"
QT_MOC_LITERAL(12, 129, 14), // "MonthEndEvents"
QT_MOC_LITERAL(13, 144, 18), // "chbOneStateHandler"
QT_MOC_LITERAL(14, 163, 20), // "chbMonthStateHandler"
QT_MOC_LITERAL(15, 184, 25), // "chbOneTakingsStateHandler"
QT_MOC_LITERAL(16, 210, 27), // "chbMonthTakingsStateHandler"
QT_MOC_LITERAL(17, 238, 21), // "MoreInfoButtonPressed"
QT_MOC_LITERAL(18, 260, 24), // "on_actionEnglish_toggled"
QT_MOC_LITERAL(19, 285, 23) // "on_actionGerman_toggled"

    },
    "MainWindow\0eventFilter\0\0watched\0QEvent*\0"
    "Event\0closeEvent\0QCloseEvent*\0evnt\0"
    "MainListboxInsertion\0MainListboxDeletion\0"
    "UpdateLabels\0MonthEndEvents\0"
    "chbOneStateHandler\0chbMonthStateHandler\0"
    "chbOneTakingsStateHandler\0"
    "chbMonthTakingsStateHandler\0"
    "MoreInfoButtonPressed\0on_actionEnglish_toggled\0"
    "on_actionGerman_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x09 /* Protected */,
       6,    1,   84,    2, 0x09 /* Protected */,
       9,    0,   87,    2, 0x09 /* Protected */,
      10,    0,   88,    2, 0x09 /* Protected */,
      11,    0,   89,    2, 0x09 /* Protected */,
      12,    0,   90,    2, 0x09 /* Protected */,
      13,    0,   91,    2, 0x09 /* Protected */,
      14,    0,   92,    2, 0x09 /* Protected */,
      15,    0,   93,    2, 0x09 /* Protected */,
      16,    0,   94,    2, 0x09 /* Protected */,
      17,    0,   95,    2, 0x09 /* Protected */,
      18,    1,   96,    2, 0x09 /* Protected */,
      19,    1,   99,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->MainListboxInsertion(); break;
        case 3: _t->MainListboxDeletion(); break;
        case 4: _t->UpdateLabels(); break;
        case 5: _t->MonthEndEvents(); break;
        case 6: _t->chbOneStateHandler(); break;
        case 7: _t->chbMonthStateHandler(); break;
        case 8: _t->chbOneTakingsStateHandler(); break;
        case 9: _t->chbMonthTakingsStateHandler(); break;
        case 10: _t->MoreInfoButtonPressed(); break;
        case 11: _t->on_actionEnglish_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_actionGerman_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

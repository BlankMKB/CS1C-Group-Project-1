/****************************************************************************
** Meta object code from reading C++ file 'storemanagerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS1C_BulkClub/storemanagerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storemanagerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StoreManagerWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_StoreManagerWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_StoreManagerWindow_t qt_meta_stringdata_StoreManagerWindow = {
    {
QT_MOC_LITERAL(0, 18), // "StoreManagerWindow"
QT_MOC_LITERAL(19, 24), // "on_logout_button_clicked"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 31), // "on_memberCB_currentIndexChanged"
QT_MOC_LITERAL(77, 5), // "index"
QT_MOC_LITERAL(83, 40), // "on_expirationMonthCB_currentI..."
QT_MOC_LITERAL(124, 29), // "on_dateCB_currentIndexChanged"
QT_MOC_LITERAL(154, 29), // "on_typeCB_currentIndexChanged"
QT_MOC_LITERAL(184, 29), // "on_memberSearchButton_clicked"
QT_MOC_LITERAL(214, 27) // "on_itemSearchButton_clicked"

    },
    "StoreManagerWindow\0on_logout_button_clicked\0"
    "\0on_memberCB_currentIndexChanged\0index\0"
    "on_expirationMonthCB_currentIndexChanged\0"
    "on_dateCB_currentIndexChanged\0"
    "on_typeCB_currentIndexChanged\0"
    "on_memberSearchButton_clicked\0"
    "on_itemSearchButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoreManagerWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    1,   57,    2, 0x08,    2 /* Private */,
       5,    1,   60,    2, 0x08,    4 /* Private */,
       6,    1,   63,    2, 0x08,    6 /* Private */,
       7,    1,   66,    2, 0x08,    8 /* Private */,
       8,    0,   69,    2, 0x08,   10 /* Private */,
       9,    0,   70,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StoreManagerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StoreManagerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_logout_button_clicked(); break;
        case 1: _t->on_memberCB_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_expirationMonthCB_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_dateCB_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_typeCB_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_memberSearchButton_clicked(); break;
        case 6: _t->on_itemSearchButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject StoreManagerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_StoreManagerWindow.offsetsAndSize,
    qt_meta_data_StoreManagerWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_StoreManagerWindow_t
, QtPrivate::TypeAndForceComplete<StoreManagerWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *StoreManagerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StoreManagerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StoreManagerWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StoreManagerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'WindowAddClassPeriod.h'
**
** Created: Mon Apr 2 20:24:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WindowAddClassPeriod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowAddClassPeriod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowAddClassPeriod[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      33,   21,   21,   21, 0x0a,
      47,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowAddClassPeriod[] = {
    "WindowAddClassPeriod\0\0addGroup()\0"
    "deleteGroup()\0addClassPeriod()\0"
};

const QMetaObject WindowAddClassPeriod::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WindowAddClassPeriod,
      qt_meta_data_WindowAddClassPeriod, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowAddClassPeriod::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowAddClassPeriod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowAddClassPeriod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowAddClassPeriod))
        return static_cast<void*>(const_cast< WindowAddClassPeriod*>(this));
    return QDialog::qt_metacast(_clname);
}

int WindowAddClassPeriod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addGroup(); break;
        case 1: deleteGroup(); break;
        case 2: addClassPeriod(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'WindowAdministrator.h'
**
** Created: Sun Apr 1 18:50:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WindowAdministrator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowAdministrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowAdministrator[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      33,   20,   20,   20, 0x0a,
      46,   20,   20,   20, 0x0a,
      61,   20,   20,   20, 0x0a,
      76,   20,   20,   20, 0x0a,
      95,   20,   20,   20, 0x0a,
     116,   20,   20,   20, 0x0a,
     133,   20,   20,   20, 0x0a,
     151,   20,   20,   20, 0x0a,
     171,   20,   20,   20, 0x0a,
     193,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowAdministrator[] = {
    "WindowAdministrator\0\0addModule()\0"
    "editModule()\0deleteModule()\0okEditModule()\0"
    "cancelEditModule()\0displayClassPeriod()\0"
    "addClassPeriod()\0editClassPeriod()\0"
    "deleteClassPeriod()\0addGroupClassPeriod()\0"
    "deleteGroupClassPeriod()\0"
};

const QMetaObject WindowAdministrator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WindowAdministrator,
      qt_meta_data_WindowAdministrator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowAdministrator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowAdministrator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowAdministrator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowAdministrator))
        return static_cast<void*>(const_cast< WindowAdministrator*>(this));
    return QDialog::qt_metacast(_clname);
}

int WindowAdministrator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addModule(); break;
        case 1: editModule(); break;
        case 2: deleteModule(); break;
        case 3: okEditModule(); break;
        case 4: cancelEditModule(); break;
        case 5: displayClassPeriod(); break;
        case 6: addClassPeriod(); break;
        case 7: editClassPeriod(); break;
        case 8: deleteClassPeriod(); break;
        case 9: addGroupClassPeriod(); break;
        case 10: deleteGroupClassPeriod(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

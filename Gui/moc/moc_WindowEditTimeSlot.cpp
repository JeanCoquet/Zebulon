/****************************************************************************
** Meta object code from reading C++ file 'WindowEditTimeSlot.h'
**
** Created: Mon Apr 2 20:24:13 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WindowEditTimeSlot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowEditTimeSlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowEditTimeSlot[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      38,   19,   19,   19, 0x0a,
      61,   19,   19,   19, 0x0a,
      80,   19,   19,   19, 0x0a,
     109,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowEditTimeSlot[] = {
    "WindowEditTimeSlot\0\0changeModule(int)\0"
    "changeClassPeriod(int)\0timeSlotAccepted()\0"
    "deleteTimeSlotButtonAction()\0"
    "openWindowAddClassPeriod()\0"
};

const QMetaObject WindowEditTimeSlot::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WindowEditTimeSlot,
      qt_meta_data_WindowEditTimeSlot, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowEditTimeSlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowEditTimeSlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowEditTimeSlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowEditTimeSlot))
        return static_cast<void*>(const_cast< WindowEditTimeSlot*>(this));
    return QDialog::qt_metacast(_clname);
}

int WindowEditTimeSlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeModule((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: changeClassPeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: timeSlotAccepted(); break;
        case 3: deleteTimeSlotButtonAction(); break;
        case 4: openWindowAddClassPeriod(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

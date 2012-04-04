/****************************************************************************
** Meta object code from reading C++ file 'WindowAdministrator.h'
**
** Created: Wed Apr 4 23:49:45 2012
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
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      40,   20,   20,   20, 0x0a,
      55,   20,   20,   20, 0x0a,
      71,   20,   20,   20, 0x0a,
      89,   20,   20,   20, 0x0a,
     107,   20,   20,   20, 0x0a,
     129,   20,   20,   20, 0x0a,
     160,   20,   20,   20, 0x0a,
     176,   20,   20,   20, 0x0a,
     188,   20,   20,   20, 0x0a,
     201,   20,   20,   20, 0x0a,
     216,   20,   20,   20, 0x0a,
     231,   20,   20,   20, 0x0a,
     250,   20,   20,   20, 0x0a,
     271,   20,   20,   20, 0x0a,
     288,   20,   20,   20, 0x0a,
     306,   20,   20,   20, 0x0a,
     326,   20,   20,   20, 0x0a,
     346,   20,   20,   20, 0x0a,
     370,   20,   20,   20, 0x0a,
     392,   20,   20,   20, 0x0a,
     423,  417,   20,   20, 0x0a,
     461,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowAdministrator[] = {
    "WindowAdministrator\0\0classroomClicked()\0"
    "addClassroom()\0editClassroom()\0"
    "deleteClassroom()\0okEditClassroom()\0"
    "cancelEditClassroom()\0"
    "comboBoxTypeClassroomChanged()\0"
    "moduleClicked()\0addModule()\0editModule()\0"
    "deleteModule()\0okEditModule()\0"
    "cancelEditModule()\0classperiodClicked()\0"
    "addClassPeriod()\0editClassPeriod()\0"
    "deleteClassPeriod()\0okEditClassPeriod()\0"
    "cancelEditClassPeriod()\0addGroupClassPeriod()\0"
    "deleteGroupClassPeriod()\0index\0"
    "comboBoxGroupsClassPeriodChanged(int)\0"
    "listGroupClassPeriodClicked()\0"
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
        case 0: classroomClicked(); break;
        case 1: addClassroom(); break;
        case 2: editClassroom(); break;
        case 3: deleteClassroom(); break;
        case 4: okEditClassroom(); break;
        case 5: cancelEditClassroom(); break;
        case 6: comboBoxTypeClassroomChanged(); break;
        case 7: moduleClicked(); break;
        case 8: addModule(); break;
        case 9: editModule(); break;
        case 10: deleteModule(); break;
        case 11: okEditModule(); break;
        case 12: cancelEditModule(); break;
        case 13: classperiodClicked(); break;
        case 14: addClassPeriod(); break;
        case 15: editClassPeriod(); break;
        case 16: deleteClassPeriod(); break;
        case 17: okEditClassPeriod(); break;
        case 18: cancelEditClassPeriod(); break;
        case 19: addGroupClassPeriod(); break;
        case 20: deleteGroupClassPeriod(); break;
        case 21: comboBoxGroupsClassPeriodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: listGroupClassPeriodClicked(); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

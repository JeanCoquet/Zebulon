/****************************************************************************
** Meta object code from reading C++ file 'WindowAdministrator.h'
**
** Created: Thu Apr 5 15:44:02 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WindowAdministrator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowAdministrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowAdministrator[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      36,   20,   20,   20, 0x0a,
      47,   20,   20,   20, 0x0a,
      59,   20,   20,   20, 0x0a,
      73,   20,   20,   20, 0x0a,
      87,   20,   20,   20, 0x0a,
     105,   20,   20,   20, 0x0a,
     121,   20,   20,   20, 0x0a,
     146,  140,   20,   20, 0x0a,
     178,   20,   20,   20, 0x0a,
     202,   20,   20,   20, 0x0a,
     219,   20,   20,   20, 0x0a,
     232,   20,   20,   20, 0x0a,
     246,   20,   20,   20, 0x0a,
     262,   20,   20,   20, 0x0a,
     278,   20,   20,   20, 0x0a,
     298,   20,   20,   20, 0x0a,
     317,   20,   20,   20, 0x0a,
     332,   20,   20,   20, 0x0a,
     348,   20,   20,   20, 0x0a,
     366,   20,   20,   20, 0x0a,
     384,   20,   20,   20, 0x0a,
     406,   20,   20,   20, 0x0a,
     437,   20,   20,   20, 0x0a,
     453,   20,   20,   20, 0x0a,
     465,   20,   20,   20, 0x0a,
     478,   20,   20,   20, 0x0a,
     493,   20,   20,   20, 0x0a,
     508,   20,   20,   20, 0x0a,
     527,   20,   20,   20, 0x0a,
     548,   20,   20,   20, 0x0a,
     565,   20,   20,   20, 0x0a,
     583,   20,   20,   20, 0x0a,
     603,   20,   20,   20, 0x0a,
     623,   20,   20,   20, 0x0a,
     647,   20,   20,   20, 0x0a,
     669,   20,   20,   20, 0x0a,
     694,  140,   20,   20, 0x0a,
     732,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowAdministrator[] = {
    "WindowAdministrator\0\0groupClicked()\0"
    "addGroup()\0editGroup()\0deleteGroup()\0"
    "okEditGroup()\0cancelEditGroup()\0"
    "addGroupGroup()\0deleteGroupGroup()\0"
    "index\0comboBoxGroupsGroupChanged(int)\0"
    "listGroupGroupClicked()\0studentClicked()\0"
    "addStudent()\0editStudent()\0deleteStudent()\0"
    "okEditStudent()\0cancelEditStudent()\0"
    "classroomClicked()\0addClassroom()\0"
    "editClassroom()\0deleteClassroom()\0"
    "okEditClassroom()\0cancelEditClassroom()\0"
    "comboBoxTypeClassroomChanged()\0"
    "moduleClicked()\0addModule()\0editModule()\0"
    "deleteModule()\0okEditModule()\0"
    "cancelEditModule()\0classperiodClicked()\0"
    "addClassPeriod()\0editClassPeriod()\0"
    "deleteClassPeriod()\0okEditClassPeriod()\0"
    "cancelEditClassPeriod()\0addGroupClassPeriod()\0"
    "deleteGroupClassPeriod()\0"
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
        case 0: groupClicked(); break;
        case 1: addGroup(); break;
        case 2: editGroup(); break;
        case 3: deleteGroup(); break;
        case 4: okEditGroup(); break;
        case 5: cancelEditGroup(); break;
        case 6: addGroupGroup(); break;
        case 7: deleteGroupGroup(); break;
        case 8: comboBoxGroupsGroupChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: listGroupGroupClicked(); break;
        case 10: studentClicked(); break;
        case 11: addStudent(); break;
        case 12: editStudent(); break;
        case 13: deleteStudent(); break;
        case 14: okEditStudent(); break;
        case 15: cancelEditStudent(); break;
        case 16: classroomClicked(); break;
        case 17: addClassroom(); break;
        case 18: editClassroom(); break;
        case 19: deleteClassroom(); break;
        case 20: okEditClassroom(); break;
        case 21: cancelEditClassroom(); break;
        case 22: comboBoxTypeClassroomChanged(); break;
        case 23: moduleClicked(); break;
        case 24: addModule(); break;
        case 25: editModule(); break;
        case 26: deleteModule(); break;
        case 27: okEditModule(); break;
        case 28: cancelEditModule(); break;
        case 29: classperiodClicked(); break;
        case 30: addClassPeriod(); break;
        case 31: editClassPeriod(); break;
        case 32: deleteClassPeriod(); break;
        case 33: okEditClassPeriod(); break;
        case 34: cancelEditClassPeriod(); break;
        case 35: addGroupClassPeriod(); break;
        case 36: deleteGroupClassPeriod(); break;
        case 37: comboBoxGroupsClassPeriodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: listGroupClassPeriodClicked(); break;
        default: ;
        }
        _id -= 39;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

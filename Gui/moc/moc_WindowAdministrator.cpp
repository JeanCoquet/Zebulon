/****************************************************************************
** Meta object code from reading C++ file 'WindowAdministrator.h'
**
** Created: Thu Apr 5 23:05:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WindowAdministrator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowAdministrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowAdministrator[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   21,   20, 0x0a,
      34,   20,   20,   20, 0x0a,
      49,   20,   20,   20, 0x0a,
      60,   20,   20,   20, 0x0a,
      72,   20,   20,   20, 0x0a,
      86,   20,   20,   20, 0x0a,
     100,   20,   20,   20, 0x0a,
     118,   20,   20,   20, 0x0a,
     134,   20,   20,   20, 0x0a,
     159,  153,   20,   20, 0x0a,
     191,   20,   20,   20, 0x0a,
     215,   20,   20,   20, 0x0a,
     232,   20,   20,   20, 0x0a,
     245,   20,   20,   20, 0x0a,
     259,   20,   20,   20, 0x0a,
     275,   20,   20,   20, 0x0a,
     291,   20,   20,   20, 0x0a,
     311,   20,   20,   20, 0x0a,
     330,   20,   20,   20, 0x0a,
     345,   20,   20,   20, 0x0a,
     361,   20,   20,   20, 0x0a,
     379,   20,   20,   20, 0x0a,
     397,   20,   20,   20, 0x0a,
     419,   20,   20,   20, 0x0a,
     450,   20,   20,   20, 0x0a,
     466,   20,   20,   20, 0x0a,
     478,   20,   20,   20, 0x0a,
     491,   20,   20,   20, 0x0a,
     506,   20,   20,   20, 0x0a,
     521,   20,   20,   20, 0x0a,
     540,   20,   20,   20, 0x0a,
     561,   20,   20,   20, 0x0a,
     578,   20,   20,   20, 0x0a,
     596,   20,   20,   20, 0x0a,
     616,   20,   20,   20, 0x0a,
     636,   20,   20,   20, 0x0a,
     660,   20,   20,   20, 0x0a,
     682,   20,   20,   20, 0x0a,
     707,  153,   20,   20, 0x0a,
     745,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowAdministrator[] = {
    "WindowAdministrator\0\0bool\0close()\0"
    "groupClicked()\0addGroup()\0editGroup()\0"
    "deleteGroup()\0okEditGroup()\0"
    "cancelEditGroup()\0addGroupGroup()\0"
    "deleteGroupGroup()\0index\0"
    "comboBoxGroupsGroupChanged(int)\0"
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
        case 0: { bool _r = close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: groupClicked(); break;
        case 2: addGroup(); break;
        case 3: editGroup(); break;
        case 4: deleteGroup(); break;
        case 5: okEditGroup(); break;
        case 6: cancelEditGroup(); break;
        case 7: addGroupGroup(); break;
        case 8: deleteGroupGroup(); break;
        case 9: comboBoxGroupsGroupChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: listGroupGroupClicked(); break;
        case 11: studentClicked(); break;
        case 12: addStudent(); break;
        case 13: editStudent(); break;
        case 14: deleteStudent(); break;
        case 15: okEditStudent(); break;
        case 16: cancelEditStudent(); break;
        case 17: classroomClicked(); break;
        case 18: addClassroom(); break;
        case 19: editClassroom(); break;
        case 20: deleteClassroom(); break;
        case 21: okEditClassroom(); break;
        case 22: cancelEditClassroom(); break;
        case 23: comboBoxTypeClassroomChanged(); break;
        case 24: moduleClicked(); break;
        case 25: addModule(); break;
        case 26: editModule(); break;
        case 27: deleteModule(); break;
        case 28: okEditModule(); break;
        case 29: cancelEditModule(); break;
        case 30: classperiodClicked(); break;
        case 31: addClassPeriod(); break;
        case 32: editClassPeriod(); break;
        case 33: deleteClassPeriod(); break;
        case 34: okEditClassPeriod(); break;
        case 35: cancelEditClassPeriod(); break;
        case 36: addGroupClassPeriod(); break;
        case 37: deleteGroupClassPeriod(); break;
        case 38: comboBoxGroupsClassPeriodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: listGroupClassPeriodClicked(); break;
        default: ;
        }
        _id -= 40;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/* 
 * File:   Controller.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 8:34 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "../Model/Student.h"
#include "../Gui/ZebulonWindow.h"
#include "../Controller/Database.h"


#include <QtGui/QApplication>
#include <string>
#include <algorithm>

using namespace std;

class ZebulonWindow;
//class WindowAddClassPeriod;
//class WindowAddClassroom;
//class WindowAdministrator;
//class WindowEditTimeSlot;

class Controller : public QObject {
Q_OBJECT     
public:
    Controller() throw(int);    
    ~Controller();
    
    
    int strToInt(string);
    Date* strToDate(string);
    bool strToBool(string);
    string intToStr(int);
    int boolToInt(bool b);

    void loadSchedule();
    
    void addStudent(Student *stud, Group *group);
    void delStudent(Student *stud, Group *group);
    void addModule(Module *mod);
    void delModule(Module *mod);
    void addGroup(Group *group);
    void delGroup(Group *group);
    bool addTimeSlot(TimeSlot* timeSlot);
    void delTimeSlot(TimeSlot* timeSlot);
    void addClassPeriod(ClassPeriod* classPeriod, Module *mod);
    void delClassPeriod(ClassPeriod* classPeriod, Module *mod);
    void delClassroom(Classroom* cr);
    void addClassroom(Classroom* cr);
    void setClassroom(Classroom* cr, string id, int capacity, int specificity);
    void joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod);
    void setModule(Module* mod, string id, string name, string theHead);
    void setClassPeriod(Module *mod, ClassPeriod* cp, string type,  string teacher, int duration, list<Group*> *lg);
    void setGroup(Group *g, string id,  list<Group*> *lg);
    void setStudent(Student *s, Group* group, string id, string lastname, string firstname, string addr, string email);
  
    void connectMainWindow();
    void connectWindowAdministrator();
    void connectWindowEditTimeSlot();
    
private slots :
    void removeTimeSlot(QTimeSlot*);
    void changeDate(QDate date);
    void openEditTimeSlot();
    void openEditTimeSlot(QTimeSlot* timeSlot);
    void openAdministrator();
    void tabIndexChanged();
    void addQTimeSlot(QTimeSlot* t);
    void commit();
    
    void admin_close();
    // Onglet Group
    void admin_groupClicked();
    void admin_addGroup();
    void admin_editGroup();
    void admin_deleteGroup();
    void admin_okEditGroup();
    void admin_cancelEditGroup();
    void admin_addGroupGroup();
    void admin_deleteGroupGroup();
    void admin_comboBoxGroupsGroupChanged(int index);
    void admin_listGroupGroupClicked();
    
    void admin_studentClicked();
    void admin_addStudent();
    void admin_editStudent();
    void admin_deleteStudent();
    void admin_okEditStudent();
    void admin_cancelEditStudent();    
    
    // Onglet Classroom
    void admin_classroomClicked();
    void admin_addClassroom();
    void admin_editClassroom();
    void admin_deleteClassroom();
    void admin_okEditClassroom();
    void admin_cancelEditClassroom();
    void admin_comboBoxTypeClassroomChanged();
    
    // Onglet Module
    void admin_moduleClicked();
    void admin_addModule();
    void admin_editModule();
    void admin_deleteModule();
    void admin_okEditModule();
    void admin_cancelEditModule();
    
    void admin_classperiodClicked();
    void admin_addClassPeriod();
    void admin_editClassPeriod();
    void admin_deleteClassPeriod();
    void admin_okEditClassPeriod();
    void admin_cancelEditClassPeriod();
    void admin_addGroupClassPeriod();
    void admin_deleteGroupClassPeriod();
    void admin_comboBoxGroupsClassPeriodChanged(int index);
    void admin_listGroupClassPeriodClicked();
    
    void editTimeSlot_changeModule(int);
    void editTimeSlot_changeClassPeriod(int);
    void editTimeSlot_timeSlotAccepted();
    void editTimeSlot_deleteTimeSlotButtonAction();
    
private:
    Schedule schedule;
    Database database;
    ZebulonWindow *window;
};

#endif	/* CONTROLLER_H */


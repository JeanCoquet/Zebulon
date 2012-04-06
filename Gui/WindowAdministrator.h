/* 
 * File:   WindowAdministrator.h
 * Author: E110091P
 *
 * Created on 29 mars 2012, 12:32
 */

#ifndef _WINDOWADMINISTRATOR_H
#define	_WINDOWADMINISTRATOR_H
#include "ui_WindowAdministrator.h"
#include "../Model/Schedule.h"


class WindowAdministrator : public QDialog {
    Q_OBJECT
public:
    WindowAdministrator(Schedule *schedule);
    virtual ~WindowAdministrator();
    ClassPeriod* getCurrentClassPeriod() { return currentClassPeriod; }
    Classroom* getCurrentClassroom() { return currentClassroom; }
    Group* getCurrentGroup() { return currentGroup; }
    Module* getCurrentModule() { return currentModule; }
    Student* getCurrentStudent() { return currentStudent; }    
    Ui::WindowAdministrator *getWidget() { return &widget; }
    bool isGroupGroupModified() { return groupGroupModified; }
    void setGroupGroupModified(bool groupGroupModified) { this->groupGroupModified = groupGroupModified; }
    QStringList* getTempGroupListClassPeriod() { return &tempGroupListClassPeriod; }
    QStringList* getTempGroupListGroup() { return &tempGroupListGroup; }
    void setCurrentClassPeriod(ClassPeriod* currentClassPeriod) { this->currentClassPeriod = currentClassPeriod; }
    void setCurrentClassroom(Classroom* currentClassroom) { this->currentClassroom = currentClassroom; }
    void setCurrentGroup(Group* currentGroup) { this->currentGroup = currentGroup; }
    void setCurrentModule(Module* currentModule) { this->currentModule = currentModule; }
    void setCurrentStudent(Student* currentStudent) { this->currentStudent = currentStudent; }
    string getOldIdSelectedModule() { return oldIdSelectedModule; }
    void setOldIdSelectedModule(string oldIdSelectedModule) { this->oldIdSelectedModule = oldIdSelectedModule; }
    bool isGroupClassPeriodModified() { return groupClassPeriodModified; }
    void setGroupClassPeriodModified(bool groupClassPeriodModified) { this->groupClassPeriodModified = groupClassPeriodModified; }


    
    // Onglet Group
    void groupClicked();
    void addGroup();
    void editGroup();
    void deleteGroup();
    void okEditGroup();
    void cancelEditGroup();
    void addGroupGroup();
    void deleteGroupGroup();
    void comboBoxGroupsGroupChanged(int index);
    void listGroupGroupClicked();
    
    void studentClicked();
    void addStudent();
    void editStudent();
    void deleteStudent();
    void okEditStudent();
    void cancelEditStudent();    
    
    // Onglet Classroom
    void classroomClicked();
    void addClassroom();
    void editClassroom();
    void deleteClassroom();
    void okEditClassroom();
    void cancelEditClassroom();
    void comboBoxTypeClassroomChanged();
    
    // Onglet Module
    void moduleClicked();
    void addModule();
    void editModule();
    void deleteModule();
    void okEditModule();
    void cancelEditModule();
    
    void classperiodClicked();
    void addClassPeriod();
    void editClassPeriod();
    void deleteClassPeriod();
    void okEditClassPeriod();
    void cancelEditClassPeriod();
    void addGroupClassPeriod();
    void deleteGroupClassPeriod();
    void comboBoxGroupsClassPeriodChanged(int index);
    void listGroupClassPeriodClicked();
    
    
private:
    Ui::WindowAdministrator widget;
    Schedule *schedule;
    bool load; 
    bool edited;
    
    // Onglet Group
    Group* currentGroup;
    Student* currentStudent;
    int groupState; /* voir doc */ 
    bool groupGroupModified;
    QStringList tempGroupListGroup;    
    void displayGroups();
    void displayStudents();
    void refreshGroup(int newState);
    void loadGroupsGroup();
    void setCurrentGroup();
    void setCurrentStudent();
    
    // Onglet Classroom
    Classroom *currentClassroom;
    int classroomState; /* voir doc */
    void refreshClassroom(int newState);
    void displayClassroom();
    void displaySpecificityClassroom();
    void setCurrentClassroom();
    
    // Onglet Module
    Module* currentModule;
    ClassPeriod* currentClassPeriod;
    int moduleState; /* voir doc */
    string oldIdSelectedModule;
    bool groupClassPeriodModified;
    QStringList tempGroupListClassPeriod;
    void refreshModule(int newState);
    void displayModule();
    void displayClassPeriod();
    void loadGroupsClassPeriod();
    void setCurrentModule();
    void setCurrentClassPeriod();
};

#endif	/* _WINDOWADMINISTRATOR_H */


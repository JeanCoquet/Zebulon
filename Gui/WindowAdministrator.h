/* 
 * File:   WindowAdministrator.h
 * Author: E110091P
 *
 * Created on 29 mars 2012, 12:32
 */

#ifndef _WINDOWADMINISTRATOR_H
#define	_WINDOWADMINISTRATOR_H
#include "Model/Controller.h"
#include "mainwindow.h"
#include "ui_WindowAdministrator.h"
#include "Model/TutorialClassroom.h"
#include "Model/PracticalClassroom.h"
#include "Model/LectureHall.h"

class MainWindow;

class WindowAdministrator : public QDialog {
    Q_OBJECT
public:
    WindowAdministrator(Controller*, MainWindow*);
    virtual ~WindowAdministrator();
    
    Ui::WindowAdministrator getWidget() const {
        return widget;
    }

public slots :
    
    // Onglet Group
    
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
    Controller* ctrl;
    MainWindow* m;
    bool load; 
    
    // Onglet Group
    void displayStudents();
    
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


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
    void addModule();
    void editModule();
    void deleteModule();
    void okEditModule();
    void cancelEditModule();
    void displayClassPeriod();
    void addClassPeriod();
    void editClassPeriod();
    void deleteClassPeriod();
    void okEditClassPeriod();
    void cancelEditClassPeriod();
    void addGroupClassPeriod();
    void deleteGroupClassPeriod();
    void displayStudents();
    void moduleClicked();
    void classperiodClicked();
    void displayModule();
    void comboBoxGroupsClassPeriodChanged(int index);
    void listGroupClassPeriodClicked();
    
    
private:
    bool load;
    bool groupClassPeriodModified;
    int moduleState; /* voir doc */
    int classroomState;
    Classroom *currentClassroom;
    void refreshModule(int newState);
    void refreshClassroom(int newState);
    string oldIdSelectedModule; 
    Ui::WindowAdministrator widget;
    Controller* ctrl;
    MainWindow* m;
    Module* currentModule;
    ClassPeriod* currentClassPeriod;
    void displayClassroom();
    void setCurrentModule();
    void setCurrentClassroom();
    void setCurrentClassPeriod();
    void displaySpecificityClassroom();
    void loadGroupsClassPeriod();
    QStringList tempGroupListClassPeriod;
};

#endif	/* _WINDOWADMINISTRATOR_H */


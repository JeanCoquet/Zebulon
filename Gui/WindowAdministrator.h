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
    void addGroupClassPeriod();
    void deleteGroupClassPeriod();
    
private:
    Ui::WindowAdministrator widget;
    Controller* ctrl;
    MainWindow* m;
    Module* currentModule;
    ClassPeriod* currentClassPeriod;
};

#endif	/* _WINDOWADMINISTRATOR_H */


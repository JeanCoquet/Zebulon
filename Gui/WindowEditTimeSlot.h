/* 
 * File:   WindowEditTimeSlot.h
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#ifndef _WINDOWEDITTIMESLOT_H
#define	_WINDOWEDITTIMESLOT_H
#include "Model/Controller.h"
#include "mainwindow.h"
#include "ui_WindowEditTimeSlot.h"
#include <sstream>
#include <iostream>

class MainWindow;

class WindowEditTimeSlot : public QDialog {
    Q_OBJECT
public:
    WindowEditTimeSlot(Controller*, MainWindow*);
    virtual ~WindowEditTimeSlot();
    void clearWidgetContent();
    Ui::WindowEditTimeSlot getWidget() const {
        return widget;
    }
    
public slots :
    void changeModule(int);
    void changeClassPeriod(int);
    void timeSlotAccepted();
        
private:
    Ui::WindowEditTimeSlot widget;
    Controller* ctrl;
    MainWindow* m;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


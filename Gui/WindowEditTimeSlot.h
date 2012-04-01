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
#include "WindowAddClassPeriod.h"
#include "ui_WindowEditTimeSlot.h"
#include <sstream>
#include <iostream>

class MainWindow;
class WindowAddClassPeriod;

class WindowEditTimeSlot : public QDialog {
    Q_OBJECT
public:
    WindowEditTimeSlot(Controller*, MainWindow*);
    virtual ~WindowEditTimeSlot();
    void clearWidgetContent();
    Ui::WindowEditTimeSlot getWidget() const {
        return widget;
    }
    
    void setCurrentTimeSlot(QTimeSlot* currentTimeSlot) {
        this->currentTimeSlot = currentTimeSlot;
    }
    
    WindowAddClassPeriod* getWindowAddClassPeriod() const {
        return windowAddClassPeriod;
    }

public slots :
    void changeModule(int);
    void changeClassPeriod(int);
    void timeSlotAccepted();
    void deleteTimeSlotButtonAction();
    void openWindowAddClassPeriod();
        
private:
    Ui::WindowEditTimeSlot widget;
    Controller* ctrl;
    MainWindow* m;
    QTimeSlot *currentTimeSlot;
    WindowAddClassPeriod *windowAddClassPeriod;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


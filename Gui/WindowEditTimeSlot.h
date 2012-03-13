/* 
 * File:   WindowEditTimeSlot.h
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#ifndef _WINDOWEDITTIMESLOT_H
#define	_WINDOWEDITTIMESLOT_H
#include "Controller.h"
#include "ui_WindowEditTimeSlot.h"
#include <sstream>
#include <iostream>

class WindowEditTimeSlot : public QDialog {
    Q_OBJECT
public:
    WindowEditTimeSlot(Controller*);
    virtual ~WindowEditTimeSlot();
    Ui::WindowEditTimeSlot getWidget() const {
        return widget;
    }
public slots :
    void changeModule(int);
    void timeSlotAccepted();
        
private:
    Ui::WindowEditTimeSlot widget;
    Controller* ctrl;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


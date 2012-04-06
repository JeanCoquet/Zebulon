/* 
 * File:   WindowEditTimeSlot.h
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#ifndef _WINDOWEDITTIMESLOT_H
#define	_WINDOWEDITTIMESLOT_H
#include "../Model/Schedule.h"
#include "ui_WindowEditTimeSlot.h"
#include "QTimeSlot.h"
#include <sstream>
#include <iostream>

class WindowEditTimeSlot : public QDialog {
    Q_OBJECT
public:
    WindowEditTimeSlot(Schedule*);
    virtual ~WindowEditTimeSlot();
    void clearWidgetContent();
    Ui::WindowEditTimeSlot* getWidget() {
        return &widget;
    }
    
    void setCurrentTimeSlot(QTimeSlot* currentTimeSlot) {
        this->currentTimeSlot = currentTimeSlot;
    }
    
    QTimeSlot* getCurrentTimeSlot() {
        return currentTimeSlot;
    }

    
    void changeModule(int);
    void changeClassPeriod(int);
    void deleteTimeSlotButtonAction();

private:
    Ui::WindowEditTimeSlot widget;
    Schedule *schedule;
    QTimeSlot *currentTimeSlot;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


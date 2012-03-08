/* 
 * File:   WindowEditTimeSlot.h
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#ifndef _WINDOWEDITTIMESLOT_H
#define	_WINDOWEDITTIMESLOT_H

#include "ui_WindowEditTimeSlot.h"

class WindowEditTimeSlot : public QDialog {
    Q_OBJECT
public:
    WindowEditTimeSlot();
    virtual ~WindowEditTimeSlot();
    Ui::WindowEditTimeSlot getWidget() const {
        return widget;
    }

private:
    Ui::WindowEditTimeSlot widget;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


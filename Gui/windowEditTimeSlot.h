/* 
 * File:   windowEditTimeSlot.h
 * Author: E082474W
 *
 * Created on 6 mars 2012, 17:22
 */

#ifndef _WINDOWEDITTIMESLOT_H
#define	_WINDOWEDITTIMESLOT_H

#include "ui_windowEditTimeSlot.h"

class windowEditTimeSlot : public QWidget {
    Q_OBJECT
public:
    windowEditTimeSlot();
    virtual ~windowEditTimeSlot();
private:
    Ui::windowEditTimeSlot widget;
};

#endif	/* _WINDOWEDITTIMESLOT_H */


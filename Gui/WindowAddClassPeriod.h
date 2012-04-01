/* 
 * File:   WindowAddClassPeriod.h
 * Author: jean
 *
 * Created on 1 avril 2012, 02:26
 */

#ifndef _WINDOWADDCLASSPERIOD_H
#define	_WINDOWADDCLASSPERIOD_H

#include "ui_WindowAddClassPeriod.h"
#include "Model/Controller.h"
#include "WindowEditTimeSlot.h"

class WindowEditTimeSlot;

class WindowAddClassPeriod : public QDialog {
    Q_OBJECT
public:
    WindowAddClassPeriod(Controller*, WindowEditTimeSlot*);
    virtual ~WindowAddClassPeriod();
    
    Ui::WindowAddClassPeriod getWidget() const {
        return widget;
    }
    
    void setIndexModule(int index);
    void clearChildrenContent();
    
public slots :
    void addGroup();
    void deleteGroup();
    void addClassPeriod();
    
private:
    Ui::WindowAddClassPeriod widget;
    Controller* ctrl;
    WindowEditTimeSlot* windowE;
    Module *module;
    QList<int>* listIndexGroup;
};

#endif	/* _WINDOWADDCLASSPERIOD_H */

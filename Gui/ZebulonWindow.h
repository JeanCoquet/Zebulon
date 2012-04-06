/* 
 * File:   ZebulonWindow.h
 * Author: bicodul
 *
 * Created on April 6, 2012, 4:06 AM
 */

#ifndef _ZEBULONWINDOW_H
#define	_ZEBULONWINDOW_H

#include "ui_ZebulonWindow.h"
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include "QSchedule.h"
#include "../Model/Schedule.h"

#include "WindowEditTimeSlot.h"
#include "WindowAdministrator.h"
#include <list>
using namespace std;

class ZebulonWindow : public QMainWindow {
    Q_OBJECT
public:
    ZebulonWindow(Schedule *schedule);
    virtual ~ZebulonWindow() {};
    
    void reloadClassrooms();
    void reloadGroups();
    void reloadModules();
    void reloadStudents();
    void reloadAll();
    
    Ui::ZebulonWindow* getWidget() {
        return &widget;
    };

    
    WindowAdministrator* getWindowAdministrator() { return &windowAdministrator; }
    WindowEditTimeSlot* getWindowEditTimeSlot() { return &windowEditTimeSlot; }

    
    void reloadQTimeSlots();
    void addTimeSlot(QTimeSlot *t);

    
    void removeTimeSlot(QTimeSlot*);
    void changeDate(QDate date);
    void openEditTimeSlot();
    void openEditTimeSlot(QTimeSlot* timeSlot);
    void openAdministrator();
    void commit();
    
    
signals :
        void signal_addTimeSlot(QTimeSlot *);

private:
    
    void genererQTimeSlot(TimeSlot* t);
    bool findStudentInGroup(Group* g, string name);
    
    Ui::ZebulonWindow widget;
    WindowEditTimeSlot windowEditTimeSlot;
    WindowAdministrator windowAdministrator;
    Schedule *schedule;   

};

#endif	/* _ZEBULONWINDOW_H */

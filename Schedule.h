/* 
 * File:   Schedule.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:41 PM
 */

#ifndef SCHEDULE_H
#define	SCHEDULE_H
#include <list>
#include "TimeSlot.h"
#include "Module.h"

using namespace std;

class Schedule {
public:
    Schedule();
    Schedule(const Schedule& orig);
    virtual ~Schedule();
private:
    list<Classroom> classroomList;
    list<Group> groupList;
    list<Module> moduleList;
    list<TimeSlot> timeSlotList;    
};

#endif	/* SCHEDULE_H */


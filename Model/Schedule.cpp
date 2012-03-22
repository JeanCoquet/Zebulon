/* 
 * File:   Schedule.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:41 PM
 */

#include "Schedule.h"

Schedule::Schedule() {
    classroomList = new  list<Classroom*>;
    groupList = new list<Group*>;
    moduleList = new list<Module*>;
    timeSlotList = new list<TimeSlot*>;
}

Schedule::~Schedule() {
    delete[] classroomList;
    delete[] groupList;
    delete[] moduleList;
    delete[] timeSlotList;
}


/* 
 * File:   TimeSlot.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:33
 */

#include "TimeSlot.h"

TimeSlot::TimeSlot(int id, Date *startDate, Classroom* classroom, ClassPeriod* classPeriod) {
    this->id = id;
    this->startDate = startDate;
    this->classroom = classroom;
    this->classPeriod = classPeriod;
}



TimeSlot::TimeSlot(const TimeSlot& orig) {
}

TimeSlot::~TimeSlot() {
}


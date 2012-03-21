/* 
 * File:   TimeSlot.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:33
 */

#include "TimeSlot.h"

int TimeSlot::maxId = 0;

TimeSlot::TimeSlot(Date *startDate, Classroom* classroom, ClassPeriod* classPeriod) {
    
    this->startDate = startDate;
    this->classroom = classroom;
    this->classPeriod = classPeriod;
    this->maxId++;
    this->id = this->maxId;
}



TimeSlot::TimeSlot(const TimeSlot& orig) {
}

TimeSlot::~TimeSlot() {
}


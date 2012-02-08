/* 
 * File:   TimeSlot.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:33
 */

#ifndef TIMESLOT_H
#define	TIMESLOT_H
#include "Date.h"
#include "Classroom.h"
#include "ClassPeriod.h"
class TimeSlot {
public:
    TimeSlot();
    TimeSlot(const TimeSlot& orig);
    virtual ~TimeSlot();
private:
    Date startDate;
    Classroom classroom;
    ClassPeriod classPeriod;
};

#endif	/* TIMESLOT_H */


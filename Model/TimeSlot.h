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
    TimeSlot(Date *startDate, Classroom *classroom, ClassPeriod* classPeriod);
    TimeSlot(const TimeSlot& orig);
    virtual ~TimeSlot();
    void updateEndDate();
    static int maxId;
    
    ClassPeriod* GetClassPeriod() const {
        return classPeriod;
    }

    Classroom* GetClassroom() const {
        return classroom;
    }

    int GetId() const {
        return id;
    }

    Date* GetStartDate() const {
        return startDate;
    }
    
    Date* GetEndDate() const {
        return endDate;
    }



private:
    int id;
    Date *startDate;
    Date *endDate;
    Classroom *classroom;
    ClassPeriod *classPeriod;
};

#endif	/* TIMESLOT_H */


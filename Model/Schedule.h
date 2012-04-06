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
#include "TutorialClassroom.h"
#include "PracticalClassroom.h"
#include "LectureHall.h"
#include "../Model/TutorialClass.h"
#include "../Model/PracticalClass.h"
#include "../Model/MagistralClass.h"
using namespace std;

class Schedule {
public:
    Schedule();
    Schedule(const Schedule& orig);
    virtual ~Schedule();

    list<Classroom*>* GetClassroomList() const {
        return classroomList;
    }

    void SetClassroomList(list<Classroom*>* classroomList) {
        this->classroomList = classroomList;
    }

    list<Group*>* GetGroupList() const {
        return groupList;
    }

    void SetGroupList(list<Group*>* groupList) {
        this->groupList = groupList;
    }

    list<Module*>* GetModuleList() const {
        return moduleList;
    }

    void SetModuleList(list<Module*>* moduleList) {
        this->moduleList = moduleList;
    }

    list<TimeSlot*>* GetTimeSlotList() const {
        return timeSlotList;
    }

    void SetTimeSlotList(list<TimeSlot*>* timeSlotList) {
        this->timeSlotList = timeSlotList;
    }


private:
    list<Classroom*> *classroomList;
    list<Group*> *groupList;
    list<Module*> *moduleList;
    list<TimeSlot*> *timeSlotList;    
};

#endif	/* SCHEDULE_H */


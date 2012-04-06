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
    this->endDate = NULL;
    updateEndDate();
}


void TimeSlot::updateEndDate(){
    if(this->endDate != NULL)
        delete this->endDate;
    this->endDate = new Date(*(this->startDate));
    int nbMin = this->endDate->GetMin() + this->classPeriod->GetDuration();
    if(nbMin >= 60) {
        this->endDate->SetMin(nbMin%60);
        this->endDate->SetHour(this->endDate->GetHour()+(nbMin/60));
        if(this->endDate->GetHour() > 20) //L'heure maximum est fixee a 20h on ne change pas de jour
            this->endDate->SetHour(20);
    }
    else
        this->endDate->SetMin(nbMin);
}

TimeSlot::~TimeSlot() {
    if(endDate != NULL)
        delete endDate;
}


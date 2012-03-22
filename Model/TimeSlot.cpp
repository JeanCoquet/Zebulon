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

Date TimeSlot::GetEndDate() const{
    cout<<"addition date: "<<*(this->GetStartDate())<<" + "<<this->GetClassPeriod()->GetDuration()<<endl;
    Date date2 = Date(*(this->startDate));
    int nbMin = date2.GetMin() + this->classPeriod->GetDuration();
    if(nbMin >= 60) {
        date2.SetMin(nbMin%60);
        date2.SetHour(date2.GetHour()+(nbMin/60));
        if(date2.GetHour() > 20)
            date2.SetHour(20);
    }
    else
        date2.SetMin(nbMin);
    cout<<"date end : "<<date2<<endl;
    return date2;
}


TimeSlot::TimeSlot(const TimeSlot& orig) {
}

TimeSlot::~TimeSlot() {
}


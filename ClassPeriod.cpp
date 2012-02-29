/* 
 * File:   ClassPeriod.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:30
 */

#include "ClassPeriod.h"

ClassPeriod::ClassPeriod(int id, string teacher, int duration) {
    this->duration = duration;
    this->id = id;
    this->teacher = teacher;
    this->groupList = new list<Group*>();
}

ClassPeriod::ClassPeriod(const ClassPeriod& orig) {
}

ClassPeriod::~ClassPeriod() {
    delete[] this->groupList;
}


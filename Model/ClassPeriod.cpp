/* 
 * File:   ClassPeriod.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:30
 */

#include "ClassPeriod.h"

int ClassPeriod::maxId = 0;

ClassPeriod::ClassPeriod(string teacher, int duration, Module* mod): momo(mod) {
    this->duration = duration;
    this->maxId++;
    this->id = this->maxId;
    this->teacher = teacher;
    this->groupList = new list<Group*>();
}

ClassPeriod::ClassPeriod(const ClassPeriod& orig) {
}

ClassPeriod::~ClassPeriod() {
    delete[] this->groupList;
}


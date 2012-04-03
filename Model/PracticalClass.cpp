/* 
 * File:   PracticalClass.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:31
 */

#include "PracticalClass.h"

PracticalClass::PracticalClass(string teacher, int duration, Module* mod):ClassPeriod(teacher,duration, mod)  {
}

PracticalClass::PracticalClass(const ClassPeriod* orig) : ClassPeriod(orig) {}

PracticalClass::~PracticalClass() {
}


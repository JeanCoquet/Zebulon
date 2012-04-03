/* 
 * File:   TutorialClass.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:31
 */

#include "TutorialClass.h"

TutorialClass::TutorialClass(string teacher, int duration, Module* mod):ClassPeriod(teacher,duration, mod)  {
}

TutorialClass::TutorialClass(const ClassPeriod* orig) : ClassPeriod(orig) {}

TutorialClass::~TutorialClass() {
}


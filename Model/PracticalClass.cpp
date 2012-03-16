/* 
 * File:   PracticalClass.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:31
 */

#include "PracticalClass.h"

PracticalClass::PracticalClass(int id, string teacher, int duration) : ClassPeriod(id, teacher, duration) {
}

PracticalClass::PracticalClass(const PracticalClass& orig)  : ClassPeriod(orig.GetId(), orig.GetTeacher(), orig.GetDuration()){
}

PracticalClass::~PracticalClass() {
}


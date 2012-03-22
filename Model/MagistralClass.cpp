/* 
 * File:   MagistralClass.cpp
 * Author: E110091P
 * 
 * Created on 7 février 2012, 15:31
 */

#include "MagistralClass.h"

MagistralClass::MagistralClass(int id, string teacher, int duration, Module* mod):ClassPeriod(id,teacher,duration, mod) {
}

MagistralClass::~MagistralClass() {
}


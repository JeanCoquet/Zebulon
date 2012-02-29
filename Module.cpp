/* 
 * File:   Module.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:29 PM
 */

#include "Module.h"

Module::Module(string id, string name, string theHead) {
    this->id = id;
    this->name = name;
    this->theHead = theHead;
    this->classPeriodList = new list<ClassPeriod>();
}

Module::Module(const Module& orig) {
}

Module::~Module() {
    delete[] classPeriodList;
}


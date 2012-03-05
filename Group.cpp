/* 
 * File:   Group.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:25 PM
 */

#include "Group.h"

Group::Group(string id, Group *daddy) {
    this->id = id;
    this->StudentList = new list<Student*>();
    this->daddy = daddy; 
}

Group::Group(const Group& orig) {
}

Group::~Group() {
    delete[] this->StudentList;
}


/* 
 * File:   Group.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:25 PM
 */

#include "Group.h"

Group::Group(string id) {
    this->id = id;
    this->StudentList = new list<Student*>();
}

Group::Group(const Group& orig) {
}

Group::~Group() {
    delete[] this->StudentList;
}


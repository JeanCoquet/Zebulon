/* 
 * File:   Group.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:25 PM
 */

#include "Group.h"

Group::Group(string id, list<Group*>* groupList) {
    this->id = id;
    this->StudentList = new list<Student*>();
    this->groupList = groupList;
}

Group::Group(const Group* orig) {
    this->id = orig->id;
    this->groupList = NULL;
    this->StudentList = new list<Student*>();
}


Group::~Group() {
    
}


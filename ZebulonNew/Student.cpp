/* 
 * File:   Student.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:22 PM
 */

#include "Student.h"

Student::Student(string id, string lastname, string firstname, string addr, string email) {
    this->addr = addr;
    this->id = id;
    this->lastname = lastname;
    this->email = email;
    this->firstname = firstname;
}

Student::Student(const Student& orig) {
}

Student::~Student() {
}


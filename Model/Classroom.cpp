/* 
 * File:   Classroom.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:08 PM
 */

#include "Classroom.h"

Classroom::Classroom(string id, int capacity) {
    this->id = id;
    this->capacity = capacity;
}

Classroom::Classroom(const Classroom& orig) {
}

Classroom::~Classroom() {
}


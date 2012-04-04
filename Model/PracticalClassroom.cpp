/* 
 * File:   PracticalClassroom.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:19 PM
 */

#include "PracticalClassroom.h"

PracticalClassroom::PracticalClassroom(string id, int capacity, int elementsNumber) : Classroom(id, capacity){
    this->elementsNumber = elementsNumber;
}

PracticalClassroom::PracticalClassroom(const PracticalClassroom* orig) : Classroom(orig){
    this->elementsNumber = orig->elementsNumber;
}

PracticalClassroom::~PracticalClassroom() {
}


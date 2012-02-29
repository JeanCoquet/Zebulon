/* 
 * File:   PracticalClassroom.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:19 PM
 */

#include "PracticalClassroom.h"

PracticalClassroom::PracticalClassroom(string id, int capacity) : Classroom(id, capacity){
}

PracticalClassroom::PracticalClassroom(const PracticalClassroom& orig, string id, int capacity) : Classroom(id, capacity){
}

PracticalClassroom::~PracticalClassroom() {
}


/*
 * File: LectureHall.C
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:15 PM
 */

#include "LectureHall.h"

LectureHall::LectureHall(string id, int capacity, bool videoconferencing) : Classroom(id, capacity){
    this->videoconferencing = videoconferencing;
}

LectureHall::LectureHall(const LectureHall& orig, string id, int capacity) : Classroom(id, capacity){
}

LectureHall::~LectureHall() {
}
/* 
 * File:   PracticalClassroom.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:19 PM
 */

#ifndef PRACTICALCLASSROOM_H
#define	PRACTICALCLASSROOM_H
#include "Classroom.h"
class PracticalClassroom : public Classroom {
public:
    PracticalClassroom(string id, int capacity, int elementsNumber);
    PracticalClassroom(const PracticalClassroom& orig, string id, int capacity);
    virtual ~PracticalClassroom();
private:
    int elementsNumber;
};

#endif	/* PRACTICALCLASSROOM_H */


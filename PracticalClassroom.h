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
    PracticalClassroom();
    PracticalClassroom(const PracticalClassroom& orig);
    virtual ~PracticalClassroom();
private:
    int elementsNumber;
};

#endif	/* PRACTICALCLASSROOM_H */


/* 
 * File:   LectureHall.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:15 PM
 */

#ifndef LECTUREHALL_H
#define	LECTUREHALL_H
#include "Classroom.h"
class LectureHall : public Classroom {
public:
    LectureHall();
    LectureHall(const LectureHall& orig);
    virtual ~LectureHall();
private:
    bool videoconferencing;
};

#endif	/* LECTUREHALL_H */


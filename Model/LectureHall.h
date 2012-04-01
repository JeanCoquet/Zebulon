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
    LectureHall(string id, int capacity, bool videoconferencing);
    LectureHall(const LectureHall& orig, string id, int capacity);
    virtual ~LectureHall();
    bool IsVideoconferencing() const {
        return videoconferencing;
    }

private:
    bool videoconferencing;
};

#endif	/* LECTUREHALL_H */


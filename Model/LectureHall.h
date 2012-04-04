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
    LectureHall(const LectureHall* orig);
    virtual ~LectureHall();
    bool IsVideoconferencing() const {
        return videoconferencing;
    }
    void SetVideoconferencing(bool videoconferencing) {
        this->videoconferencing = videoconferencing;
    }


private:
    bool videoconferencing;
};

#endif	/* LECTUREHALL_H */


/* 
 * File:   TutorialClassroom.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:17 PM
 */

#ifndef TUTORIALCLASSROOM_H
#define	TUTORIALCLASSROOM_H
#include "Classroom.h"
class TutorialClassroom : public Classroom {
public:
    TutorialClassroom(string id, int capacity, bool videoprojector);
    TutorialClassroom(const TutorialClassroom* orig);
    virtual ~TutorialClassroom();
    bool IsVideoprojector() const {
        return videoprojector;
    }
    void SetVideoprojector(bool videoprojector) {
        this->videoprojector = videoprojector;
    }

private:
    bool videoprojector;
};

#endif	/* TUTORIALCLASSROOM_H */


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
    TutorialClassroom(string id, int capacity);
    TutorialClassroom(const TutorialClassroom& orig, string id, int capacity);
    virtual ~TutorialClassroom();
private:
    bool videoprojector;
};

#endif	/* TUTORIALCLASSROOM_H */


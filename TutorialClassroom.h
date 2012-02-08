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
    TutorialClassroom();
    TutorialClassroom(const TutorialClassroom& orig);
    virtual ~TutorialClassroom();
private:
    bool videoprojector;
};

#endif	/* TUTORIALCLASSROOM_H */


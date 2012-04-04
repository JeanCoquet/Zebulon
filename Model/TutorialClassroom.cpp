/*
 * File: TutorialClassroom.C
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:17 PM
 */

#include "TutorialClassroom.h"

TutorialClassroom::TutorialClassroom(string id, int capacity, bool videoprojector) : Classroom(id, capacity) {
    this->videoprojector = videoprojector;
}

TutorialClassroom::TutorialClassroom(const TutorialClassroom* orig) : Classroom(orig) {
    this->videoprojector = orig->videoprojector;
}

TutorialClassroom::~TutorialClassroom() {
}
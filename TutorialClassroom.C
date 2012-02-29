/* 
 * File:   TutorialClassroom.C
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:17 PM
 */

#include "TutorialClassroom.h"

TutorialClassroom::TutorialClassroom(string id, int capacity) : Classroom(id, capacity) {
}

TutorialClassroom::TutorialClassroom(const TutorialClassroom& orig, string id, int capacity)  : Classroom(id, capacity) {
}

TutorialClassroom::~TutorialClassroom() {
}


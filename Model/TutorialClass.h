/* 
 * File:   TutorialClass.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef TUTORIALCLASS_H
#define	TUTORIALCLASS_H
#include "ClassPeriod.h"
class TutorialClass  : public ClassPeriod{
public:
    TutorialClass(string teacher, int duration, Module* mod);
    TutorialClass(const ClassPeriod* orig);
    virtual ~TutorialClass();
private:

};

#endif	/* TUTORIALCLASS_H */


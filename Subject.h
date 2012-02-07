/* 
 * File:   Subject.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef SUBJECT_H
#define	SUBJECT_H
#include <list>
#include <string>
#include "ClassPeriod.h"

using namespace std;

class Subject {
public:
    Subject();
    Subject(const Subject& orig);
    virtual ~Subject();
private:
    list<ClassPeriod> classPeriodList;
    string theHead;
};

#endif	/* SUBJECT_H */


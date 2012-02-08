/* 
 * File:   PracticalClass.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef PRACTICALCLASS_H
#define	PRACTICALCLASS_H
#include "ClassPeriod.h"

class PracticalClass : public ClassPeriod {
public:
    PracticalClass();
    PracticalClass(const PracticalClass& orig);
    virtual ~PracticalClass();
private:
};

#endif	/* PRACTICALCLASS_H */


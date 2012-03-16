/* 
 * File:   MagistralClass.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef MAGISTRALCLASS_H
#define	MAGISTRALCLASS_H
#include "ClassPeriod.h"
class MagistralClass  : public ClassPeriod{
public:
    MagistralClass(int id, string teacher, int duration);
    virtual ~MagistralClass();
private:

};

#endif	/* MAGISTRALCLASS_H */


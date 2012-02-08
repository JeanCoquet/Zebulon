/* 
 * File:   Module.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:29 PM
 */

#ifndef MODULE_H
#define	MODULE_H
#include <list>
#include <string>
#include "ClassPeriod.h"

using namespace std;
        
class Module {
public:
    Module();
    Module(const Module& orig);
    virtual ~Module();
private:
    list<ClassPeriod> classPeriodList;
    string theHead;
};

#endif	/* MODULE_H */


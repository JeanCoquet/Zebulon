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
    Module(string id, string name, string theHead);
    Module(const Module& orig);
    virtual ~Module();
    
    list<ClassPeriod*>* GetClassPeriodList() const {
        return classPeriodList;
    }

    void SetClassPeriodList(list<ClassPeriod*>* classPeriodList) {
        this->classPeriodList = classPeriodList;
    }


    string GetId() const {
        return id;
    }

    void SetId(string id) {
      this->id = id;
    }

    string GetName() const {
        return name;
    }

    void SetName(string name) {
        this->name = name;
    }

    string GetTheHead() const {
        return theHead;
    }

    void SetTheHead(string theHead) {
        this->theHead = theHead;
    }



private:
    string id;
    string name;
    list<ClassPeriod*> *classPeriodList;
    string theHead;
};

#endif	/* MODULE_H */


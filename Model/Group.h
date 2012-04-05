/* 
 * File:   Group.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:25 PM
 */

#ifndef GROUP_H
#define	GROUP_H
#include <string>
#include <list>
#include "Student.h"

using namespace std;
class Group {
public:
    Group(string id, list<Group*> *groupList);
    Group(const Group* orig);
    virtual ~Group();
    string GetId() const {
        return id;
    }

    void SetId(string id) {
        this->id = id;
    }

    list<Student*>* GetStudentList() const {
        return StudentList;
    }

    void SetStudentList(list<Student*> *StudentList) {
        this->StudentList = StudentList;
    }
    
    list<Group*>* GetGroupList() const {
        return groupList;
    }

    void SetGroupList(list<Group*>* groupList) {
        delete this->groupList;
        this->groupList = groupList;
    }



private:
    string id;
    list<Student*> *StudentList;
    list<Group*> *groupList;
};

#endif	/* GROUP_H */


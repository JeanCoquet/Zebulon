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
    Group(string id, Group *daddy);
    Group(const Group& orig);
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
    
    Group* GetDaddy() const {
        return daddy;
    }

    void SetDaddy(Group* daddy) {
        this->daddy = daddy;
    }


private:
    string id;
    list<Student*> *StudentList;
    Group *daddy;
};

#endif	/* GROUP_H */


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
    Group();
    Group(const Group& orig);
    virtual ~Group();
    string GetId() const {
        return id;
    }

    void SetId(string id) {
        this->id = id;
    }

    list<Student> GetStudentList() const {
        return StudentList;
    }

    void SetStudentList(list<Student> StudentList) {
        this->StudentList = StudentList;
    }

private:
    string id;
    list<Student> StudentList;
};

#endif	/* GROUP_H */


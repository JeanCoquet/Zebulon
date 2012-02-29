/* 
 * File:   Student.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:22 PM
 */

#ifndef Student_H
#define	Student_H
#include <string>
using namespace std;
class Student {
public:
    Student(int id, string lastname, string firstname, string addr, string email);
    Student(const Student& orig);
    virtual ~Student();
    string GetAddr() const {
        return addr;
    }

    void SetAddr(string addr) {
        this->addr = addr;
    }

    string GetEmail() const {
        return email;
    }

    void SetEmail(string email) {
        this->email = email;
    }

    string GetFirstname() const {
        return firstname;
    }

    void SetFirstname(string firstname) {
        this->firstname = firstname;
    }

    int GetId() const {
        return id;
    }

    void SetId(int id) {
        this->id = id;
    }

    string GetLastname() const {
        return lastname;
    }

    void SetLastname(string lastname) {
        this->lastname = lastname;
    }

private:
    int id;
    string lastname;
    string firstname;
    string addr;
    string email;
};

#endif	/* Student_H */


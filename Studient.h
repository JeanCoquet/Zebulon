/* 
 * File:   Studient.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:22 PM
 */

#ifndef STUDIENT_H
#define	STUDIENT_H
#include <string>
using namespace std;
class Studient {
public:
    Studient();
    Studient(const Studient& orig);
    virtual ~Studient();
private:
    int id;
    string lastname;
    string firstname;
    string addr;
    string email;

};

#endif	/* STUDIENT_H */


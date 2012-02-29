/* 
 * File:   Classroom.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:08 PM
 */

#ifndef CLASSROOM_H
#define	CLASSROOM_H
#include <string>
using namespace std;
class Classroom {
public:
    Classroom(string id, int capacity);
    Classroom(const Classroom& orig);
    virtual ~Classroom();
private:
    string id;
    int capacity;
};

#endif	/* CLASSROOM_H */


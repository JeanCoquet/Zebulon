/* 
 * File:   Group.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:25 PM
 */

#ifndef GROUP_H
#define	GROUP_H
#include <string>
using namespace std;
class Group {
public:
    Group();
    Group(const Group& orig);
    virtual ~Group();
private:
    string id;
//    Group parentGroup;
};

#endif	/* GROUP_H */


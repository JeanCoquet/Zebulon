/* 
 * File:   Database.h
 * Author: bicodul
 *
 * Created on February 10, 2012, 4:54 PM
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include "../Model/PracticalClass.h"
#include "../Model/TutorialClass.h"
#include "../Model/MagistralClass.h"
#include "../Model/ClassPeriod.h"
#include "../Model/Schedule.h"
#include "../Model/Group.h"
#include "../Model/LectureHall.h"
#include "../Model/PracticalClassroom.h"
#include "../Model/TutorialClassroom.h"
#include "../Model/PracticalClass.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../sqlite/lib/sqlite3.h"
#include <exception>
using namespace std;

class Database {
public:
    Database();
    Database(const Database& orig);
    virtual ~Database();
    list< list<string> >* request(string request) throw(int);
    
    void addStudent(Student *stud, Group *group);
    void delStudent(Student *stud, Group *group);
    void updateStudent(Student *stud, Group *group, string id, string lastname, string firstname, string addr, string email);
    
    void addModule(Module *mod);
    void delModule(Module *mod);
    void updateModule(Module* mod, string id, string name, string theHead);
    
    void addGroup(Group *group);
    void delGroup(Group *group);
    void updateGroup(Group *group, string id, Group *daddyGroup);
    
    void addTimeSlot(TimeSlot* timeSlot);
    void delTimeSlot(TimeSlot* timeSlot);
    
    void addClassPeriod(ClassPeriod* classPeriod, int id_type, Module *mod);
    void delClassPeriod(ClassPeriod* classPeriod, Module *mod);
    void updateClassPeriod(Module *mod, ClassPeriod* cp, int id_type,  string teacher, int duration, list<Group*> *lg);
    
    void addClassroom(Classroom* cr);
    void addTutorialClassroom(TutorialClassroom* cr);
    void addPracticalClassroom(PracticalClassroom* cr);
    void addLectureHall(LectureHall* cr);
    void delClassroom(Classroom* cr);
    void delTutorialClassroom(TutorialClassroom* cr);
    void delPracticalClassroom(PracticalClassroom* cr);
    void delLectureHall(LectureHall* cr);
    void updateClassroom(Classroom* cr, string id, int capacity);
    void updateTutorialClassroom(TutorialClassroom* cr, string id, bool specificity);
    void updatePracticalClassroom(PracticalClassroom* cr, string id, int specificity);
    void updateLectureHall(LectureHall* cr, string id, bool specificity);
    
    void joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod);
    
    
    void commit();

private:
    sqlite3 *database;
    static int callback(void*, int, char**, char**);
    fstream history;

};

#endif	/* DATABASE_H */


/* 
 * File:   Controller.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 8:34 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H
#include "Student.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Schedule.h"
#include "Group.h"
#include "sqlite/Database.h"

using namespace std;
class Controller {
public:
    Controller() throw(int);
    Controller(const Controller& orig);
    // Pour ajouter on demande l'objet. pour supprimer on demande l'id
    int strToInt(string);
    void loadSchedule();
    void commit();
    void addStudent(Student *stud, Group *group);
    void delStudent(Student *stud, Group *group);
    void addModule(Module *mod);
    void delModule(Module *mod);
    void addGroup(Group *group);
    void delGroup(Group *group);
    void joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod);
    virtual ~Controller();
private:
    Schedule *schedule;
    Database *database;
    fstream history;
};

#endif	/* CONTROLLER_H */


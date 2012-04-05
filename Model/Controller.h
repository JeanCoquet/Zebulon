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
#include "sqlite/Database.h"

using namespace std;
class Controller {
public:
    Controller() throw(int);
    Controller(const Controller& orig);
    // Pour ajouter on demande l'objet. pour supprimer on demande l'id
    Database* getDatabase() const {
        return database;
    }
    
    int strToInt(string);
    Date* strToDate(string);
    bool strToBool(string);
    string intToStr(int);

    void loadSchedule();
    void commit();
    void addStudent(Student *stud, Group *group);
    void delStudent(Student *stud, Group *group);
    void addModule(Module *mod);
    void delModule(Module *mod);
    void addGroup(Group *group);
    void delGroup(Group *group);
    bool addTimeSlot(TimeSlot* timeSlot);
    void delTimeSlot(TimeSlot* timeSlot);
    void addClassPeriod(ClassPeriod* classPeriod, Module *mod);
    void delClassPeriod(ClassPeriod* classPeriod, Module *mod);
    void delClassroom(Classroom* cr);
    void addClassroom(Classroom* cr);
    void setClassroom(Classroom* cr, string id, int capacity, int specificity);
    void joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod);
    void setModule(Module* mod, string id, string name, string theHead);
    void setClassPeriod(Module *mod, ClassPeriod* cp, string type,  string teacher, int duration, list<Group*> *lg);
    void setGroup(Group *g, string id,  list<Group*> *lg);
    void setStudent(Student *s, Group* group, string id, string lastname, string firstname, string addr, string email);
    virtual ~Controller();


    Schedule* getSchedule() const {
        return schedule;
    }

    void setSchedule(Schedule* schedule) {
        this->schedule = schedule;
    }

private:
    Schedule *schedule;
    Database *database;
    Main
};

#endif	/* CONTROLLER_H */


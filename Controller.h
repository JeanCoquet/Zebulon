/* 
 * File:   Controller.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 8:34 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H
#include "Studient.h"
#include <string>
#include "Schedule.h"
using namespace std;
class Controller {
public:
    Controller();
    Controller(const Controller& orig);
    // Pour ajouter on demande l'objet. pour supprimer on demande l'id
    void addStudient(Studient *stud);
    void delStudient(string id);
    void addModule(Module *mod);
    void delModule(string id);
    void addGroup(Group *group);
    void delGroup(string id);
    void joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod);
    virtual ~Controller();
private:
    Schedule schedule;
};

#endif	/* CONTROLLER_H */


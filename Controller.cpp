/* 
 * File:   Controller.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 8:34 PM
 */

#include "Controller.h"

Controller::Controller() {
         this->schedule = loadSchedule(); //constructeur statique au lieu de dynamique    
         this->database = new Database();
}

bool Controller::addStudent(Student *stud, Group *group){
    string str = "";
    str.append("insert into Student values(");
    str.append(
        stud->GetId()+","
        +group->GetId()+","
        +stud->GetLastname()+","
        +stud->GetFirstname()+","
        +stud->GetAddr()+","
        +stud->GetEmail()+")"
    );
    try{
        database->request(str);
    }
    catch(int){
        return false;
    }
    group->GetStudentList()->push_back(stud);
    return true;
}

bool Controller::addGroup(Group* group){
    try{
        database->request("insert into Group values("+group->GetId()+", NULL)");
    }
    catch(int){
        return false;
    }
    schedule->GetGroupList()->push_back(group);
    return true;
}

bool Controller::addModule(Module* mod){
    try{
        database->request("insert into Module values("+mod->GetId()+","+mod->GetName()+","+mod->GetTheHead()+")");
    }
    catch(int){
        return false;
    }
    return true;
    schedule->GetModuleList()->push_back(mod);
}

void Controller::delGroup(Group* group) {
    try{
        database->request("delete from Group where id = '"+group->GetId()+"'");
    }
    catch(int){
    }
}

void Controller::delModule(Module* mod) {
    try{
        database->request("delete from Module where id = '"+mod->GetId()+"'");
    }
    catch(int){
    }
}

void Controller::delStudent(Student *stud) {
    try{
        database->request("delete from Student where id = '"+stud->GetId()+"'");
    }
    catch(int){
    }
}



Schedule* Controller::loadSchedule(){
    return NULL;
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}


/* 
 * File:   Database.cpp
 * Author: bicodul
 * 
 * Created on February 10, 2012, 4:54 PM
 */
#include <iostream>
#include "Database.h"
using namespace std;

const char* historyFile = "history.sql";

string boolToStr(bool b) {
    if(b) return "true";
    else return "false";
}

list< list<string> >* Database::request(string request) throw(int){
   list< list<string> >* result = new list< list<string> >();
   char *zErrMsg = NULL;
   cout<<"execution de la requete : "<<request<<endl;
   int rc = sqlite3_exec(this->database, request.c_str(), callback, (void*)result, &zErrMsg);
   cout<<"requete executee"<<endl;
   if(rc != SQLITE_OK) {
        cout<<"Error sql"<<endl;
        sqlite3_free(zErrMsg);
        throw 1;
        return NULL;
   }
   return result;
}

int Database::callback(void *result, int argc, char **argv, char **azColName) {
    cout<<"traitement de la ligne"<<endl;
    list<string>* line = new list<string>();
    for(int i=0 ; i<argc ; i++){
        if(argv[i] == NULL)
            line->push_back("");  
        else
            line->push_back(argv[i]);    
    }
    ((list< list<string> >*)result)->push_back(*line);
    return 0;
}


Database::Database() {
    if(sqlite3_open("./sqlite/Zebulon_database.sqlite", &database) == SQLITE_OK) {
        cout<<"Database is open"<<endl;
    }
    
    this->history.open(historyFile, ios::out | ios::trunc);
         if(this->history.bad())
             throw 1;
}

void Database::addStudent(Student *stud, Group *group) {
    cout << "insert into Student values('" << stud->GetId()<<"','"<< group->GetId()<<"','"<< stud->GetLastname()<<"','"
        << stud->GetFirstname()<<"','"<< stud->GetAddr()<<"','"<< stud->GetEmail()<<"')" << endl;    
    this->history << "insert into Student values('" << stud->GetId()<<"','"<< group->GetId()<<"','"<< stud->GetLastname()<<"','"
        << stud->GetFirstname()<<"','"<< stud->GetAddr()<<"','"<< stud->GetEmail()<<"')" << endl;    
}
void Database::delStudent(Student *stud, Group *group) {
    cout <<  "delete from Student where id = '"<<stud->GetId()<<"'"<<endl;
    this->history << "delete from Student where id = '"<<stud->GetId()<<"'"<<endl;
}
void Database::updateStudent(Student *stud, Group *group, string id, string lastname, string firstname, string addr, string email){

}

void Database::addModule(Module *mod) {
    cout << "insert into Module values('"<<mod->GetId()<<"','"<<mod->GetName()<<"','"<<mod->GetTheHead()<<"')"<<endl;
    this->history << "insert into Module values('"<<mod->GetId()<<"','"<<mod->GetName()<<"','"<<mod->GetTheHead()<<"')"<<endl;
}
void Database::delModule(Module *mod){
    cout << "delete from ClassPeriod where id_module = '"<<mod->GetId()<<"'"<<endl;
    this->history << "delete from ClassPeriod where id_module = '"<<mod->GetId()<<"'"<<endl;
    cout << "delete from Module where id = '"<<mod->GetId()<<"'"<<endl;
    this->history << "delete from Module where id = '"<<mod->GetId()<<"'"<<endl;
}
void Database::updateModule(Module* mod, string id, string name, string theHead) {
    cout << "update module set id = '"<<id<<"', name = '"<<name<<"', theHead = '"<<theHead<<"' where id = '"<<mod->GetId()<<endl;
    this->history << "update module set id = '"<<id<<"', name = '"<<name<<"', theHead = '"<<theHead<<"' where id = '"<<mod->GetId()<<endl;
    cout << "update classPeriod set id_module = '"<<id<<"' where id_module = '"<<mod->GetId()<<"'"<<endl;
    this->history << "update classPeriod set id_module = '"<<id<<"' where id_module = '"<<mod->GetId()<<"'"<<endl;
}

void Database::addGroup(Group *group){
    
}
void Database::delGroup(Group *group) {
    cout << "delete from Student where id_group='"<<group->GetId()<<"'"<<endl;
    this->history << "delete from Student where id_group='"<<group->GetId()<<"'"<<endl;
    cout << "delete from 'Group' where id = '"<<group->GetId()<<"'"<<endl;
    this->history << "delete from 'Group' where id = '"<<group->GetId()<<"'"<<endl;
}
void Database::updateGroup(Group *group, string id, list<Student*> studentList, Group *dadyGroup){
    
}

void Database::addTimeSlot(TimeSlot* timeSlot){
    cout << "insert into TimeSlot values('"<<timeSlot->GetId()<<"','"<<timeSlot->GetClassroom()->GetId()<<"','"<<timeSlot->GetClassPeriod()->GetId()<<"','"<<*(timeSlot->GetStartDate())<<"')"<<endl;
    this->history << "insert into TimeSlot values('"<<timeSlot->GetId()<<"','"<<timeSlot->GetClassroom()->GetId()<<"','"<<timeSlot->GetClassPeriod()->GetId()<<"','"<<*(timeSlot->GetStartDate())<<"')"<<endl;
    
}
void Database::delTimeSlot(TimeSlot* timeSlot) {
    cout << "delete from TimeSlot where id = '"<<timeSlot->GetId()<<"'"<<endl;
    this->history << "delete from TimeSlot where id = '"<<timeSlot->GetId()<<"'"<<endl;
}

void Database::addClassPeriod(ClassPeriod* classPeriod, int id_type, Module *mod) {
    this->history << "insert into ClassPeriod values('"<<classPeriod->GetId()<<"','"<<mod->GetId()<<"', '"<<classPeriod->GetTeacher()<<"', '"<<classPeriod->GetDuration()<<"', '"<<id_type<<"')"<<endl;
}
void Database::delClassPeriod(ClassPeriod* classPeriod, Module *mod){
    cout << "delete from ClassPeriod where id = '"<<classPeriod->GetId()<<"'"<<endl;
    this->history << "delete from ClassPeriod where id = '"<<classPeriod->GetId()<<"'"<<endl;
    cout << "delete from assign where id_classperiod = '"<<classPeriod->GetId()<<"'"<<endl;
    history << "delete from assign where id_classperiod = '"<<classPeriod->GetId()<<"'"<<endl;
}
void Database::updateClassPeriod(Module *mod, ClassPeriod* cp, int id_type,  string teacher, int duration, list<Group*> *lg) {
    cout << "update classperiod set teacher = '"<<teacher<<"', duration = '"<<duration<<"', id_type = '"<<id_type<<"' where id = '"<<cp->GetId()<<"'"<<endl; 
    history << "update classperiod set teacher = '"<<teacher<<"', duration = '"<<duration<<"', id_type = '"<<id_type<<"' where id = '"<<cp->GetId()<<"'"<<endl; 
    cout << "delete from assign where id_classperiod = '"<<cp->GetId()<<"'"<<endl;
    history << "delete from assign where id_classperiod = '"<<cp->GetId()<<"'"<<endl;
    
    list<Group*>::iterator it = lg->begin();
    list<Group*>::const_iterator itMax = lg->end();
    for(; it!=itMax; it++) {
        cout << "insert into assign values('"<<cp->GetId()<<"', '"<<(*it)->GetId()<<"')"<<endl;
        history << "insert into assign values('"<<cp->GetId()<<"', '"<<(*it)->GetId()<<"')"<<endl;
    }
}

void Database::addClassroom(Classroom* cr) {
    cout << "insert into Classroom values('" << cr->GetId() <<"','"<< cr->GetCapacity() <<"')" << endl; 
    this->history << "insert into Classroom values('" << cr->GetId() <<"','"<< cr->GetCapacity() <<"')" << endl; 
}
void Database::addTutorialClassroom(TutorialClassroom* cr) {
    cout << "insert into TutorialClassroom values('" << cr->GetId() <<"','"<< cr->IsVideoprojector() <<"')" << endl; 
    this->history << "insert into TutorialClassroom values('" << cr->GetId() <<"','"<< cr->IsVideoprojector() <<"')" << endl; 
}
void Database::addPracticalClassroom(PracticalClassroom* cr) {
    cout << "insert into PracticalClassroom values('" << cr->GetId() <<"','"<< cr->GetElementsNumber() <<"')" << endl; 
    this->history << "insert into PracticalClassroom values('" << cr->GetId() <<"','"<< cr->GetElementsNumber() <<"')" << endl; 
}
void Database::addLectureHall(LectureHall* cr) {
    cout << "insert into LectureHall values('" << cr->GetId() <<"','"<< ((LectureHall*)cr)->IsVideoconferencing() <<"')" << endl; 
    this->history << "insert into LectureHall values('" << cr->GetId() <<"','"<< ((LectureHall*)cr)->IsVideoconferencing() <<"')" << endl; 
}
void Database::delClassroom(Classroom* cr) {
    cout << "delete from Classroom where id='"<<cr->GetId()<<"'";
    this->history << "delete from Classroom where id='"<<cr->GetId()<<"'";
}
void Database::delTutorialClassroom(TutorialClassroom* cr) {
    cout << "delete from TutorialClassroom where id='"<<cr->GetId()<<"'";    
    this->history << "delete from TutorialClassroom where id='"<<cr->GetId()<<"'";    
}
void Database::delPracticalClassroom(PracticalClassroom* cr) {
    cout << "delete from PracticalClassroom where id='"<<cr->GetId()<<"'";
    this->history << "delete from PracticalClassroom where id='"<<cr->GetId()<<"'";
}
void Database::delLectureHall(LectureHall* cr) {
    cout << "delete from LectureHall where id='"<<cr->GetId()<<"'";
    this->history << "delete from LectureHall where id='"<<cr->GetId()<<"'";
}
void Database::updateClassroom(Classroom* cr, string id, int capacity) {
    cout << "update classroom set id = '"<< id <<"', capacity = '"<<capacity<<"' where id = '"<<cr->GetId()<<"'"<<endl;
    history << "update classroom set id = '"<< id <<"', capacity = '"<<capacity<<"' where id = '"<<cr->GetId()<<"'"<<endl;
}
void Database::updateTutorialClassroom(TutorialClassroom* cr, string id, bool specificity) {
    cout << "update TutorialClassroom set id = '"<< id <<"', videoprojector = '"<<boolToStr(specificity)<<"' where id = '"<<cr->GetId()<<"'"<<endl;
    history << "update TutorialClassroom set id = '"<< id <<"', videoprojector = '"<<boolToStr(specificity)<<"' where id = '"<<cr->GetId()<<"'"<<endl;
}
void Database::updatePracticalClassroom(PracticalClassroom* cr, string id, int specificity) {
    cout << "update PracticalClassroom set id = '"<< id <<"', elementsnumber = '"<<specificity<<"' where id = '"<<cr->GetId()<<"'"<<endl;
    history << "update PracticalClassroom set id = '"<< id <<"', elementsnumber = '"<<specificity<<"' where id = '"<<cr->GetId()<<"'"<<endl;
}
void Database::updateLectureHall(LectureHall* cr, string id, bool specificity) {
    cout << "update LectureHall set id = '"<< id <<"', videoconferencing = '"<<boolToStr(specificity)<<"' where id = '"<<cr->GetId()<<"'"<<endl;
    history << "update LectureHall set id = '"<< id <<"', videoconferencing = '"<<boolToStr(specificity)<<"' where id = '"<<cr->GetId()<<"'"<<endl;
}

void Database::joinTimeSlotWithClassPeriod(TimeSlot *timeslot, ClassPeriod *classPeriod){
    
}

void Database::commit() {
    this->history.close();
    this->history.open(historyFile, ios::in);
    string line = "";
    while(!this->history.eof()){
        getline(this->history, line);
        if(line != ""){
            try{
                this->request(line);
                cout<<"request : '"<<line<<"'"<<endl;
            }catch(int){
                cout<<"ignored request : '"<<line<<"'"<<endl;
            }
        }
    }
    this->history.open(historyFile, ios::out | ios::trunc);
}

Database::Database(const Database& orig) {
}

Database::~Database() {
       sqlite3_close(database);
}


/* 
 * File:   Controller.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 8:34 PM
 */

#include "Controller.h"
const char* historyFile = "history.sql";

Controller::Controller() throw(int){
        this->database = new Database(); // doit etre avant load
         this->schedule = NULL;
         loadSchedule();  
         cout<<"schedule loaded."<<endl;
         
         this->history.open(historyFile, ios::out | ios::trunc);
         if(this->history.bad())
             throw 1;
}

void Controller::addStudent(Student *stud, Group *group){
    this->history << "insert into Student values('" << stud->GetId()<<"','"<< group->GetId()<<"','"<< stud->GetLastname()<<"','"
        << stud->GetFirstname()<<"','"<< stud->GetAddr()<<"','"<< stud->GetEmail()<<"')" << endl;    
    group->GetStudentList()->push_back(stud);
}

void Controller::addGroup(Group* group){
    this->history << "insert into 'Group' values('"<<group->GetId()<<"', '')"<<endl;
    schedule->GetGroupList()->push_back(group);
}

void Controller::addModule(Module* mod){
    this->history << "insert into Module values('"<<mod->GetId()<<"','"<<mod->GetName()<<"','"<<mod->GetTheHead()<<"')"<<endl;
    schedule->GetModuleList()->push_back(mod);
}

void Controller::delGroup(Group* group) {
    this->history << "delete from 'Group' where id = '"<<group->GetId()<<"'"<<endl;
    this->schedule->GetGroupList()->remove(group);
}

void Controller::delModule(Module* mod) {
    this->history << "delete from Module where id = '"<<mod->GetId()<<"'"<<endl;
    this->schedule->GetModuleList()->remove(mod);
}

void Controller::delStudent(Student *stud, Group *group) {
    this->history << "delete from Student where id = '"<<stud->GetId()<<"'"<<endl;
    group->GetStudentList()->remove(stud);
}

void Controller::commit(){
    this->history.close();
    this->history.open(historyFile, ios::in);
    string line = "";
    while(!this->history.eof()){
        getline(this->history, line);
        if(line != ""){
            try{
                this->database->request(line);
                cout<<"request : '"<<line<<"'"<<endl;
            }catch(int){
                cout<<"ignored request : '"<<line<<"'"<<endl;
            }
        }
    }
    this->history.open(historyFile, ios::out | ios::trunc);
}
int Controller::strToInt(string str){
    int val = 0;
    for(int i= 0 ; i < str.length() ; i++){
        val *= 10;
        val += str[i] - '0';
    }
   return val; 
}

void Controller::loadSchedule(){
    cout<<"loading schedule..."<<endl;
    /*if(this->schedule != NULL)
        delete this->schedule;*/
    this->schedule = new Schedule();
    list< list<string> >* result;
    try{
         result = database->request("select * from classroom");
         cout<<"   request done."<<endl;
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule->GetClassroomList()->push_back(new Classroom(*itList, strToInt(*(++itList)) ));
                /*for(;itList!=MaxListList;itList++){    
                    cout<<*itList<<" ";
                }*/
                cout<<"#"<<endl;
             } 
         }
    }catch(int){
        cout<<"Error while loading classrooms."<<endl;
    }
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
    this->history.close();
    delete this->schedule;
    delete this->database;
}


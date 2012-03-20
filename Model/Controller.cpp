/* 
 * File:   Controller.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 8:34 PM
 */

#include "Controller.h"
#include "LectureHall.h"
#include "PracticalClassroom.h"
#include "TutorialClassroom.h"
#include "PracticalClass.h"
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

/*void Controller::addGroup(Group* group)
  {    if(group->GetDaddy() != NULL){
        this->history << "insert into 'Group' values('"<<group->GetId()<<"', ''"<<group->GetDaddy()->GetId()<<"');"<<endl;
    }
    else {
        this->history << "insert into 'Group' values('"<<group->GetId()<<"', '')"<<endl;
    }
    schedule->GetGroupList()->push_back(group);
}*/

void Controller::addModule(Module* mod){
    this->history << "insert into Module values('"<<mod->GetId()<<"','"<<mod->GetName()<<"','"<<mod->GetTheHead()<<"')"<<endl;
    schedule->GetModuleList()->push_back(mod);
}

void Controller::delGroup(Group* group) {
    this->history << "delete from Student where id_group='"<<group->GetId()<<"'";
    this->history << "delete from 'Group' where id = '"<<group->GetId()<<"'"<<endl;
    this->schedule->GetGroupList()->remove(group);
}

void Controller::delModule(Module* mod) {
    this->history << "delete from ClassPeriod where id_module = '"<<mod->GetId()<<"'"<<endl;
    this->history << "delete from Module where id = '"<<mod->GetId()<<"'"<<endl;
    this->schedule->GetModuleList()->remove(mod);
}

void Controller::delStudent(Student *stud, Group *group) {
    this->history << "delete from Student where id = '"<<stud->GetId()<<"'"<<endl;
    group->GetStudentList()->remove(stud);
}

bool Controller::addTimeSlot(TimeSlot* timeSlot){
    list<TimeSlot*> *timeSlotList = new list<TimeSlot*>();
    list<TimeSlot*>::iterator it = this->schedule->GetTimeSlotList()->begin();
    list<TimeSlot*> ::const_iterator itMax = this->schedule->GetTimeSlotList()->end();
    for(; it!=itMax; it++) {
        if((*it)->GetStartDate() >= timeSlot->GetStartDate()
                && (*it)->GetStartDate() < timeSlot->GetStartDate()+timeSlot->GetClassPeriod()->GetDuration()) {
            timeSlotList->push_back(*it);
        }
    }
    
    it = timeSlotList->begin();
    itMax = timeSlotList->end();
    for(; it!=itMax; it++) {
        if((*it)->GetClassroom()->GetId() == timeSlot->GetClassroom()->GetId())
            return false;
        else {
            list<Group*>::iterator itG = (*it)->GetClassPeriod()->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = (*it)->GetClassPeriod()->GetGroupList()->end();
            for(; itG != itGMax; itG++) {
                list<Group*>::iterator itGTimeSlot = timeSlot->GetClassPeriod()->GetGroupList()->begin();
                list<Group*>::const_iterator itGMaxTimeSlot = timeSlot->GetClassPeriod()->GetGroupList()->end();
                for(; itGTimeSlot != itGMaxTimeSlot; itGTimeSlot++) {
                    if((*itG)->GetId() == (*itGTimeSlot)->GetId())
                        return false;
                }
            }
        }
    }
    
    this->history << "insert into TimeSlot values('"<<timeSlot->GetId()<<"','"<<timeSlot->GetClassroom()<<"','"<<timeSlot->GetClassPeriod()<<"','"<<timeSlot->GetStartDate()<<"')";
    this->schedule->GetTimeSlotList()->push_back(timeSlot);
    
    delete timeSlotList;
    return true;
}

void Controller::delTimeSlot(TimeSlot* timeSlot) {
    this->history << "delete from TimeSlot where id = '"<<timeSlot->GetId()<<"'"<<endl;
    this->schedule->GetTimeSlotList()->remove(timeSlot);
}
    
void Controller::addClassPeriod(ClassPeriod* classPeriod, Module *mod) {
    
    this->history << "insert into ClassPeriod values('"<<"')";
    mod->GetClassPeriodList()->push_back(classPeriod);
}

void Controller::delClassPeriod(ClassPeriod* classPeriod, Module *mod) {
    this->history << "delete from ClassPeriod where id = '"<<classPeriod->GetId()<<"'"<<endl;
    mod->GetClassPeriodList()->remove(classPeriod);
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

Date* Controller::strToDate(string date){
    int h = 0;
    int m = 0;
    
    if(date.length() > 10){
        h = strToInt(date.substr(11,2));
        m = strToInt(date.substr(15,2));
    }
    Date *dateh = new Date(strToInt(date.substr(0,2)), strToInt(date.substr(3,2)), strToInt(date.substr(6,4)), h, m);
    return dateh;
}

bool Controller::strToBool(string str){
    return (str == "true");
}

struct groupString{
    Group* group;
    string str;
};

void addChildrenToGroup(list<Group*> *lgBase, list<struct groupString*>* lgs, Group* group){
    list<Group*>* lChildren = new list<Group*>();
    group->SetGroupList(lChildren);
    list< struct groupString* >::iterator itLGS = lgs->begin();
    list< struct groupString* >::const_iterator itMaxLGS = lgs->end();
    int count = 0;
    while(itLGS != itMaxLGS){
        if( (*itLGS)->str == group->GetId() ){
            Group *groupChld = new Group((*itLGS)->group);
            lChildren->push_back(groupChld);
            lgBase->push_back(groupChld);
            lgs->erase(itLGS);
            itLGS = lgs->begin();
            itMaxLGS = lgs->end();
            count = count - 1;
            for(int i = 0 ; i < count ; i++){
                itLGS++;
            }
        }
        itLGS++; count++;
    }
    list<Group*>::iterator it = lChildren->begin();
    list<Group*>::const_iterator itMax = lChildren->end();
    for(; it!=itMax; it++) {
        addChildrenToGroup(lgBase, lgs, (*it));
    }
}


void Controller::loadSchedule(){
    cout<<"loading schedule..."<<endl;
    /*if(this->schedule != NULL)
        delete this->schedule;*/
    this->schedule = new Schedule();
    list< list<string> >* result;
    try{
         result = database->request("select * from vlecturehall");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule->GetClassroomList()->push_back(new LectureHall(*itList, strToInt(*(++itList)), strToBool(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database->request("select * from vpracticalclassroom");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule->GetClassroomList()->push_back(new PracticalClassroom(*itList, strToInt(*(++itList)), strToInt(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database->request("select * from vtutorialclassroom");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule->GetClassroomList()->push_back(new TutorialClassroom(*itList, strToInt(*(++itList)), strToBool(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database->request("select * from 'group'");
         if(result != NULL){
             list<struct groupString*>* lgs = new list<struct groupString*>();
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                
                string id = (*itList);
                string idP = *(++itList);
                 
                Group *g = new Group(id, NULL);
                if(idP == "") {
                    this->schedule->GetGroupList()->push_back(g);
                }
                else {
                    struct groupString *gs = new struct groupString();
                    gs->str = idP; 
                    gs->group = g;
                    lgs->push_back(gs);
                }
                
             } 

            list<Group*>::iterator itG = this->schedule->GetGroupList()->begin();
            list<Group*>::const_iterator itMaxG = this->schedule->GetGroupList()->end();
            for(; itG!=itMaxG; itG++) {
                addChildrenToGroup(this->schedule->GetGroupList(), lgs, (*itG));
            }
            
            if(lgs->size() != 0) {
                list< struct groupString* >::iterator itLGS = lgs->begin();
                list< struct groupString* >::const_iterator itMaxLGS = lgs->end();
                for(;itLGS != itMaxLGS ; itLGS++){
                        Group *groupChld = new Group((*itLGS)->group);
                        this->schedule->GetGroupList()->push_back(groupChld);
                }
            }
            delete lgs;             
         }
         
         result->clear();      
         
         result = database->request("select * from student");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                string stuId = *itList;
                string groupId = *(++itList);
                Student *stud = new Student(stuId, *(++itList), *(++itList), *(++itList), *(++itList));
                
                list<Group*>::const_iterator MaxGroupList = this->schedule->GetGroupList()->end();                
                list<Group*>::iterator elemGroupList = this->schedule->GetGroupList()->begin();                
                for(;elemGroupList != MaxGroupList ; elemGroupList++){
                    if((*elemGroupList)->GetId() == groupId){
                        (*elemGroupList)->GetStudentList()->push_back(stud);
                        break;
                    }
                }
                
             } 
         }
         
         
         
         result->clear();
         result = database->request("select m.id, m.name, m.theHead, c.id, c.teacher, c.duration, c.id_type, a.id_group from Module m left join Classperiod c on m.id = c.id_module left join assign a on c.id = a.id_classPeriod order by m.id, c.id, a.id_group");
         if(result != NULL){
             string idModule = "";
             string idClassPeriod = "";
             Module *mod;
             ClassPeriod *classPeriod;
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                //list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                if(idModule != *itList) {
                    idModule = *itList;
                    mod = new Module(idModule, *(++itList), *(++itList));
                    this->schedule->GetModuleList()->push_back(mod);
                }
                else {
                    ++itList++;
                }
                if(*(++itList) != "") { 
                    if(idClassPeriod != (*itList) ) {
                        idClassPeriod = (*itList);
                        int id = strToInt(*(itList));
                        string teacher = *(++itList);
                        int duration = strToInt(*(++itList));
                        int type = strToInt(*(++itList));
                        switch(type){
                            case 1 :
                                classPeriod = new PracticalClass(id, teacher, duration);
                                break;
                            case 2 :
                                classPeriod = new MagistralClass(id, teacher, duration);
                                break;
                            case 3 :
                                classPeriod = new TutorialClass(id, teacher, duration);
                                break;
                        }

                        mod->GetClassPeriodList()->push_back(classPeriod);
                    }
                    else {
                        ++itList++;
                        ++itList++; 
                    }
                    if(*(++itList) != "") {
                        string idGroup = (*itList);
                        list<Group*>::iterator it = this->schedule->GetGroupList()->begin();
                        list<Group*>::const_iterator itMax = this->schedule->GetGroupList()->end();
                        for(; it!=itMax; it++) {
                            if((*it)->GetId() == idGroup) {
                                classPeriod->GetGroupList()->push_back(*it);
                                break;
                            }
                        }
                    }
                }
                
             } 
         }
         
         result->clear();
         result = database->request("select id_classroom, id_classperiod, id, date from timeslot");
         if(result != NULL){
             string idModule = "";
             Module *mod;
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                Classroom *classroom;
                ClassPeriod *classperiod;
                string classroomId = *itList;
                string classPeriodId = *(++itList);
                //recherche de la salle
                list<Classroom*>::const_iterator MaxClassroomList = this->schedule->GetClassroomList()->end();                
                list<Classroom*>::iterator elemClassroomList = this->schedule->GetClassroomList()->begin();                
                for(;elemClassroomList != MaxClassroomList ; elemClassroomList++){
                    if((*elemClassroomList)->GetId() == classroomId){
                        classroom = (*elemClassroomList);
                        break;
                    }
                }
                
                list<Module*>::const_iterator MaxModuleList = this->schedule->GetModuleList()->end();                
                list<Module*>::iterator elemModuleList = this->schedule->GetModuleList()->begin();                
                for(;elemModuleList != MaxModuleList ; elemModuleList++){
                    list<ClassPeriod*>::const_iterator MaxClassPeriodList = (*elemModuleList)->GetClassPeriodList()->end();
                    list<ClassPeriod*>::iterator elemClassPeriodList = (*elemModuleList)->GetClassPeriodList()->begin();
                    for(;elemClassPeriodList != MaxClassPeriodList ; elemClassPeriodList++){
                        if((*elemClassPeriodList)->GetId() == strToInt(classPeriodId)){
                            classperiod = (*elemClassPeriodList);
                            break;
                        }
                }
            }
                
                TimeSlot *timeslot = new TimeSlot(strToInt(*(++itList)), strToDate(*(++itList)), classroom, classperiod);
                schedule->GetTimeSlotList()->push_back(timeslot); 
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


<<<<<<< HEAD
/*
 * File:   main.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 09:37
 */

#include <QtGui/QApplication>
#include "Gui/mainwindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    MainWindow w;
    w.show();


    // create and show your widgets here

    return app.exec();
}

=======
/* 
 * File:   main.cpp
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:28
 */

#include <iostream>
#include "Controller.h"
#include "sqlite/lib/sqlite3.h"
#include "sqlite/Database.h"


using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);


int main(int argc, char** argv) {    
    Controller *ctrl;
    try{
         ctrl = new Controller();
    }catch(int){
        cout<<"Error while Controller initialisation."<<endl;
        return (1);
    }
    cout<<ctrl->getSchedule()->GetGroupList()->size()<<endl;
    
    list<Group*>::iterator it = ctrl->getSchedule()->GetGroupList()->begin();
    list<Group*>::const_iterator MaxList = ctrl->getSchedule()->GetGroupList()->end();
    for(;it != MaxList; it++){
        cout<<(*it)->GetId()<<endl;
        list<Student*>::iterator it2 = (*it)->GetStudentList()->begin();
        list<Student*>::const_iterator MaxList2 = (*it)->GetStudentList()->end();
        for(;it2 != MaxList2; it2++){
            cout<<"     "<<(*it2)->GetId()<<" "<<(*it2)->GetFirstname()<<" "<<
                    (*it2)->GetLastname()<<" "<<(*it2)->GetAddr()<<" "<<(*it2)->GetEmail()<<endl;
        }
    } 
    
    list<Module*>::iterator it3 = ctrl->getSchedule()->GetModuleList()->begin();
    list<Module*>::const_iterator MaxList3 = ctrl->getSchedule()->GetModuleList()->end();
    for(;it3 != MaxList3; it3++){
        cout<<(*it3)->GetName()<<endl;
        list<ClassPeriod*>::iterator it4 = (*it3)->GetClassPeriodList()->begin();
        list<ClassPeriod*>::const_iterator MaxList4 = (*it3)->GetClassPeriodList()->end();
        for(;it4 != MaxList4; it4++){
            cout<<"    "<<(*it4)->GetId()<<" "<<(*it4)->GetDuration()<<" "<<(*it4)->GetTeacher()<<endl;
        }
    } 
    
    list<TimeSlot*>::iterator it5 = ctrl->getSchedule()->GetTimeSlotList()->begin();
    list<TimeSlot*>::const_iterator MaxList5 = ctrl->getSchedule()->GetTimeSlotList()->end();
    for(;it5 != MaxList5; it5++){
        Date *d = (*it5)->GetStartDate();
        cout<<d->GetDay()<<"/"<<d->GetMonth()<<"/"<<d->GetYear()<<" "<<d->GetHour()<<":"<<d->GetMin()
                <<" "<<(*it5)->GetClassroom()->GetId()<<" "<<(*it5)->GetClassPeriod()->GetTeacher()<<endl;
    } 
    
}



>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9

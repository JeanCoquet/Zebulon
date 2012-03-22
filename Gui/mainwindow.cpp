#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>


void MainWindow::addGroupToComboBox(){
    list<Group*>* l = this->ctrl->getSchedule()->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        ui->comboBoxGroup->addItem((*it)->GetId().c_str());
    }
}

void MainWindow::addModuleToComboBox(){
    list<Module*>* l = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator it = l->begin();
    list<Module*>::const_iterator MaxList = l->end();
    bool loaded = false;
    string s;
    for(;it != MaxList; it++){
        s = "";
        s.append((*it)->GetId().c_str());
        s.append(" : ");
        s.append((*it)->GetName().c_str());
        ui->comboBoxModule->addItem(s.c_str());
        windowEditTimeSlot->getWidget().comboBoxModule->addItem(s.c_str());
        if(!loaded){
                list<ClassPeriod*>* lcp = (*it)->GetClassPeriodList();
                list<ClassPeriod*>::iterator itCp = lcp->begin();
                list<ClassPeriod*>::const_iterator MaxListCp = lcp->end();
                for(;itCp != MaxListCp; itCp++){
                    if(dynamic_cast<TutorialClass*>(*itCp) != NULL)
                            windowEditTimeSlot->getWidget().comboBoxClassPeriod->addItem("TD");
                    else if(dynamic_cast<PracticalClass*>(*itCp) != NULL)
                            windowEditTimeSlot->getWidget().comboBoxClassPeriod->addItem("TP");
                    else if(dynamic_cast<MagistralClass*>(*itCp) != NULL)
                            windowEditTimeSlot->getWidget().comboBoxClassPeriod->addItem("CM");
                    else
                            windowEditTimeSlot->getWidget().comboBoxClassPeriod->addItem(QString::number((*itCp)->GetId()));
                    loaded = false;
                    
                }
        }
    }
    list<Classroom*>* lcr = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator itcr = lcr->begin();
    list<Classroom*>::const_iterator MaxListcr = lcr->end();
    for(;itcr != MaxListcr; itcr++){
        windowEditTimeSlot->getWidget().comboBoxClassroom->addItem((*itcr)->GetId().c_str());
    }
}

void MainWindow::addClassroomToComboBox(){
    list<Classroom*>* l = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator it = l->begin();
    list<Classroom*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        ui->comboBoxClassroom->addItem((*it)->GetId().c_str());
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this->setWindowIcon(QIcon("./zebulon.png"));
    
    QDate date = QDate::currentDate();
    ui->edt->setDate(date);
    QObject::connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(changeDate(QDate)));
    QObject::connect(ui->addTimeSlotButton, SIGNAL(clicked()), this, SLOT(openEditTimeSlot())); 
    QObject::connect(ui->commitButton, SIGNAL(clicked()), this, SLOT(commit()));
    ctrl = new Controller();
    
    windowEditTimeSlot = new WindowEditTimeSlot(this->ctrl, this);
    addGroupToComboBox();
    addModuleToComboBox();
    addClassroomToComboBox();
    
}

void MainWindow::commit(){
    cout<<"COMMIT DES DONNEES SI T AS MERDE T AS DETRUIT NOTRE BASE, :p"<<endl;
    this->ctrl->commit();
}

void MainWindow::addTimeSlot(QTimeSlot *t) {
    //ajout du nouveau time slot
    this->ui->edt->addTimeSlot(t);
    QObject::connect(t, SIGNAL(clicked(QTimeSlot*)), this, SLOT(openEditTimeSlot(QTimeSlot*)));
}

void MainWindow::removeTimeSlot(QTimeSlot *t) {
    list<TimeSlot*> *lts = this->ctrl->getSchedule()->GetTimeSlotList();
    list<TimeSlot*>::iterator it = lts->begin();
    list<TimeSlot*>::const_iterator itMax = lts->begin();
    for(;it!=itMax;it++){
        if( (*it)->GetId() == t->getId() ){
            this->ctrl->delTimeSlot((*it));
            break;
        }
    }
    this->ui->edt->removeTimeSlot(t);
}

void MainWindow::changeDate(QDate date) {
    if(ui->edt->getStartDate() > date || date > ui->edt->getEndDate()){
        ui->edt->setDate(date);
        ui->edt->removeAllTimeSlots();
        QDate qd = this->ui->edt->getStartDate();
        Date d(qd.day(), qd.month(), qd.year(), 0, 0);
        
        QDate qde = this->ui->edt->getEndDate();
        Date de(qde.day(), qde.month(), qde.year(), 23, 59);
        
        list<TimeSlot*>::iterator it = ctrl->getSchedule()->GetTimeSlotList()->begin();
        list<TimeSlot*> ::const_iterator itMax = ctrl->getSchedule()->GetTimeSlotList()->end();
        for(; it!=itMax; it++) {
            Date *dit = (*it)->GetStartDate();
            //cout<<dit<<" "<<d<<" "<<de<<endl;
            if(*dit >= d && *dit <= de ) {
                QDate qdts = QDate(dit->GetYear(), dit->GetMonth(), dit->GetDay());
                
                QString nameCP;
                ClassPeriod *cp = (*it)->GetClassPeriod();
                if(dynamic_cast<TutorialClass*>(cp) != NULL)
                        nameCP = "TD "+QString::number(cp->GetId());
                else if(dynamic_cast<PracticalClass*>(cp) != NULL)
                        nameCP = "TP "+QString::number(cp->GetId());
                else if(dynamic_cast<MagistralClass*>(cp) != NULL)
                        nameCP = "CM "+QString::number(cp->GetId());
                
                QTimeSlot* time = new QTimeSlot((*it)->GetId(), qdts, dit->GetHour(), dit->GetMin(), cp->GetDuration(),
                     nameCP, QString::fromStdString((*it)->GetClassroom()->GetId()), QString::fromStdString((cp->GetMomo()->GetId()+" : "+cp->GetMomo()->GetName())), QString::fromStdString(cp->GetTeacher()), "602", ui->edt);
                
                this->addTimeSlot(time);
                //QApplication::connect(time, SIGNAL(clicked(QTimeSlot*)), this, SLOT(openEditTimeSlot(QTimeSlot*)));
                
            }
        }
    }
    else
            ui->edt->setDate(date);

}

void MainWindow::openEditTimeSlot() { 
    windowEditTimeSlot->clearWidgetContent();
    windowEditTimeSlot->getWidget().calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate());
    windowEditTimeSlot->show();
}

void MainWindow::openEditTimeSlot(QTimeSlot* timeSlot) {   
    windowEditTimeSlot->clearWidgetContent(); 
    windowEditTimeSlot->getWidget().calendarWidget->setSelectedDate(timeSlot->getDate());
    windowEditTimeSlot->getWidget().durationVal->setText(QString::number(timeSlot->getDuration()));
    
    QTime time;
    time.setHMS(timeSlot->getHour(), timeSlot->getMinute(), 0, 0);
    windowEditTimeSlot->getWidget().timeEdit->setTime(time);
    
    QComboBox* combo = windowEditTimeSlot->getWidget().comboBoxClassroom;
    combo->setCurrentIndex(combo->findText(timeSlot->getClassRoom())); 
    
    combo = windowEditTimeSlot->getWidget().comboBoxModule;
    combo->setCurrentIndex(combo->findText(timeSlot->getModule()));
    
    windowEditTimeSlot->changeModule(windowEditTimeSlot->getWidget().comboBoxModule->currentIndex());
    
    combo = windowEditTimeSlot->getWidget().comboBoxClassPeriod;
    combo->setCurrentIndex(combo->findText(timeSlot->getClassPeriod()));
    
    windowEditTimeSlot->setCurrentTimeSlot(timeSlot);
    windowEditTimeSlot->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

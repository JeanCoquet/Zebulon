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
                    ostringstream oss;
                    oss<<(*itCp)->GetId();
                    windowEditTimeSlot->getWidget().comboBoxClassPeriod->addItem(oss.str().c_str());
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
    QDate date = QDate::currentDate();
    ui->edt->setDate(date);
    QObject::connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(changeDate(QDate)));
    QObject::connect(ui->addTimeSlotButton, SIGNAL(clicked()), this, SLOT(openEditTimeSlot())); 
    ctrl = new Controller();
    windowEditTimeSlot = new WindowEditTimeSlot(this->ctrl);
    addGroupToComboBox();
    addModuleToComboBox();
    addClassroomToComboBox();
    
    
}

void MainWindow::addTimeSlot() {
    /*ui->edt->addTimeSlot(ui->calendarWidget->selectedDate(), ui->timeEdit->time().hour(), ui->timeEdit->time().minute(), ui->lineEdit_2->text().toInt(),
                     "TD", "salle 008", "S32I010 Bases de donnees 2", "MEKAOUCHE, Abdelouahab", "602");*/
}

void MainWindow::removeTimeSlot() {
    //ui->edt->removeTimeSlot(ui->lineEdit->text().toInt());
}

void MainWindow::changeDate(QDate date) {
    ui->edt->setDate(date);
}

void MainWindow::openEditTimeSlot() {
    
    windowEditTimeSlot->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

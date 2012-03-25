/*
 * File:   WindowEditTimeSlot.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#include "WindowEditTimeSlot.h"
//#include "ui_mainwindow.h"
#include <sstream>

WindowEditTimeSlot::WindowEditTimeSlot(Controller* ctrl, MainWindow* m) {
    this->ctrl = ctrl;
    this->m = m;
    this->setModal(true);
    widget.setupUi(this);
    QObject::connect(this->widget.comboBoxModule, SIGNAL(currentIndexChanged(int)), this, SLOT(changeModule(int)));
    QObject::connect(this->widget.comboBoxClassPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeClassPeriod(int)));
    QObject::connect(this->widget.buttonBox, SIGNAL(accepted()), this, SLOT(timeSlotAccepted()));
    QObject::connect(this->widget.deleteTimeSlotButton, SIGNAL(clicked()), this, SLOT(deleteTimeSlotButtonAction()));
    this->widget.listGroups->setEnabled(false);
    this->currentTimeSlot = NULL;
}

void WindowEditTimeSlot::deleteTimeSlotButtonAction(){
    if(this->currentTimeSlot != NULL){
        this->m->removeTimeSlot(currentTimeSlot);
        this->currentTimeSlot = NULL;
    }
    this->setVisible(false);
}

void WindowEditTimeSlot::changeModule(int){
    int index = this->widget.comboBoxModule->currentIndex();
    list<Module*>* l = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator it = l->begin();
    for(int i = 0 ; i < index ; i++){
        it++;
    }
    list<ClassPeriod*>* lcp = (*it)->GetClassPeriodList();
    list<ClassPeriod*>::iterator itCp = lcp->begin();
    list<ClassPeriod*>::const_iterator MaxListCp = lcp->end();
    this->widget.comboBoxClassPeriod->clear();
    for(;itCp != MaxListCp; itCp++){ 
        if(dynamic_cast<TutorialClass*>(*itCp) != NULL)
                this->getWidget().comboBoxClassPeriod->addItem("TD "+QString::number((*itCp)->GetId()));
        else if(dynamic_cast<PracticalClass*>(*itCp) != NULL)
                this->getWidget().comboBoxClassPeriod->addItem("TP "+QString::number((*itCp)->GetId()));
        else if(dynamic_cast<MagistralClass*>(*itCp) != NULL)
                this->getWidget().comboBoxClassPeriod->addItem("CM "+QString::number((*itCp)->GetId()));
        else
                this->getWidget().comboBoxClassPeriod->addItem(QString::number((*itCp)->GetId()));
    }
}

void WindowEditTimeSlot::changeClassPeriod(int index) {
    this->widget.listGroups->clear();
    int indexModule = this->widget.comboBoxModule->currentIndex();
    list<Module*>* lm = this->ctrl->getSchedule()->GetModuleList();    
    list<Module*>::iterator itM = lm->begin();
    for( int i = 0; i < indexModule ; i++){ 
        itM++;
    }
    list<ClassPeriod*>* lcp = (*itM)->GetClassPeriodList();
    list<ClassPeriod*>::iterator itCP = lcp->begin();
    for(int i = 0 ; i < index ; i++){
        itCP++;
    }
    list<Group*> *lg = (*itCP)->GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();    
    for(;itG != itGMax ; itG++){
        this->widget.listGroups->addItem((*itG)->GetId().c_str());
    }
    cout<<"duree de la classperiod : "<<(*itCP)->GetDuration()<<endl;
    
    this->widget.durationVal->setText(QString::fromStdString(ctrl->intToStr((*itCP)->GetDuration())));
}

void WindowEditTimeSlot::timeSlotAccepted(){
    int indexModule = this->widget.comboBoxModule->currentIndex();
    int indexClassPeriod = this->widget.comboBoxClassPeriod->currentIndex();
    int indexClassroom = this->widget.comboBoxClassroom->currentIndex();
    int duration = this->widget.durationVal->text().toInt();
    int h = this->widget.timeEdit->time().hour();
    int m = this->widget.timeEdit->time().minute();
    QDate date = this->widget.calendarWidget->selectedDate();
    
    list<Module*>* lm = this->ctrl->getSchedule()->GetModuleList();    
    list<Module*>::iterator itM = lm->begin();
    for( int i = 0; i < indexModule ; i++){ 
        itM++;
    }
    
    list<ClassPeriod*>* lcp = (*itM)->GetClassPeriodList();
    list<ClassPeriod*>::iterator itCP = lcp->begin();
    for(int i = 0 ; i < indexClassPeriod ; i++){
        itCP++;
    }
    list<Classroom*>* lcr = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator itCr = lcr->begin();
    for(int i = 0 ; i < indexClassroom ; i++){
        itCr++;
    }
    
    Date *d = new Date(date.day(), date.month(), date.year(), h, m);
    
    if(duration != (*itCP)->GetDuration())
        (*itCP)->SetDuration(duration);
    
    TimeSlot *t = new TimeSlot(d, (*itCr), (*itCP));
    
    if(ctrl->addTimeSlot(t)) {
        QString nameCP;
        if(dynamic_cast<TutorialClass*>(*itCP) != NULL)
                nameCP = "TD "+QString::number((*itCP)->GetId());
        else if(dynamic_cast<PracticalClass*>(*itCP) != NULL)
                nameCP = "TP "+QString::number((*itCP)->GetId());
        else if(dynamic_cast<MagistralClass*>(*itCP) != NULL)
                nameCP = "CM "+QString::number((*itCP)->GetId());
        //QTimeSlot* time = new QTimeSlot(t->GetId(), date, h, m, duration,
        //             nameCP, QString::fromStdString((*itCr)->GetId()), QString::fromStdString(((*itM)->GetId()+" : "+(*itM)->GetName())), QString::fromStdString((*itCP)->GetTeacher()), "602", this->m->getUi()->edt);
        
        if(currentTimeSlot != NULL){
            this->m->removeTimeSlot(currentTimeSlot);
            currentTimeSlot = NULL;
            // A SUPPRIMER DANS LE CONTROLLEUR
        }
        this->m->reloadQTimeSlots();
    }
    else{
        QMessageBox::warning(this, "Oups!", "Le time SLot que vosu avez cherché à ajouter n'est pas correct!");
    }
}

void WindowEditTimeSlot::clearWidgetContent() {
    this->widget.comboBoxModule->setCurrentIndex(-1);
    this->widget.comboBoxClassPeriod->setCurrentIndex(-1);
    this->widget.comboBoxClassPeriod->clear();
    this->widget.comboBoxClassroom->setCurrentIndex(-1);
    this->widget.durationVal->clear();
    this->widget.timeEdit->setTime(QTime::fromString("08:00", "hh:ss"));
    this->widget.calendarWidget->setSelectedDate(QDate::currentDate());
    this->widget.listGroups->clear();
}

WindowEditTimeSlot::~WindowEditTimeSlot() {
}


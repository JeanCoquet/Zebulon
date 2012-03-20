/*
 * File:   WindowEditTimeSlot.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#include "WindowEditTimeSlot.h"

WindowEditTimeSlot::WindowEditTimeSlot(Controller* ctrl) {
    this->ctrl = ctrl;
    this->setModal(true);
    widget.setupUi(this);
    QObject::connect(this->widget.comboBoxModule, SIGNAL(currentIndexChanged(int)), this, SLOT(changeModule(int)));
    QObject::connect(this->widget.comboBoxClassPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeClassPeriod(int)));
    QObject::connect(this->widget.buttonBox, SIGNAL(accepted()), this, SLOT(timeSlotAccepted()));
    this->widget.listGroups->setEnabled(false);
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
}

void WindowEditTimeSlot::timeSlotAccepted(){
    int indexModule = this->widget.comboBoxModule->currentIndex();
    int indexClassPeriod = this->widget.comboBoxClassPeriod->currentIndex();
    int indexClassroom = this->widget.comboBoxClassroom->currentIndex();
    //int duration = atoi(this->widget.durationVal->text().);
    cout<<"time slot cree ou presque"<<endl;
}

void WindowEditTimeSlot::clearWidgetContent() {
    this->widget.comboBoxModule->setCurrentIndex(-1);
    this->widget.comboBoxClassPeriod->setCurrentIndex(-1);
    this->widget.comboBoxClassroom->setCurrentIndex(-1);
    this->widget.durationVal->clear();
    this->widget.timeEdit->setTime(QTime::fromString("00:00", "hh:ss"));
    this->widget.calendarWidget->setSelectedDate(QDate::currentDate());
    this->widget.listGroups->clear();
}

WindowEditTimeSlot::~WindowEditTimeSlot() {
}


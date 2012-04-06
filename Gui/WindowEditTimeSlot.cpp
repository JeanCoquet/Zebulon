/*
 * File:   WindowEditTimeSlot.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#include "WindowEditTimeSlot.h"
#include "ui_mainwindow.h"
//#include "ui_mainwindow.h"
#include <sstream>

WindowEditTimeSlot::WindowEditTimeSlot(Schedule* schedule) {
    this->setModal(true);
    this->setWindowIcon(QIcon("./zebulon.png"));
    widget.setupUi(this);
    this->schedule = schedule;
    this->widget.listGroups->setEnabled(false);
    this->currentTimeSlot = NULL;
}

void WindowEditTimeSlot::deleteTimeSlotButtonAction(){
    this->setVisible(false);
}

void WindowEditTimeSlot::changeModule(int){
    int index = this->widget.comboBoxModule->currentIndex();
    
    list<Module*>* l = schedule->GetModuleList();
    list<Module*>::iterator it = l->begin();
    for(int i = 0 ; i < index ; i++){
        it++;
    }
    list<ClassPeriod*>* lcp = (*it)->GetClassPeriodList();
    list<ClassPeriod*>::iterator itCp = lcp->begin();
    list<ClassPeriod*>::const_iterator MaxListCp = lcp->end();
    this->widget.comboBoxClassPeriod->clear();
    for(;itCp != MaxListCp; itCp++){ 
        bool ok = true;
        list<TimeSlot*>::iterator itTS = schedule->GetTimeSlotList()->begin();
        list<TimeSlot*>::const_iterator itTSMax = schedule->GetTimeSlotList()->end();
        for(; itTS != itTSMax; itTS++) {
            if((*itTS)->GetClassPeriod()->GetId() == (*itCp)->GetId()) {
                ok = false;
                if(currentTimeSlot != NULL && currentTimeSlot->getId() == (*itTS)->GetId())
                    ok = true;
            }
        }
        if(ok) {
            if(dynamic_cast<TutorialClass*>(*itCp) != NULL)
                    this->getWidget()->comboBoxClassPeriod->addItem("Tutorial "+QString::number((*itCp)->GetId()));
            else if(dynamic_cast<PracticalClass*>(*itCp) != NULL)
                    this->getWidget()->comboBoxClassPeriod->addItem("Practical "+QString::number((*itCp)->GetId()));
            else if(dynamic_cast<MagistralClass*>(*itCp) != NULL)
                    this->getWidget()->comboBoxClassPeriod->addItem("Magistral "+QString::number((*itCp)->GetId()));
            else
                    this->getWidget()->comboBoxClassPeriod->addItem(QString::number((*itCp)->GetId()));
        }
        
    }
}

void WindowEditTimeSlot::changeClassPeriod(int index) {
    this->widget.listGroups->clear();
    int indexModule = this->widget.comboBoxModule->currentIndex();
    list<Module*>* lm = schedule->GetModuleList();    
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
    this->widget.durationVal->setText(QString::number((*itCP)->GetDuration()));
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


/*
 * File:   WindowEditTimeSlot.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 10:31
 */

#include "WindowEditTimeSlot.h"

WindowEditTimeSlot::WindowEditTimeSlot(Controller* ctrl) {
    cout<<"bleu violace"<<endl;
    this->ctrl = ctrl;
    this->setModal(true);
    widget.setupUi(this);
    QObject::connect(this->widget.comboBoxModule, SIGNAL(currentIndexChanged(int)), this, SLOT(changeModule(int)));
    QObject::connect(this->widget.buttonBox, SIGNAL(accepted()), this, SLOT(timeSlotAccepted()));
    cout<<"fin constructeur edit time slot"<<endl;
}

void WindowEditTimeSlot::changeModule(int){
    cout<<"rouge fonce"<<endl;
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
        this->getWidget().comboBoxClassPeriod->addItem(QString::number((*itCp)->GetId()));
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
}

WindowEditTimeSlot::~WindowEditTimeSlot() {
}


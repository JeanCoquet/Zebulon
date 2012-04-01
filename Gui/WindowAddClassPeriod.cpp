/*
 * File:   WindowAddClassPeriod.cpp
 * Author: jean
 *
 * Created on 1 avril 2012, 02:26
 */

#include <qt4/QtGui/qpictureformatplugin.h>
#include <qt4/QtGui/qstandarditemmodel.h>

#include "WindowAddClassPeriod.h"

WindowAddClassPeriod::WindowAddClassPeriod(Controller* c, WindowEditTimeSlot* w) {
    widget.setupUi(this);
    this->setModal(true); 
    this->ctrl = c;
    this->windowE = w;
    module = NULL; 
    listIndexGroup = new QList<int>;
    
    QObject::connect(widget.buttonAddGroup, SIGNAL(clicked()), this, SLOT(addGroup()));
    QObject::connect(widget.buttonDeleteGroup, SIGNAL(clicked()), this, SLOT(deleteGroup()));
    QObject::connect(this->widget.buttonBox, SIGNAL(accepted()), this, SLOT(addClassPeriod()));
}

void WindowAddClassPeriod::addClassPeriod() {
    int indexType = widget.comboBoxType->currentIndex();
    if(widget.lineEditDuration->text().toInt() > 15 && widget.lineEditTeacher->text() != "" && indexType != -1) {
        ClassPeriod *classPeriod;
        if(indexType == 0)
            classPeriod = new MagistralClass(widget.lineEditTeacher->text().toStdString(), widget.lineEditDuration->text().toInt(), module);
        else if(indexType == 1)
            classPeriod = new TutorialClass(widget.lineEditTeacher->text().toStdString(), widget.lineEditDuration->text().toInt(), module);
        else if(indexType == 2)
            classPeriod = new PracticalClass(widget.lineEditTeacher->text().toStdString(), widget.lineEditDuration->text().toInt(), module);
        else
            classPeriod = new ClassPeriod(widget.lineEditTeacher->text().toStdString(), widget.lineEditDuration->text().toInt(), module);
        
        QList<int>::iterator it = listIndexGroup->begin();
        QList<int>::const_iterator itMax = listIndexGroup->end();
        for(; it!=itMax; it++) {
            list<Group*> *lg = this->ctrl->getSchedule()->GetGroupList();
            list<Group*>::iterator itG = lg->begin();
            for(int i = 0 ; i < (*it) ; i++){
                itG++;
            }
            classPeriod->GetGroupList()->push_back((*itG));
        }
        ctrl->addClassPeriod(classPeriod, module);
        
        windowE->changeModule(windowE->getWidget().comboBoxModule->currentIndex());
        int indexT = windowE->getWidget().comboBoxClassPeriod->findText(widget.comboBoxType->currentText()+" "+QString::number(classPeriod->GetId()));
        windowE->getWidget().comboBoxClassPeriod->setCurrentIndex(indexT);
    }
    clearChildrenContent();
}

void WindowAddClassPeriod::addGroup() {
    if(listIndexGroup->indexOf(widget.comboBoxGroup->currentIndex()) == -1) {
        listIndexGroup->push_back(widget.comboBoxGroup->currentIndex());
        widget.listWidgetGroups->addItem(widget.comboBoxGroup->currentText());
    }
}

void WindowAddClassPeriod::deleteGroup() {
    int index = widget.comboBoxGroup->findText(widget.listWidgetGroups->currentItem()->text());
    listIndexGroup->removeAt(listIndexGroup->indexOf(index));
    delete widget.listWidgetGroups->currentItem();
}

void WindowAddClassPeriod::setIndexModule(int index) {
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    for(int i = 0 ; i < index ; i++){
        itM++;
    }
    module = (*itM);
    string s = (*itM)->GetId().c_str();
    s.append(" : ");
    s.append((*itM)->GetName().c_str());
    widget.lineEditModule->setText(s.c_str());
}

void WindowAddClassPeriod::clearChildrenContent() {
    widget.lineEditDuration->setText("");
    widget.lineEditModule->setText("");
    widget.lineEditTeacher->setText("");
    widget.listWidgetGroups->clear();
    widget.comboBoxType->setCurrentIndex(-1);
    listIndexGroup->clear();
}

WindowAddClassPeriod::~WindowAddClassPeriod() {
    delete listIndexGroup;
}

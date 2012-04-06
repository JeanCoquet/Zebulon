/*
 * File:   ZebulonWindow.cpp
 * Author: bicodul
 *
 * Created on April 6, 2012, 4:06 AM
 */

#include "ZebulonWindow.h"

ZebulonWindow::ZebulonWindow(Schedule *schedule) : windowEditTimeSlot(schedule), windowAdministrator(schedule){
    widget.setupUi(this);
    
    this->schedule = schedule;
    
    this->setWindowIcon(QIcon("./zebulon.png"));
    this->widget.commitButton->setIcon(QIcon("./Check-icon.png"));
    this->widget.dockWidget->setTitleBarWidget(new QWidget(0));
    
    QDate date = QDate::currentDate();
    widget.edt->setDate(date);
    
}

void ZebulonWindow::reloadGroups(){
    widget.comboBoxGroup->clear();
    list<Group*>* l = this->schedule->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        widget.comboBoxGroup->addItem((*it)->GetId().c_str());
    }
}

void ZebulonWindow::reloadModules(){
    windowEditTimeSlot.getWidget()->comboBoxModule->clear();
    //windowEditTimeSlot.getWidget()->comboBoxClassroom->clear();
    list<Module*>* l = this->schedule->GetModuleList();
    list<Module*>::iterator it = l->begin();
    list<Module*>::const_iterator MaxList = l->end();
    bool loaded = false;
    string s;
    for(;it != MaxList; it++){
        s = "";
        s.append((*it)->GetId().c_str());
        s.append(" : ");
        s.append((*it)->GetName().c_str());
        windowEditTimeSlot.getWidget()->comboBoxModule->addItem(s.c_str());
    }
}

void ZebulonWindow::reloadClassrooms(){
    widget.comboBoxClassroom->clear();
    windowEditTimeSlot.getWidget()->comboBoxClassroom->clear();
    list<Classroom*>* l = this->schedule->GetClassroomList();
    list<Classroom*>::iterator it = l->begin();
    list<Classroom*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        widget.comboBoxClassroom->addItem((*it)->GetId().c_str());
        windowEditTimeSlot.getWidget()->comboBoxClassroom->addItem((*it)->GetId().c_str());
    }
}

void ZebulonWindow::reloadStudents(){
    widget.comboBoxStudent->clear();
    list<Group*>* lg = this->schedule->GetGroupList();
    list<Group*>::iterator it = lg->begin();
    list<Group*>::const_iterator MaxList = lg->end();
    string s;
    for(;it != MaxList; it++){
        list<Student*>::iterator itS = (*it)->GetStudentList()->begin();
        list<Student*>::const_iterator MaxListS = (*it)->GetStudentList()->end();
        for(;itS != MaxListS; itS++){
            s = "";
            s.append((*itS)->GetFirstname().c_str());
            s.append(" ");
            s.append((*itS)->GetLastname().c_str());
            widget.comboBoxStudent->addItem(s.c_str());
        }
    }
}

void ZebulonWindow::changeDate(QDate date) {
    
    if(widget.edt->getStartDate() > date || date > widget.edt->getEndDate()){
        widget.edt->setDate(date);
        reloadQTimeSlots();
    }    
   else
       widget.edt->setDate(date);

}
    
void ZebulonWindow::reloadQTimeSlots(){
        widget.edt->removeAllTimeSlots();
        QDate qd = this->widget.edt->getStartDate();
        Date d(qd.day(), qd.month(), qd.year(), 0, 0);
        
        QDate qde = this->widget.edt->getEndDate();
        Date de(qde.day(), qde.month(), qde.year(), 23, 59);
        
        list<TimeSlot*>::iterator it = schedule->GetTimeSlotList()->begin();
        list<TimeSlot*> ::const_iterator itMax = schedule->GetTimeSlotList()->end();
        for(; it!=itMax; it++) {
            
            Date *dit = (*it)->GetStartDate();
            
            if(*dit >= d && *dit <= de ) {
                
                int currentIndex = this->widget.tabWidget->currentIndex();
                if(currentIndex == 0){
                    int indexGroup = this->widget.comboBoxGroup->currentIndex();
                    list<Group*> *lg = schedule->GetGroupList();
                    list<Group*>::iterator itG = lg->begin();
                    for(int i = 0 ; i < indexGroup ; i++){
                        itG++;
                    }
                    list<Group*> *lgl = (*it)->GetClassPeriod()->GetGroupList();
                    list<Group*>::iterator itGL = lgl->begin();
                    list<Group*>::const_iterator itGLMax = lgl->end();
                    for(;itGL != itGLMax ; itGL++){
                        if((*itG) == (*itGL)){
                            genererQTimeSlot((*it));
                            break;
                        }
                    }
                }
                else if(currentIndex == 1){
                    int indexCR = this->widget.comboBoxClassroom->currentIndex();
                    list<Classroom*> *lcr = schedule->GetClassroomList();
                    list<Classroom*>::iterator itCR = lcr->begin();
                    for(int i = 0 ; i < indexCR ; i++){
                        itCR++;
                    }
                    if((*it)->GetClassroom() == (*itCR)){
                        genererQTimeSlot((*it));
                    }
                }
                else if(currentIndex == 2){
                    QString stringNameStudent = this->widget.comboBoxStudent->currentText();
                    list<Group*>* lg = (*it)->GetClassPeriod()->GetGroupList();
                    list<Group*>::iterator itg = lg->begin();
                    list<Group*>::const_iterator itgMax = lg->end();
                    for(; itg!=itgMax; itg++) {
                        if(findStudentInGroup((*itg), stringNameStudent.toStdString())) {
                            genererQTimeSlot((*it));
                            break;
                        }
                    }
                }
            }
                
        }    
                    cout << "YAAAUHk fin " << endl;
}


bool ZebulonWindow::findStudentInGroup(Group* g, string name) {
    string s;
    list<Student*>::iterator itS = g->GetStudentList()->begin();
    list<Student*>::const_iterator MaxListS = g->GetStudentList()->end();
    for(;itS != MaxListS; itS++){
        s = "";
        s.append((*itS)->GetFirstname().c_str());
        s.append(" ");
        s.append((*itS)->GetLastname().c_str());
        if(s == name) {
            return true;
        }
    }
    
    bool result = false;
    list<Group*>* lg = g->GetGroupList();
    if(lg != NULL) {
        list<Group*>::iterator itg = lg->begin();
        list<Group*>::const_iterator itgMax = lg->end();

        for(; itg!=itgMax; itg++) {
            result = result || findStudentInGroup((*itg), name);
        }
    }
    return result;
}

void ZebulonWindow::genererQTimeSlot(TimeSlot* t){
    QString nameCP, color;
    ClassPeriod *cp = t->GetClassPeriod();
    if(dynamic_cast<TutorialClass*>(cp) != NULL) {
            nameCP = "Tutorial "+QString::number(cp->GetId());
            color = "navy";
            if(!widget.checkBoxTutorial->isChecked()) return;
    }
    else if(dynamic_cast<PracticalClass*>(cp) != NULL) {
            nameCP = "Practical "+QString::number(cp->GetId());
            color = "green";
            if(!widget.checkBoxPractical->isChecked()) return;
    }
    else if(dynamic_cast<MagistralClass*>(cp) != NULL) {
            nameCP = "Magistral "+QString::number(cp->GetId());
            color = "maroon";
            if(!widget.checkBoxMagistral->isChecked()) return;
    }
    
    Date *dit = t->GetStartDate();
    QDate qdts = QDate(dit->GetYear(), dit->GetMonth(), dit->GetDay());

    QString stringGroups = "";
    list<Group*>* l = t->GetClassPeriod()->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        stringGroups.append(QString::fromStdString((*it)->GetId()));
        stringGroups.append(";");
    }
    
    
    QTimeSlot* time = new QTimeSlot(t->GetId(), qdts, dit->GetHour(), dit->GetMin(), cp->GetDuration(),
            nameCP, QString::fromStdString(t->GetClassroom()->GetId()), QString::fromStdString((cp->GetMomo()->GetId()+" : "+cp->GetMomo()->GetName())), QString::fromStdString(cp->GetTeacher()), stringGroups, NULL);
    time->setBackgroundColor(color);
    this->widget.edt->addTimeSlot(time);
    emit signal_addTimeSlot(time);
}

void ZebulonWindow::openEditTimeSlot() { 
    windowEditTimeSlot.clearWidgetContent();
    windowEditTimeSlot.getWidget()->calendarWidget->setSelectedDate(widget.calendarWidget->selectedDate());
    windowEditTimeSlot.show();
}

void ZebulonWindow::openEditTimeSlot(QTimeSlot* timeSlot) {   
    windowEditTimeSlot.clearWidgetContent(); 
    windowEditTimeSlot.getWidget()->calendarWidget->setSelectedDate(timeSlot->getDate());
    windowEditTimeSlot.getWidget()->durationVal->setText(QString::number(timeSlot->getDuration()));
    
    windowEditTimeSlot.setCurrentTimeSlot(timeSlot);
    
    QTime time;
    time.setHMS(timeSlot->getHour(), timeSlot->getMinute(), 0, 0);
    windowEditTimeSlot.getWidget()->timeEdit->setTime(time);
    
    QComboBox* combo = windowEditTimeSlot.getWidget()->comboBoxClassroom;
    combo->setCurrentIndex(combo->findText(timeSlot->getClassRoom())); 
    
    combo = windowEditTimeSlot.getWidget()->comboBoxModule;
    combo->setCurrentIndex(combo->findText(timeSlot->getModule()));
    
    windowEditTimeSlot.changeModule(windowEditTimeSlot.getWidget()->comboBoxModule->currentIndex());
    
    combo = windowEditTimeSlot.getWidget()->comboBoxClassPeriod;
    cout << timeSlot->getClassPeriod().toStdString() <<endl;
    combo->setCurrentIndex(combo->findText(timeSlot->getClassPeriod()));
    
    windowEditTimeSlot.show();
}

void ZebulonWindow::reloadAll(){
    reloadClassrooms();
    reloadGroups();
    reloadStudents();
    reloadModules();
    reloadQTimeSlots();
}

void ZebulonWindow::openAdministrator() {
    windowAdministrator.show();
}
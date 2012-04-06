/*
 * File:   WindowAdministrator.cpp
 * Author: moi (et lui)
 *
 * Created on 29 mars 2012, 12:32
 */

#include "WindowAdministrator.h"

WindowAdministrator::WindowAdministrator(Schedule *schedule) {
    load = false;

    groupClassPeriodModified = false;
    groupGroupModified = false;
    widget.setupUi(this);
    this->schedule = schedule;
    this->setModal(true);
    this->setWindowIcon(QIcon("./zebulon.png"));
    
    this->widget.tableWidgetModules->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetModules->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassrooms->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassrooms->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetGroups->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetGroups->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ;    
    this->widget.tableWidgetStudents->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetStudents->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ;
    
    oldIdSelectedModule = "";
    refreshModule(1);
    refreshClassroom(1);
    refreshGroup(1);
    currentModule = NULL;
}

void WindowAdministrator::refreshGroup(int newState) {
    cout << "Traitement Etat : "<<newState<<endl;
    this->groupState = newState;
    load = true;
    switch(newState){
        case 1 :
            currentGroup = NULL;
            currentStudent = NULL;
            widget.tableWidgetStudents->setEnabled(false);
            widget.frameEditGroup->setVisible(false);
            widget.frameEditStudent->setVisible(false);
            widget.buttonAddGroup->setEnabled(true);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.lineEditIdGroup->setText("");
            widget.listWidgetChildrenGroup->clear();
            displayGroups();
            displayStudents();
            break;
        case 2 :
            setCurrentGroup();
            currentStudent = NULL;
            widget.tableWidgetGroups->setEnabled(true);
            widget.tableWidgetStudents->setEnabled(true);
            widget.frameEditGroup->setVisible(false);
            widget.frameEditStudent->setVisible(false);
            widget.buttonAddGroup->setEnabled(true);
            widget.buttonEditGroup->setEnabled(true);
            widget.buttonDeleteGroup->setEnabled(true);
            widget.buttonAddStudent->setEnabled(true);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.lineEditIdGroup->setText("");
            widget.listWidgetChildrenGroup->clear();
            widget.lineEditGroupStudent->setText("");
            widget.lineEditIdStudent->setText("");
            widget.lineEditFirstNameStudent->setText("");
            widget.lineEditLastNameStudent->setText("");
            widget.lineEditAddressStudent->setText("");
            widget.lineEditEmailStudent->setText("");
            displayGroups();
            displayStudents();
            break;
        case 3 :
            setCurrentStudent();
            widget.tableWidgetGroups->setEnabled(true);
            widget.tableWidgetStudents->setEnabled(true);
            widget.frameEditGroup->setVisible(false);
            widget.frameEditStudent->setVisible(false);
            widget.buttonAddGroup->setEnabled(true);
            widget.buttonEditGroup->setEnabled(true);
            widget.buttonDeleteGroup->setEnabled(true);
            widget.buttonAddStudent->setEnabled(true);
            widget.buttonEditStudent->setEnabled(true);
            widget.buttonDeleteStudent->setEnabled(true);
            displayStudents();
            widget.lineEditIdGroup->setText("");
            widget.listWidgetChildrenGroup->clear();
            widget.lineEditGroupStudent->setText("");
            widget.lineEditIdStudent->setText("");
            widget.lineEditFirstNameStudent->setText("");
            widget.lineEditLastNameStudent->setText("");
            widget.lineEditAddressStudent->setText("");
            widget.lineEditEmailStudent->setText("");
            break;
        case 41 :
            widget.frameEditGroup->setVisible(true);
            widget.tableWidgetGroups->setEnabled(false);
            widget.tableWidgetStudents->setEnabled(false);
            widget.buttonAddGroup->setEnabled(false);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.listWidgetChildrenGroup->clear();
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            loadGroupsGroup();
            break;
        case 411 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.listWidgetChildrenGroup->setCurrentRow(-1);
            break;
        case 412 :
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            break;
        case 413 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            break;
        case 42 :
            widget.frameEditGroup->setVisible(true);
            widget.tableWidgetGroups->setEnabled(false);
            widget.tableWidgetStudents->setEnabled(false);
            widget.buttonAddGroup->setEnabled(false);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            if(currentGroup == NULL){
            }else{
                widget.lineEditIdGroup->setText(currentGroup->GetId().c_str());
            }
            loadGroupsGroup();
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            break;
        case 421 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.listWidgetChildrenGroup->setCurrentRow(-1);
            break;
        case 422 :
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            break;
        case 423 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            break;
        case 43 :
            widget.frameEditGroup->setVisible(true);
            widget.tableWidgetGroups->setEnabled(false);
            widget.tableWidgetStudents->setEnabled(false);
            widget.buttonAddGroup->setEnabled(false);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            if(currentGroup == NULL){
                
            }else{
                widget.lineEditIdGroup->setText(currentGroup->GetId().c_str());
            }
            loadGroupsGroup();     
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            break;
        case 431 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.listWidgetChildrenGroup->setCurrentRow(-1);
            break;
        case 432 :
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            widget.comboBoxChildrenGroup->setCurrentIndex(-1);
            break;
        case 433 :
            widget.buttonAddChildrenGroup->setEnabled(true);
            widget.buttonDeleteChildrenGroup->setEnabled(true);
            break;
        case 51 :
            widget.frameEditStudent->setVisible(true);
            widget.tableWidgetGroups->setEnabled(false);
            widget.tableWidgetStudents->setEnabled(false);
            widget.buttonAddGroup->setEnabled(false);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.lineEditGroupStudent->setText(currentGroup->GetId().c_str());
            break;
        case 52 :
            widget.frameEditStudent->setVisible(true);
            widget.tableWidgetGroups->setEnabled(false);
            widget.tableWidgetStudents->setEnabled(false);
            widget.buttonAddGroup->setEnabled(false);
            widget.buttonEditGroup->setEnabled(false);
            widget.buttonDeleteGroup->setEnabled(false);
            widget.buttonAddStudent->setEnabled(false);
            widget.buttonEditStudent->setEnabled(false);
            widget.buttonDeleteStudent->setEnabled(false);
            widget.buttonAddChildrenGroup->setEnabled(false);
            widget.buttonDeleteChildrenGroup->setEnabled(false);
            widget.lineEditGroupStudent->setText(currentGroup->GetId().c_str());
            if(currentStudent != NULL){   
                widget.lineEditIdStudent->setText(currentStudent->GetId().c_str());
                widget.lineEditFirstNameStudent->setText(currentStudent->GetFirstname().c_str());
                widget.lineEditLastNameStudent->setText(currentStudent->GetLastname().c_str());
                widget.lineEditAddressStudent->setText(currentStudent->GetAddr().c_str());
                widget.lineEditEmailStudent->setText(currentStudent->GetEmail().c_str());
            }
            break;
    }
    load = false;
    cout << "Fin Traitement Etat : "<<newState<<endl;
}
void WindowAdministrator::groupClicked() {
    refreshGroup(2);
}
void WindowAdministrator::addGroup() {
    if(groupState == 1){
        refreshGroup(41);
    }else if(groupState == 2){
        refreshGroup(42);
    }else{
        refreshGroup(43);
    }
}

void WindowAdministrator::editGroup() {
    if(groupState == 2){
        refreshGroup(42);
    }else{
        refreshGroup(43);
    }
}

void WindowAdministrator::deleteGroup() {
    refreshGroup(1);
}
void WindowAdministrator::okEditGroup() {
    refreshGroup(2);
}
void WindowAdministrator::cancelEditGroup() {
    if(groupState == 41){
        refreshGroup(1);
    }else if(groupState == 42){
        refreshGroup(2);
    }else{
        refreshGroup(3);
    }
}

void WindowAdministrator::addGroupGroup() {    
    if(groupState == 421){
        refreshGroup(42);
    }else if(groupState == 423){
        refreshGroup(42);
    }else if(groupState == 411){
        refreshGroup(41);
    }else if(groupState == 413){
        refreshGroup(41);
    }else if(groupState == 431){
        refreshGroup(43);
    }else if(groupState == 433){
        refreshGroup(43);
    }
}
void WindowAdministrator::deleteGroupGroup() {
    if(groupState == 413){
        refreshGroup(411);
    }else if(groupState == 412){
        refreshGroup(41);
    }else if(groupState == 423){
        refreshGroup(421);
    }else if(groupState == 422){
        refreshGroup(42);
    }else if(groupState == 433){
        refreshGroup(431);
    }else {
        refreshGroup(43);
    }
}
void WindowAdministrator::comboBoxGroupsGroupChanged(int index) {
    if(!load){
        if(groupState == 41){
            refreshGroup(411);
        }else if(groupState == 412){
            refreshGroup(413);
        }else if(groupState == 42){
            refreshGroup(421);
        }else if(groupState == 422){
            refreshGroup(423);
        }else if(groupState == 43){
            refreshGroup(431);
        }else {
            refreshGroup(433);
        }
    }
}
void WindowAdministrator::listGroupGroupClicked() { 
    if(!load){
        if(groupState == 41){
            refreshGroup(412);
        }else if(groupState == 411){
            refreshGroup(413);
        }else if(groupState == 42){
            refreshGroup(422);
        }else if(groupState == 421){
            refreshGroup(423);
        }else if(groupState == 43){
            refreshGroup(432);
        }else {
            refreshGroup(433);
        }
    }
}
void WindowAdministrator::studentClicked() { 
    refreshGroup(3);
}
void WindowAdministrator::addStudent() {
    if(groupState == 2) {
        refreshGroup(51);
    }else
        refreshGroup(52);
}

void WindowAdministrator::editStudent() {
    refreshGroup(52);
}

void WindowAdministrator::deleteStudent() {
    refreshGroup(2);
}
void WindowAdministrator::okEditStudent() { 
    widget.tableWidgetStudents->setCurrentCell(-1,0);
    refreshGroup(3);
}

void WindowAdministrator::cancelEditStudent() {
    if(groupState == 51) {
        refreshGroup(2);
    }else
        refreshGroup(3);
}

void WindowAdministrator::displayGroups() {
    QTableWidget *table = widget.tableWidgetGroups;    
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    QTableWidgetItem *item;
    
    list<Group*>* l = schedule->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        int nbRow = table->rowCount();
        table->insertRow(nbRow);
        item = new QTableWidgetItem((*it)->GetId().c_str());
        table->setItem(nbRow, 0, item);
        string s = "";
        if((*it)->GetGroupList() != NULL){
            list<Group*>::iterator itG = (*it)->GetGroupList()->begin();
            list<Group*>::const_iterator GMaxList = (*it)->GetGroupList()->end();
            for(; itG!=GMaxList; itG++) {
                s.append((*itG)->GetId());
                s.append(";");
            }
        }
        item = new QTableWidgetItem(s.c_str());
        table->setItem(nbRow, 1, item);
        
        if(currentGroup != NULL){
            if((*it)->GetId() == currentGroup->GetId()){
                table->setCurrentItem(item);
            }
        }
    }
}
void WindowAdministrator::displayStudents(){
    if(currentGroup != NULL){
        list<Student*> *ls = currentGroup->GetStudentList();
        list<Student*>::iterator itS = ls->begin();
        list<Student*>::const_iterator itSMax = ls->end();
        QTableWidget* tw = this->widget.tableWidgetStudents;
        while(tw->rowCount() != 0) {
            tw->removeRow(tw->rowCount()-1);
        }
        for(; itS != itSMax ; itS++){
            int nbRow = tw->rowCount();
            tw->insertRow(nbRow);
            tw->setItem(nbRow, 0, new QTableWidgetItem((*itS)->GetId().c_str()));
            tw->setItem(nbRow, 1, new QTableWidgetItem((*itS)->GetLastname().c_str()));
            tw->setItem(nbRow, 2, new QTableWidgetItem((*itS)->GetFirstname().c_str()));
            tw->setItem(nbRow, 3, new QTableWidgetItem((*itS)->GetAddr().c_str()));
            QTableWidgetItem *item = new QTableWidgetItem((*itS)->GetEmail().c_str());
            tw->setItem(nbRow, 4, item);

            if(currentStudent != NULL){
                if((*itS)->GetId() == currentStudent->GetId()){
                    tw->setCurrentItem(item);
                }
            }
        }
    }
}

void WindowAdministrator::loadGroupsGroup() { 
    widget.listWidgetChildrenGroup->clear();
    widget.comboBoxChildrenGroup->clear();
    list<Group*>* l = schedule->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    int count =  tempGroupListGroup.count();
    for(;it != MaxList; it++){
        bool test = false;
        if(currentGroup != NULL && currentGroup->GetGroupList() != NULL){
            list<Group*>::iterator itG = currentGroup->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = currentGroup->GetGroupList()->end();
            for(; itG!= itGMax; itG++) {
                if((*itG)->GetId() == (*it)->GetId()){
                    if(!groupGroupModified && count == 0){
                        tempGroupListGroup.push_back(QString::fromStdString((*itG)->GetId()));
                        test = true;
                    }
                    break;
                }
            }
        }
        
        if(!test && tempGroupListGroup.indexOf(QString::fromStdString((*it)->GetId())) == -1 && currentGroup != (*it)){
            widget.comboBoxChildrenGroup->addItem((*it)->GetId().c_str());
        }
        
    }
    int indexRowGroupG = widget.listWidgetChildrenGroup->currentRow();
    widget.listWidgetChildrenGroup->clear();
    widget.listWidgetChildrenGroup->addItems(tempGroupListGroup);
    widget.listWidgetChildrenGroup->setCurrentRow(indexRowGroupG);
    widget.comboBoxChildrenGroup->setCurrentIndex(-1);
}
void WindowAdministrator::setCurrentGroup() {
    if(widget.tableWidgetGroups->currentRow() != -1) {
        QList<QTableWidgetItem*>::iterator itGroup = this->widget.tableWidgetGroups->selectedItems().begin();
        list<Group*> *lg = schedule->GetGroupList();
        list<Group*>::iterator itG = lg->begin();
        list<Group*>::const_iterator itGMax = lg->end();
        for(; itG != itGMax ; itG++ ){
            if((*itG)->GetId() == (*itGroup)->text().toStdString()){
                break;
            }
        }
    
        currentGroup = (*itG);
    }
}
void WindowAdministrator::setCurrentStudent() { 
    if(widget.tableWidgetStudents->currentRow() != -1) {
        QList<QTableWidgetItem*>::iterator itStudent = this->widget.tableWidgetStudents->selectedItems().begin();
        list<Student*> *ls = currentGroup->GetStudentList();
        list<Student*>::iterator itS = ls->begin();
        list<Student*>::const_iterator itSMax = ls->end();
        for(; itS != itSMax ; itS++ ){
            if((*itS)->GetId() == (*itStudent)->text().toStdString()){
                break;
            }
        }
    
        currentStudent = (*itS);
    }
}

void WindowAdministrator::moduleClicked(){
    refreshModule(2);
}

void WindowAdministrator::classperiodClicked() {
    refreshModule(3);
}

void WindowAdministrator::comboBoxGroupsClassPeriodChanged(int index){
    if(!load){
        if(moduleState == 51){
            refreshModule(511);
        }else if(moduleState == 52){
            refreshModule(521);
        }else if(moduleState == 522){
            refreshModule(523);
        }else if(moduleState == 512){
            refreshModule(513);
        }
    }
}

void WindowAdministrator::listGroupClassPeriodClicked(){
    if(!load){
        if(moduleState == 52){
            refreshModule(522);
        }else if(moduleState == 521){
            refreshModule(523);
        }else if(moduleState == 51){
            refreshModule(512);
        }else if(moduleState == 511){
            refreshModule(513);
        }
    }
}

void WindowAdministrator::setCurrentModule(){
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = schedule->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }

    currentModule = (*itM);
}

void WindowAdministrator::setCurrentClassPeriod(){
    if(widget.tableWidgetClassPeriod->currentRow() != -1 && currentClassPeriod == NULL){
        QList<QTableWidgetItem*>::iterator itClassPeriod = widget.tableWidgetClassPeriod->selectedItems().begin();
        list<ClassPeriod*>::iterator itCP = currentModule->GetClassPeriodList()->begin();
        list<ClassPeriod*>::const_iterator itCPMax = currentModule->GetClassPeriodList()->end();
        for(; itCP!=itCPMax; itCP++){
            if((*itCP)->GetId() == (*itClassPeriod)->text().toInt()) {
                break;
            }
        }
        currentClassPeriod = (*itCP);
    }
}

void WindowAdministrator::loadGroupsClassPeriod(){
    widget.comboBoxGroupClassPeriod->clear();
    list<Group*>* l = schedule->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    int count =  tempGroupListClassPeriod.count();
    for(;it != MaxList; it++){
        bool test = false;
        if(currentClassPeriod != NULL){
            list<Group*>::iterator itG = currentClassPeriod->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = currentClassPeriod->GetGroupList()->end();
            for(; itG!= itGMax; itG++) {
                if((*itG)->GetId() == (*it)->GetId()){
                    if(!groupClassPeriodModified && count == 0){
                        tempGroupListClassPeriod.push_back(QString::fromStdString((*itG)->GetId()));
                        test = true;
                    }
                    break;
                }
            }
        }
        
        
        if(!test && tempGroupListClassPeriod.indexOf(QString::fromStdString((*it)->GetId())) == -1){
            widget.comboBoxGroupClassPeriod->addItem((*it)->GetId().c_str());
        }
        
    }
    int indexRowGroupCP = widget.listWidgetGroupClassPeriod->currentRow();
    widget.listWidgetGroupClassPeriod->clear();
    widget.listWidgetGroupClassPeriod->addItems(tempGroupListClassPeriod);
    widget.listWidgetGroupClassPeriod->setCurrentRow(indexRowGroupCP);
    widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
}

void WindowAdministrator::setCurrentClassroom(){
    if(widget.tableWidgetClassrooms->currentRow() != -1) {
        QList<QTableWidgetItem*>::iterator itClassroom = widget.tableWidgetClassrooms->selectedItems().begin();

        list<Classroom*> *lc = schedule->GetClassroomList();
        list<Classroom*>::iterator itC = lc->begin();
        list<Classroom*>::const_iterator itCMax = lc->end();
        for(;itC != itCMax ; itC++){
            if((*itC)->GetId() == (*itClassroom)->text().toStdString())
                break;
        }

        currentClassroom = (*itC);
    }
}

void WindowAdministrator::displaySpecificityClassroom() {
    widget.labelNumberComputers->setVisible(false);
    widget.lineEditNumberComputers->setVisible(false);
    widget.checkBoxSpecificity->setVisible(false);
    if(widget.comboBoxClassRoom->currentText().toStdString() == "Practical Classroom") {
        widget.labelNumberComputers->setVisible(true);
        widget.lineEditNumberComputers->setVisible(true);
    }
    else if(widget.comboBoxClassRoom->currentText().toStdString() == "Tutorial Classroom") {
        widget.checkBoxSpecificity->setVisible(true);
    }
    else if(widget.comboBoxClassRoom->currentText().toStdString() == "Lecture Hall") {
        widget.checkBoxSpecificity->setVisible(true);
    }
}

void WindowAdministrator::refreshClassroom(int newState){
    this->classroomState = newState;
    switch(newState){
        case 1 :
            currentClassroom = NULL;
            widget.tableWidgetClassrooms->setEnabled(true);
            widget.frameClassroom->setVisible(false);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(false);
            widget.buttonDeleteClassroom->setEnabled(false); 
            displayClassroom();
            break;
        case 2 :
            widget.tableWidgetClassrooms->setEnabled(true);
            widget.frameClassroom->setVisible(false);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(true);
            widget.buttonDeleteClassroom->setEnabled(true);
            setCurrentClassroom();
            displayClassroom();
            break;
        case 31 :
            widget.tableWidgetClassrooms->setEnabled(false);
            widget.frameClassroom->setVisible(true);
            widget.buttonAddClassroom->setEnabled(false);
            widget.buttonEditClassroom->setEnabled(false);
            widget.buttonDeleteClassroom->setEnabled(false);
            widget.lineEditIdClassroom->setText("");
            widget.lineEditCapacityClassroom->setText("");
            widget.comboBoxClassRoom->setCurrentIndex(-1); 
            displaySpecificityClassroom();
            break;
        case 32 :
            widget.tableWidgetClassrooms->setEnabled(false);
            widget.frameClassroom->setVisible(true);
            widget.buttonAddClassroom->setEnabled(false);
            widget.buttonEditClassroom->setEnabled(false);
            widget.buttonDeleteClassroom->setEnabled(false);
            if(currentClassroom != NULL) {
                widget.lineEditIdClassroom->setText(currentClassroom->GetId().c_str());
                widget.lineEditCapacityClassroom->setText(QString::number(currentClassroom->GetCapacity()));
                if(dynamic_cast<TutorialClassroom*>(currentClassroom) != NULL) 
                    widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Tutorial Classroom"));
                else if(dynamic_cast<PracticalClassroom*>(currentClassroom) != NULL)
                    widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Practical Classroom"));
                else if(dynamic_cast<LectureHall*>(currentClassroom) != NULL)
                    widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Lecture Hall"));
                else
                    widget.comboBoxClassRoom->setCurrentIndex(-1);
            }
            else  {
                widget.lineEditIdClassroom->setText("");
                widget.lineEditCapacityClassroom->setText("");
                widget.comboBoxClassRoom->setCurrentIndex(-1); 
            }
            displaySpecificityClassroom();   
            break;
    }
}

void WindowAdministrator::comboBoxTypeClassroomChanged() {
    displaySpecificityClassroom();
}

void WindowAdministrator::classroomClicked() {
    refreshClassroom(2);
}
void WindowAdministrator::addClassroom() {
    if(classroomState == 1)
        refreshClassroom(31);
    else
        refreshClassroom(32);
}
void WindowAdministrator::editClassroom() {
    refreshClassroom(32);
}
void WindowAdministrator::deleteClassroom() {
    refreshClassroom(1);
}

void WindowAdministrator::okEditClassroom() { 
    refreshClassroom(2);
}
void WindowAdministrator::cancelEditClassroom() {
    if(classroomState == 31)
        refreshClassroom(1);
    else
        refreshClassroom(2);
}

void WindowAdministrator::refreshModule(int newState) {
    this->moduleState = newState;
    load = true;
    switch(this->moduleState){
        case 1 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            displayModule();
            currentModule = NULL;
            displayClassPeriod();
            break;
        case 2 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(true);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(true);
            widget.buttonDeleteModule->setEnabled(true);
            widget.buttonAddClassPeriod->setEnabled(true);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            widget.lineEditModule->setText("");
            widget.comboBoxTypeClassPeriod->setCurrentIndex(-1);
            widget.lineEditTeacherClassPeriod->setText("");
            widget.lineEditDurationClassPeriod->setText("");
            widget.listWidgetGroupClassPeriod->clear();
            if(oldIdSelectedModule == "")
                oldIdSelectedModule = (*(widget.tableWidgetModules->selectedItems().begin()))->text().toStdString();
            
            currentClassPeriod = NULL;
            displayModule();
            displayClassPeriod();
            setCurrentModule();
            break;
        case 3 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(true);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(true);
            widget.buttonDeleteModule->setEnabled(true);
            widget.buttonAddClassPeriod->setEnabled(true);
            widget.buttonEditClassPeriod->setEnabled(true);
            widget.buttonDeleteClassPeriod->setEnabled(true);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            widget.lineEditModule->setText("");
            widget.comboBoxTypeClassPeriod->setCurrentIndex(-1);
            widget.lineEditTeacherClassPeriod->setText("");
            widget.lineEditDurationClassPeriod->setText("");
            widget.listWidgetGroupClassPeriod->clear();
            
            setCurrentModule();
            setCurrentClassPeriod();
            displayClassPeriod();
            
            
            break;
        case 41 :
            widget.tableWidgetModules->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false);
            break;
        case 42 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);  
            if(currentModule != NULL){
                widget.lineEditIdModule->setText(currentModule->GetId().c_str());
                widget.lineEditNameModule->setText(currentModule->GetName().c_str());
                widget.lineEditTheHeadModule->setText(currentModule->GetTheHead().c_str()); 
            }
            break;
        case 43 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);  
            if(currentModule != NULL){
                widget.lineEditIdModule->setText(currentModule->GetId().c_str());
                widget.lineEditNameModule->setText(currentModule->GetName().c_str());
                widget.lineEditTheHeadModule->setText(currentModule->GetTheHead().c_str()); 
            }
            break;
        case 51 :
            widget.tableWidgetModules->setEnabled(false);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);            
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            widget.frameEditClassPeriod->setVisible(true);
            widget.lineEditModule->setText(currentModule->GetId().c_str());
            
            loadGroupsClassPeriod();
            
            break;
        case 511 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            break;
        case 512 :
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);      
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            break;
        case 513 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);
            break;
        case 52 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditClassPeriod->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);  
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.lineEditModule->setText(currentModule->GetId().c_str());
            if(currentClassPeriod != NULL){
                 widget.lineEditDurationClassPeriod->setText(QString::number(currentClassPeriod->GetDuration()));
                widget.lineEditTeacherClassPeriod->setText(currentClassPeriod->GetTeacher().c_str()); 
                widget.lineEditModule->setText(currentModule->GetId().c_str()); 

                int indexCP;
                if(dynamic_cast<TutorialClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Tutorial");
                else if(dynamic_cast<PracticalClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Practical");
                else if(dynamic_cast<MagistralClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Magistral");
                else indexCP = -1;

                widget.comboBoxTypeClassPeriod->setCurrentIndex(indexCP);
            }
            loadGroupsClassPeriod();
            break;
        case 521 :
            widget.buttonAddGroupClassPeriod->setEnabled(true); 
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);          
            break;
        case 522 :
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);      
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            loadGroupsClassPeriod();
            break;
        case 523 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);
            break;
    }
    load = false;
}

void WindowAdministrator::displayClassroom(){
    QTableWidget *table = widget.tableWidgetClassrooms;    
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    list<Classroom*> *lc = schedule->GetClassroomList();
    list<Classroom*>::iterator itC = lc->begin();
    list<Classroom*>::const_iterator itCMax = lc->end();
    QTableWidget *twc = this->widget.tableWidgetClassrooms;
    for(;itC != itCMax ; itC++){
        int nbrow = twc->rowCount();
        twc->insertRow(nbrow);
        QTableWidgetItem *item = new QTableWidgetItem((*itC)->GetId().c_str());
        twc->setItem(nbrow, 0, item);
        twc->setItem(nbrow, 1, new QTableWidgetItem(QString::number((*itC)->GetCapacity())));
        QString specificity = "", type = ""; 
        if(dynamic_cast<TutorialClassroom*>(*itC) != NULL) {
            type = "Tutorial Classroom";
            if(((TutorialClassroom*)(*itC))->IsVideoprojector())
                specificity = "projector available";
            else specificity = "no projector";
        }
        else if(dynamic_cast<PracticalClassroom*>(*itC) != NULL){
            type = "Practical Classroom";
            specificity = QString::number(((PracticalClassroom*)(*itC))->GetElementsNumber())+" computers";
        }
        else if(dynamic_cast<LectureHall*>(*itC) != NULL){
            type = "Lecture Hall";
            if(((LectureHall*)(*itC))->IsVideoconferencing()){
                specificity = "video conferencing is possible";
            } else{
                specificity = "";
            }
        }
        twc->setItem(nbrow, 2, new QTableWidgetItem(type));
        twc->setItem(nbrow, 3, new QTableWidgetItem(specificity));
        if(currentClassroom != NULL){
            if((*itC)->GetId() == currentClassroom->GetId()){
                twc->setCurrentItem(item);
            }
        }
    }
}

void WindowAdministrator::addModule() {
    if(moduleState == 1) {
        refreshModule(41);
    }else if(moduleState == 2){
        refreshModule(42);
    }else{
        refreshModule(43);
    }
    
}
void WindowAdministrator::editModule() { 
    if(moduleState == 2){
        refreshModule(42);
    }else{
        refreshModule(43);
    }    
}

void WindowAdministrator::okEditModule() {
    if(moduleState == 41 || moduleState == 42){
        refreshModule(2);
    }else{
        refreshModule(3);
    }
}

void WindowAdministrator::cancelEditModule() {    
    if(moduleState == 41){
        refreshModule(1);
    } else if (moduleState == 42){
        refreshModule(2);
    } else{
        refreshModule(3);
    }
}
void WindowAdministrator::deleteModule() {
    refreshModule(1);
}
void WindowAdministrator::displayModule() {
    QTableWidget *table = widget.tableWidgetModules;    
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    QTableWidgetItem *item;
    
    list<Module*>* l = schedule->GetModuleList();
    list<Module*>::iterator it = l->begin();
    list<Module*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        item = new QTableWidgetItem((*it)->GetId().c_str());
        int nbRow = table->rowCount();
        table->insertRow(nbRow);
        table->setItem(nbRow, 0, item);
        item = new QTableWidgetItem((*it)->GetName().c_str());
        table->setItem(nbRow, 1, item);
        item = new QTableWidgetItem((*it)->GetTheHead().c_str());
        table->setItem(nbRow, 2, item);
        
        if((*it)->GetId() == oldIdSelectedModule) {
            table->setCurrentItem(item);
            oldIdSelectedModule = "";
            currentModule = (*it);
        }
    }
}

void WindowAdministrator::displayClassPeriod() {
    QTableWidget *table = widget.tableWidgetClassPeriod;
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    if(widget.tableWidgetModules->currentRow() != -1) {

        string type, groups = "";
        QTableWidgetItem *item;

        list<ClassPeriod*>* lcp = currentModule->GetClassPeriodList();
        list<ClassPeriod*>::iterator itCp = lcp->begin();
        list<ClassPeriod*>::const_iterator MaxListCp = lcp->end();
        for(;itCp != MaxListCp; itCp++){
            if(dynamic_cast<TutorialClass*>(*itCp) != NULL) type = "Tutorial";
            else if(dynamic_cast<PracticalClass*>(*itCp) != NULL) type = "Practical";
            else if(dynamic_cast<MagistralClass*>(*itCp) != NULL) type = "Magistral";
            else type = "";

            item = new QTableWidgetItem(QString::number((*itCp)->GetId()));
            int nbRow = table->rowCount();
            table->insertRow(nbRow);
            table->setItem(nbRow, 0, item);

            item = new QTableWidgetItem(type.c_str());
            table->setItem(nbRow, 1, item);

            item = new QTableWidgetItem((*itCp)->GetTeacher().c_str());
            table->setItem(nbRow, 2, item);

            item = new QTableWidgetItem(QString::number((*itCp)->GetDuration()));
            table->setItem(nbRow, 3, item);

            groups = "";
            list<Group*>::iterator itG = (*itCp)->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = (*itCp)->GetGroupList()->end();
            for(; itG!= itGMax; itG++) {
                groups.append((*itG)->GetId());
                groups.append(";");
            }

            item = new QTableWidgetItem(groups.c_str());
            table->setItem(nbRow, 4, item);
            
            if(currentClassPeriod != NULL){
                
                if((*itCp)->GetId() == currentClassPeriod->GetId()) {
                    table->setCurrentItem(item);
                }
                //widget.tableWidgetClassPeriod->setCurrentItem(*(widget.tableWidgetClassPeriod->findItems(QString::number(currentClassPeriod->GetId()), Qt::MatchCaseSensitive).begin()));
       
            }

        }
    }
}
void WindowAdministrator::addClassPeriod() {
    if(moduleState == 2)
        refreshModule(51);
    else
        refreshModule(52);
}
void WindowAdministrator::editClassPeriod() {
    refreshModule(52);   
}
void WindowAdministrator::deleteClassPeriod() {
    refreshModule(2);
}
void WindowAdministrator::addGroupClassPeriod() {
   if(moduleState == 521){
        refreshModule(52);
    }else if(moduleState == 523){
        refreshModule(52);
    }else if(moduleState == 511){
        refreshModule(51);
    }else if(moduleState == 513){
        refreshModule(51);
    }

    
}
void WindowAdministrator::deleteGroupClassPeriod() {
    if(moduleState == 522){
        refreshModule(52);
    }else if(moduleState == 523){
        refreshModule(521);
    }else if(moduleState == 512){
        refreshModule(51);
    }else if(moduleState == 513){
        refreshModule(511);
    }
}
void WindowAdministrator::okEditClassPeriod() {
    refreshModule(3);
}
void WindowAdministrator::cancelEditClassPeriod() {
    if(moduleState == 51){
        refreshModule(2);
    }else{
        refreshModule(3);
    }
}
WindowAdministrator::~WindowAdministrator() {
    
}


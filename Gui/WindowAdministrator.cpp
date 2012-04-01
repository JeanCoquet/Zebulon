/*
 * File:   WindowAdministrator.cpp
 * Author: E110091P
 *
 * Created on 29 mars 2012, 12:32
 */

#include "WindowAdministrator.h"

WindowAdministrator::WindowAdministrator(Controller* ctrl, MainWindow* mainwindow) {
    widget.setupUi(this);
    this->ctrl = ctrl;
    this->m = mainwindow;
    this->setModal(true);
    this->setWindowIcon(QIcon("./zebulon.png"));
    
    this->widget.tableWidgetModules->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetModules->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassrooms->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassrooms->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetStudents->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetStudents->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    
    this->widget.frameEditModule->setVisible(false);
    this->widget.frameEditClassPeriod->setVisible(false);
    
    currentModule = NULL;
    
    QObject::connect(widget.buttonAddModule, SIGNAL(clicked()), this, SLOT(addModule()));
    QObject::connect(widget.buttonEditModule, SIGNAL(clicked()), this, SLOT(editModule()));
    QObject::connect(widget.buttonDeleteModule, SIGNAL(clicked()), this, SLOT(deleteModule()));
    QObject::connect(widget.buttonOkEditModule, SIGNAL(clicked()), this, SLOT(okEditModule()));
    QObject::connect(widget.buttonCancelEditModule, SIGNAL(clicked()), this, SLOT(cancelEditModule()));
    QObject::connect(widget.tableWidgetModules, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(displayClassPeriod()));
    QObject::connect(widget.buttonAddClassPeriod, SIGNAL(clicked()), this, SLOT(addClassPeriod()));
    QObject::connect(widget.buttonEditClassPeriod, SIGNAL(clicked()), this, SLOT(editClassPeriod()));
    QObject::connect(widget.buttonDeleteClassPeriod, SIGNAL(clicked()), this, SLOT(deleteClassPeriod()));
    QObject::connect(widget.buttonAddGroupClassPeriod, SIGNAL(clicked()), this, SLOT(addGroupClassPeriod()));
    QObject::connect(widget.buttonDeleteGroupClassPeriod, SIGNAL(clicked()), this, SLOT(deleteGroupClassPeriod()));
    QObject::connect(widget.listWidgetGroups, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayStudents()));
    displayClassroom();    
    
}

void WindowAdministrator::displayClassroom(){
    list<Classroom*> *lc = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator itC = lc->begin();
    list<Classroom*>::const_iterator itCMax = lc->end();
    QTableWidget *twc = this->widget.tableWidgetClassrooms;
    for(;itC != itCMax ; itC++){
        int nbrow = twc->rowCount();
        twc->insertRow(nbrow);
        twc->setItem(nbrow, 0, new QTableWidgetItem((*itC)->GetId().c_str()));
        twc->setItem(nbrow, 1, new QTableWidgetItem(QString::number((*itC)->GetCapacity())));
        string specificity = "";
        if(dynamic_cast<TutorialClassroom*>(*itC) != NULL) {
            if(((TutorialClassroom*)(*itC))->IsVideoprojector())
                specificity = "projector available";
            else specificity = "no projector";
        }
        else if(dynamic_cast<PracticalClassroom*>(*itC) != NULL){
            
        }
        else if(dynamic_cast<LectureHall*>(*itC) != NULL){
            if(((LectureHall*)(*itC))->IsVideoconferencing()){
                specificity = "video conferencing is possible";
            } else{
                specificity = "";
            }
        }
        twc->setItem(nbrow, 2, new QTableWidgetItem(specificity.c_str()));
    }
}

void WindowAdministrator::addModule() {
    currentModule = NULL;
    this->widget.frameEditModule->setVisible(true);
}
void WindowAdministrator::editModule() {    
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }
    
    currentModule = (*itM);

    widget.frameEditModule->setVisible(true);
    widget.lineEditIdModule->setText(currentModule->GetId().c_str());
    widget.lineEditNameModule->setText(currentModule->GetName().c_str());
    widget.lineEditTheHeadModule->setText(currentModule->GetTheHead().c_str()); 
}

void WindowAdministrator::okEditModule() {
    if(currentModule != NULL)
        ctrl->delModule(currentModule);
    
    Module* mod = new Module(widget.lineEditIdModule->text().toStdString(), widget.lineEditNameModule->text().toStdString(), widget.lineEditTheHeadModule->text().toStdString());
    ctrl->addModule(mod);
    
    widget.frameEditModule->setVisible(false);
    widget.lineEditIdModule->setText("");
    widget.lineEditNameModule->setText("");
    widget.lineEditTheHeadModule->setText("");
    currentModule = NULL;
    
    m->addModuleToComboBox();
}

void WindowAdministrator::cancelEditModule() {
    widget.frameEditModule->setVisible(false);
    widget.lineEditIdModule->setText("");
    widget.lineEditNameModule->setText("");
    widget.lineEditTheHeadModule->setText("");
    currentModule = NULL;
}

void WindowAdministrator::deleteModule() {
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }
    ctrl->delModule(*itM);
    m->addModuleToComboBox();
}

void WindowAdministrator::displayStudents(){
    cout<<"groupe clique"<<endl;
//    QList<QListWidgetItem*>::iterator  itGroup = lwibegin();
    QList<QListWidgetItem*>::iterator itGroup = this->widget.listWidgetGroups->selectedItems().begin();
    list<Group*> *lg = this->ctrl->getSchedule()->GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();
    for(; itG != itGMax ; itG++ ){
        if((*itG)->GetId() == (*itGroup)->text().toStdString()){
            break;
        }
    }
    list<Student*> *ls = (*itG)->GetStudentList();
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
        tw->setItem(nbRow, 4, new QTableWidgetItem((*itS)->GetEmail().c_str()));
    }
}

void WindowAdministrator::displayClassPeriod() {
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }
    
    currentModule = (*itM);
    
    QTableWidget *table = widget.tableWidgetClassPeriod;
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
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
        
    }
}

void WindowAdministrator::addClassPeriod() {
    currentClassPeriod = NULL;
    this->widget.frameEditClassPeriod->setVisible(true);
}
void WindowAdministrator::editClassPeriod() {
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }
    Module *mod = (*itM);
    
    QList<QTableWidgetItem*>::iterator itClassPeriod = widget.tableWidgetClassPeriod->selectedItems().begin();
    list<ClassPeriod*>::iterator itCP = mod->GetClassPeriodList()->begin();
    list<ClassPeriod*>::const_iterator itCPMax = mod->GetClassPeriodList()->end();
    for(; itCP!=itCPMax; itCP++){
        if((*itCP)->GetId() == (*itClassPeriod)->text().toInt()) {
            break;
        }
    }
    currentClassPeriod = (*itCP);
    
    
    
    widget.frameEditClassPeriod->setVisible(true);
    widget.lineEditDurationClassPeriod->setText(QString::number(currentClassPeriod->GetDuration()));
    widget.lineEditTeacherClassPeriod->setText(QString::number(currentClassPeriod->GetDuration())); 
    widget.lineEditModule->setText(mod->GetId().c_str()); 
    
    int indexCP;
    if(dynamic_cast<TutorialClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Tutorial");
    else if(dynamic_cast<PracticalClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Practical");
    else if(dynamic_cast<MagistralClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Magistral");
    else indexCP = -1;
    
    widget.comboBoxTypeClassPeriod->setCurrentIndex(indexCP);
    
    list<Group*>::iterator itG = currentClassPeriod->GetGroupList()->begin();
    list<Group*>::const_iterator itGMax = currentClassPeriod->GetGroupList()->end();
    for(; itG!= itGMax; itG++) {
       widget.listWidgetGroupClassPeriod->addItem((*itG)->GetId().c_str());
    }
    
}
void WindowAdministrator::deleteClassPeriod() {
    
}
void WindowAdministrator::addGroupClassPeriod() {
    
}
void WindowAdministrator::deleteGroupClassPeriod() {
    
}

WindowAdministrator::~WindowAdministrator() {

}


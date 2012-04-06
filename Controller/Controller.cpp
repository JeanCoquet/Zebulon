/* 
 * File:   Controller.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 8:34 PM
 */

#include "Controller.h"

Controller::Controller() throw(int) {
    cout<<"Creation du cerveau de Zebulon..."<<endl;
    loadSchedule();
    
    window = new ZebulonWindow(&schedule);
    connectMainWindow();
    connectWindowAdministrator();
    connectWindowEditTimeSlot();
    
    window->reloadAll();
    
    window->show();  
}

void Controller::connectMainWindow(){
    QObject::connect(window->getWidget()->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(changeDate(QDate)));
    QObject::connect(window->getWidget()->addTimeSlotButton, SIGNAL(clicked()), this, SLOT(openEditTimeSlot())); 
    QObject::connect(window->getWidget()->commitButton, SIGNAL(clicked()), this, SLOT(commit()));
    QObject::connect(window->getWidget()->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->comboBoxClassroom, SIGNAL(currentIndexChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->comboBoxGroup, SIGNAL(currentIndexChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->comboBoxStudent, SIGNAL(currentIndexChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->actionAdministrator, SIGNAL(triggered()), this, SLOT(openAdministrator()));
    QObject::connect(window->getWidget()->checkBoxMagistral, SIGNAL(stateChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->checkBoxTutorial, SIGNAL(stateChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window->getWidget()->checkBoxPractical, SIGNAL(stateChanged(int)), this, SLOT(tabIndexChanged()));
    QObject::connect(window, SIGNAL(signal_addTimeSlot(QTimeSlot*)), this, SLOT(addQTimeSlot(QTimeSlot*)));
}

void Controller::connectWindowAdministrator() {
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddModule, SIGNAL(clicked()), this, SLOT(admin_addModule()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonEditModule, SIGNAL(clicked()), this, SLOT(admin_editModule()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteModule, SIGNAL(clicked()), this, SLOT(admin_deleteModule()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonOkEditModule, SIGNAL(clicked()), this, SLOT(admin_okEditModule()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonCancelEditModule, SIGNAL(clicked()), this, SLOT(admin_cancelEditModule()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->tableWidgetModules, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(admin_moduleClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->tableWidgetClassPeriod, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(admin_classperiodClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddClassPeriod, SIGNAL(clicked()), this, SLOT(admin_addClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonEditClassPeriod, SIGNAL(clicked()), this, SLOT(admin_editClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteClassPeriod, SIGNAL(clicked()), this, SLOT(admin_deleteClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonOkEditClassPeriod, SIGNAL(clicked()), this, SLOT(admin_okEditClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonCancelEditClassPeriod, SIGNAL(clicked()), this, SLOT(admin_cancelEditClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddGroupClassPeriod, SIGNAL(clicked()), this, SLOT(admin_addGroupClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteGroupClassPeriod, SIGNAL(clicked()), this, SLOT(admin_deleteGroupClassPeriod()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->comboBoxGroupClassPeriod, SIGNAL(currentIndexChanged (int)), this, SLOT(admin_comboBoxGroupsClassPeriodChanged(int)));
    QObject::connect(window->getWindowAdministrator()->getWidget()->listWidgetGroupClassPeriod, SIGNAL(currentRowChanged (int)), this, SLOT(admin_listGroupClassPeriodClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->tableWidgetClassrooms, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(admin_classroomClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonClose, SIGNAL(clicked()), this, SLOT(admin_close())); 
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddClassroom, SIGNAL(clicked()), this, SLOT(admin_addClassroom()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonEditClassroom, SIGNAL(clicked()), this, SLOT(admin_editClassroom()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteClassroom, SIGNAL(clicked()), this, SLOT(admin_deleteClassroom()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonOkEditClassroom, SIGNAL(clicked()), this, SLOT(admin_okEditClassroom()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonCancelEditClassroom, SIGNAL(clicked()), this, SLOT(admin_cancelEditClassroom()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->comboBoxClassRoom, SIGNAL(currentIndexChanged (int)), this, SLOT(admin_comboBoxTypeClassroomChanged()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->tableWidgetGroups, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(admin_groupClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->tableWidgetStudents, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(admin_studentClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddGroup, SIGNAL(clicked()), this, SLOT(admin_addGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonEditGroup, SIGNAL(clicked()), this, SLOT(admin_editGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteGroup, SIGNAL(clicked()), this, SLOT(admin_deleteGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->comboBoxChildrenGroup, SIGNAL(currentIndexChanged (int)), this, SLOT(admin_comboBoxGroupsGroupChanged(int)));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddChildrenGroup, SIGNAL(clicked()), this, SLOT(admin_addGroupGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->listWidgetChildrenGroup, SIGNAL(currentRowChanged (int)), this, SLOT(admin_listGroupGroupClicked()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteChildrenGroup, SIGNAL(clicked()), this, SLOT(admin_deleteGroupGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonOkEditGroup, SIGNAL(clicked()), this, SLOT(admin_okEditGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonCancelEditGroup, SIGNAL(clicked()), this, SLOT(admin_cancelEditGroup()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonAddStudent, SIGNAL(clicked()), this, SLOT(admin_addStudent()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonEditStudent, SIGNAL(clicked()), this, SLOT(admin_editStudent()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonDeleteStudent, SIGNAL(clicked()), this, SLOT(admin_deleteStudent()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonOkEditStudent, SIGNAL(clicked()), this, SLOT(admin_okEditStudent()));
    QObject::connect(window->getWindowAdministrator()->getWidget()->buttonCancelStudent, SIGNAL(clicked()), this, SLOT(admin_cancelEditStudent()));
}

void Controller::connectWindowEditTimeSlot() {
    QObject::connect(window->getWindowEditTimeSlot()->getWidget()->comboBoxModule, SIGNAL(currentIndexChanged(int)), this, SLOT(editTimeSlot_changeModule(int)));
    QObject::connect(window->getWindowEditTimeSlot()->getWidget()->comboBoxClassPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(editTimeSlot_changeClassPeriod(int)));
    QObject::connect(window->getWindowEditTimeSlot()->getWidget()->buttonBox, SIGNAL(accepted()), this, SLOT(editTimeSlot_timeSlotAccepted()));
    QObject::connect(window->getWindowEditTimeSlot()->getWidget()->deleteTimeSlotButton, SIGNAL(clicked()), this, SLOT(editTimeSlot_deleteTimeSlotButtonAction()));
}

void Controller::editTimeSlot_deleteTimeSlotButtonAction() {
    if(window->getWindowEditTimeSlot()->getCurrentTimeSlot() != NULL) {
        removeTimeSlot(window->getWindowEditTimeSlot()->getCurrentTimeSlot());
        window->getWindowEditTimeSlot()->setCurrentTimeSlot(NULL);
    }
    window->getWindowEditTimeSlot()->deleteTimeSlotButtonAction();
}

void Controller::editTimeSlot_changeModule(int i ){
    window->getWindowEditTimeSlot()->changeModule( i);
}

void Controller::editTimeSlot_changeClassPeriod(int index) {
    window->getWindowEditTimeSlot()->changeClassPeriod(index);
}

void Controller::editTimeSlot_timeSlotAccepted(){
    int indexModule = window->getWindowEditTimeSlot()->getWidget()->comboBoxModule->currentIndex();
    
    string idClassPeriod = this->window->getWindowEditTimeSlot()->getWidget()->comboBoxClassPeriod->currentText().toStdString();
    idClassPeriod = idClassPeriod.substr(idClassPeriod.find(" ")+1, idClassPeriod.size() - idClassPeriod.find(" ") - 1);
    
    int indexClassroom = this->window->getWindowEditTimeSlot()->getWidget()->comboBoxClassroom->currentIndex();
    int duration = this->window->getWindowEditTimeSlot()->getWidget()->durationVal->text().toInt();
    int h = this->window->getWindowEditTimeSlot()->getWidget()->timeEdit->time().hour();
    int m = this->window->getWindowEditTimeSlot()->getWidget()->timeEdit->time().minute();
    QDate date = this->window->getWindowEditTimeSlot()->getWidget()->calendarWidget->selectedDate();
    
    list<Module*>* lm = schedule.GetModuleList();    
    list<Module*>::iterator itM = lm->begin();   
    for( int i = 0; i < indexModule ; i++){ 
        itM++;
    }
    
    list<ClassPeriod*>* lcp = (*itM)->GetClassPeriodList();
    list<ClassPeriod*>::iterator itCP = lcp->begin();
    list<ClassPeriod*>::const_iterator itCPMax = lcp->end();
    for(int i = 0 ; itCP != itCPMax; itCP++){
         if((*itCP)->GetId() == strToInt(idClassPeriod))
            break;
    }
    
    list<Classroom*>* lcr = schedule.GetClassroomList();
    list<Classroom*>::iterator itCr = lcr->begin();
    for(int i = 0 ; i < indexClassroom ; i++){
        itCr++;
    }
    
    Date *d = new Date(date.day(), date.month(), date.year(), h, m);
    
    if(duration != (*itCP)->GetDuration())
        (*itCP)->SetDuration(duration);
    
    TimeSlot *t = new TimeSlot(d, (*itCr), (*itCP));
    cout << "Zebulon essaye d'ajouter votre Time slot... Bonne chance !" <<endl;
    if(addTimeSlot(t)) {
       if(window->getWindowEditTimeSlot()->getCurrentTimeSlot() != NULL){
            //window->removeTimeSlot(window->getWindowEditTimeSlot()->getCurrentTimeSlot());
            window->getWindowEditTimeSlot()->setCurrentTimeSlot(NULL);
            
        }
        window->getWidget()->calendarWidget->setSelectedDate(date);
        window->reloadQTimeSlots();
    }
    else{
        QMessageBox::warning(window->getWindowEditTimeSlot(), "Oups!", "No, no you can't do that. We are sorry but if we allow this we will be punish :( !");
    }
}

void Controller::admin_groupClicked() { window->getWindowAdministrator()->groupClicked(); }
void Controller::admin_addGroup() { 
    window->getWindowAdministrator()->setCurrentGroup(NULL);
    window->getWindowAdministrator()->addGroup(); 
}
void Controller::admin_editGroup() { window->getWindowAdministrator()->editGroup(); }
void Controller::admin_deleteGroup() {
    delGroup(window->getWindowAdministrator()->getCurrentGroup());
    window->getWindowAdministrator()->deleteGroup();
}
void Controller::admin_okEditGroup() {
    window->getWindowAdministrator()->setGroupGroupModified(false);
    list<Group*>* lGNew = new list<Group*>();
    list<Group*> *lg = schedule.GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();
    for( ; itG != itGMax ; itG++){
        if(window->getWindowAdministrator()->getWidget()->listWidgetChildrenGroup->findItems(QString::fromStdString((*itG)->GetId()), Qt::MatchCaseSensitive).size() != 0 ){
            lGNew->push_back((*itG));
        }
    }
    window->getWindowAdministrator()->getTempGroupListGroup()->clear();
    if(window->getWindowAdministrator()->getCurrentGroup() != NULL){
        setGroup(window->getWindowAdministrator()->getCurrentGroup(), window->getWindowAdministrator()->getWidget()->lineEditIdGroup->text().toStdString(), lGNew);
    }
    else{
        Group* group = new Group(window->getWindowAdministrator()->getWidget()->lineEditIdGroup->text().toStdString(), lGNew);
        addGroup(group);
        window->getWindowAdministrator()->setCurrentGroup(group);
    }
    window->getWindowAdministrator()->okEditGroup();
}
void Controller::admin_cancelEditGroup() {
    window->getWindowAdministrator()->cancelEditGroup();
}
void Controller::admin_addGroupGroup() {
    window->getWindowAdministrator()->setGroupGroupModified(true);
    window->getWindowAdministrator()->getTempGroupListGroup()->push_back(window->getWindowAdministrator()->getWidget()->comboBoxChildrenGroup->currentText());
    window->getWindowAdministrator()->addGroupGroup();
}
void Controller::admin_deleteGroupGroup() {
    window->getWindowAdministrator()->setGroupGroupModified(true);
    window->getWindowAdministrator()->getTempGroupListGroup()->removeOne(window->getWindowAdministrator()->getWidget()->listWidgetChildrenGroup->currentItem()->text());
    window->getWindowAdministrator()->deleteGroupGroup();
}
void Controller::admin_comboBoxGroupsGroupChanged(int index) {
    window->getWindowAdministrator()->comboBoxGroupsGroupChanged(index);
}
void Controller::admin_listGroupGroupClicked() { 
    window->getWindowAdministrator()->listGroupGroupClicked();
}
void Controller::admin_studentClicked() { 
    window->getWindowAdministrator()->studentClicked();
}
void Controller::admin_addStudent() {
    window->getWindowAdministrator()->setCurrentStudent(NULL);
    window->getWindowAdministrator()->addStudent();
}
void Controller::admin_close(){
    window->reloadAll();
    window->getWindowAdministrator()->close();
}
void Controller::admin_editStudent() {
    window->getWindowAdministrator()->editStudent();
}
void Controller::admin_deleteStudent() {
    delStudent(window->getWindowAdministrator()->getCurrentStudent(), window->getWindowAdministrator()->getCurrentGroup());
    window->getWindowAdministrator()->deleteStudent();
}
void Controller::admin_okEditStudent() {
    if(window->getWindowAdministrator()->getCurrentStudent() != NULL) {
        setStudent(window->getWindowAdministrator()->getCurrentStudent(), window->getWindowAdministrator()->getCurrentGroup(), window->getWindowAdministrator()->getWidget()->lineEditIdStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditLastNameStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditFirstNameStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditAddressStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditEmailStudent->text().toStdString());
    }
    else {
        Student *student = new Student( window->getWindowAdministrator()->getWidget()->lineEditIdStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditLastNameStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditFirstNameStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditAddressStudent->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditEmailStudent->text().toStdString());
        addStudent(student, window->getWindowAdministrator()->getCurrentGroup());
        window->getWindowAdministrator()->setCurrentStudent(student);
    } 
    window->getWindowAdministrator()->okEditStudent();
}
void Controller::admin_cancelEditStudent() {
    window->getWindowAdministrator()->cancelEditStudent();
}
void Controller::admin_moduleClicked(){
    window->getWindowAdministrator()->moduleClicked();
}
void Controller::admin_classperiodClicked() {
    window->getWindowAdministrator()->setCurrentClassPeriod(NULL);
    window->getWindowAdministrator()->classperiodClicked();
}
void Controller::admin_comboBoxGroupsClassPeriodChanged(int index){
    window->getWindowAdministrator()->comboBoxGroupsClassPeriodChanged(index);
}
void Controller::admin_listGroupClassPeriodClicked(){
    window->getWindowAdministrator()->listGroupClassPeriodClicked();
}
void Controller::admin_comboBoxTypeClassroomChanged() {
    window->getWindowAdministrator()->comboBoxTypeClassroomChanged();
}
void Controller::admin_classroomClicked() {
    window->getWindowAdministrator()->classroomClicked();
}
void Controller::admin_addClassroom() {
    window->getWindowAdministrator()->setCurrentClassroom(NULL);
    window->getWindowAdministrator()->addClassroom();
}
void Controller::admin_editClassroom() {
    window->getWindowAdministrator()->editClassroom();
}
void Controller::admin_deleteClassroom() {
    delClassroom(window->getWindowAdministrator()->getCurrentClassroom());
    window->getWindowAdministrator()->deleteClassroom();
}

int Controller::boolToInt(bool b) {
    if(b) return 1;
    else return 0;
}

void Controller::admin_okEditClassroom() {
    if(window->getWindowAdministrator()->getCurrentClassroom() != NULL)
        if(window->getWindowAdministrator()->getWidget()->checkBoxSpecificity->isVisible())
            setClassroom(window->getWindowAdministrator()->getCurrentClassroom(), window->getWindowAdministrator()->getWidget()->lineEditIdClassroom->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditCapacityClassroom->text().toInt(), boolToInt(window->getWindowAdministrator()->getWidget()->checkBoxSpecificity->isChecked()));
        else
            setClassroom(window->getWindowAdministrator()->getCurrentClassroom(), window->getWindowAdministrator()->getWidget()->lineEditIdClassroom->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditCapacityClassroom->text().toInt(), window->getWindowAdministrator()->getWidget()->lineEditNumberComputers->text().toInt());
    else {
        Classroom *cr;
        if(window->getWindowAdministrator()->getWidget()->comboBoxClassRoom->currentText() == "Lecture Hall")
            cr = new LectureHall(window->getWindowAdministrator()->getWidget()->lineEditIdClassroom->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditCapacityClassroom->text().toInt(), window->getWindowAdministrator()->getWidget()->checkBoxSpecificity->isChecked());
        else if(window->getWindowAdministrator()->getWidget()->comboBoxClassRoom->currentText() == "Practical Classroom")
            cr = new PracticalClassroom(window->getWindowAdministrator()->getWidget()->lineEditIdClassroom->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditCapacityClassroom->text().toInt(), window->getWindowAdministrator()->getWidget()->lineEditNumberComputers->text().toInt());
        else
            cr = new TutorialClassroom(window->getWindowAdministrator()->getWidget()->lineEditIdClassroom->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditCapacityClassroom->text().toInt(), window->getWindowAdministrator()->getWidget()->checkBoxSpecificity->isChecked());
        addClassroom(cr);
        window->getWindowAdministrator()->setCurrentClassroom(cr);
        window->getWindowAdministrator()->getWidget()->tableWidgetClassrooms->setCurrentCell(-1,0);
    }    
    window->getWindowAdministrator()->okEditClassroom();
}
void Controller::admin_cancelEditClassroom() {
    window->getWindowAdministrator()->cancelEditClassroom();
}
void Controller::admin_addModule() {
    window->getWindowAdministrator()->setCurrentModule(NULL);
    window->getWindowAdministrator()->addModule();
}
void Controller::admin_editModule() { 
    window->getWindowAdministrator()->editModule();
}
void Controller::admin_okEditModule() {
    if(window->getWindowAdministrator()->getCurrentModule() != NULL){
        setModule(window->getWindowAdministrator()->getCurrentModule(), window->getWindowAdministrator()->getWidget()->lineEditIdModule->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditNameModule->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditTheHeadModule->text().toStdString());
    }
    else{
        Module* mod = new Module(window->getWindowAdministrator()->getWidget()->lineEditIdModule->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditNameModule->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditTheHeadModule->text().toStdString());
        addModule(mod);

    }
    window->getWindowAdministrator()->setOldIdSelectedModule(window->getWindowAdministrator()->getWidget()->lineEditIdModule->text().toStdString());

    window->getWindowAdministrator()->okEditModule();
}
void Controller::admin_cancelEditModule() {
    window->getWindowAdministrator()->cancelEditModule();
}
void Controller::admin_deleteModule() {
    delModule(window->getWindowAdministrator()->getCurrentModule());
    window->getWindowAdministrator()->deleteModule();
}
void Controller::admin_addClassPeriod() {
    window->getWindowAdministrator()->setCurrentClassPeriod(NULL);
    window->getWindowAdministrator()->addClassPeriod();
}
void Controller::admin_editClassPeriod() {
     window->getWindowAdministrator()->editClassPeriod();
}
void Controller::admin_deleteClassPeriod() {
    QList<QTableWidgetItem*>::iterator itClassPeriod = window->getWindowAdministrator()->getWidget()->tableWidgetClassPeriod->selectedItems().begin();
    list<ClassPeriod*>::iterator itCP = window->getWindowAdministrator()->getCurrentModule()->GetClassPeriodList()->begin();
    list<ClassPeriod*>::const_iterator itCPMax = window->getWindowAdministrator()->getCurrentModule()->GetClassPeriodList()->end();
    for(; itCP!=itCPMax; itCP++){
        if((*itCP)->GetId() == (*itClassPeriod)->text().toInt()) {
            break;
        }
    }
    delClassPeriod((*itCP), window->getWindowAdministrator()->getCurrentModule());
    window->getWindowAdministrator()->setCurrentClassPeriod(NULL);
    window->getWindowAdministrator()->deleteClassPeriod();
}
void Controller::admin_addGroupClassPeriod() {
    window->getWindowAdministrator()->setGroupClassPeriodModified(true);
    window->getWindowAdministrator()->getTempGroupListClassPeriod()->push_back(window->getWindowAdministrator()->getWidget()->comboBoxGroupClassPeriod->currentText());
    
    window->getWindowAdministrator()->addGroupClassPeriod();
}
void Controller::admin_deleteGroupClassPeriod() {
    window->getWindowAdministrator()->setGroupGroupModified(true);
    window->getWindowAdministrator()->getTempGroupListClassPeriod()->removeOne(window->getWindowAdministrator()->getWidget()->listWidgetGroupClassPeriod->currentItem()->text());

    window->getWindowAdministrator()->deleteGroupClassPeriod();
}
void Controller::admin_okEditClassPeriod() {
    window->getWindowAdministrator()->setGroupClassPeriodModified(false);
    list<Group*>* lGNew = new list<Group*>();
    list<Group*> *lg = schedule.GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();
    for( ; itG != itGMax ; itG++){
        if(window->getWindowAdministrator()->getWidget()->listWidgetGroupClassPeriod->findItems(QString::fromStdString((*itG)->GetId()), Qt::MatchCaseSensitive).size() != 0 ){
            lGNew->push_back((*itG));
        }
    }
    window->getWindowAdministrator()->getTempGroupListClassPeriod()->clear();
    if(window->getWindowAdministrator()->getCurrentClassPeriod() != NULL){
        setClassPeriod(window->getWindowAdministrator()->getCurrentModule(), window->getWindowAdministrator()->getCurrentClassPeriod(), window->getWindowAdministrator()->getWidget()->comboBoxTypeClassPeriod->currentText().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditTeacherClassPeriod->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditDurationClassPeriod->text().toInt(), lGNew);
    }
    else{
        ClassPeriod *cp;
        string type = window->getWindowAdministrator()->getWidget()->comboBoxTypeClassPeriod->currentText().toStdString();
        if(type == "Magistral")
            cp = new MagistralClass(window->getWindowAdministrator()->getWidget()->lineEditTeacherClassPeriod->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditDurationClassPeriod->text().toInt(), window->getWindowAdministrator()->getCurrentModule());
        else if(type == "Practical")
            cp = new PracticalClass(window->getWindowAdministrator()->getWidget()->lineEditTeacherClassPeriod->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditDurationClassPeriod->text().toInt(), window->getWindowAdministrator()->getCurrentModule());
        else
            cp = new TutorialClass(window->getWindowAdministrator()->getWidget()->lineEditTeacherClassPeriod->text().toStdString(), window->getWindowAdministrator()->getWidget()->lineEditDurationClassPeriod->text().toInt(), window->getWindowAdministrator()->getCurrentModule());
        cp->SetGroupList(lGNew);
        
        addClassPeriod(cp, window->getWindowAdministrator()->getCurrentModule());
        window->getWindowAdministrator()->setCurrentClassPeriod(cp);
    }
    window->getWindowAdministrator()->okEditClassPeriod();
}
void Controller::admin_cancelEditClassPeriod() {
    window->getWindowAdministrator()->setGroupClassPeriodModified(false);
    window->getWindowAdministrator()->getTempGroupListClassPeriod()->clear();
    window->getWindowAdministrator()->cancelEditClassPeriod();
}

void Controller::addQTimeSlot(QTimeSlot* t) {
    QObject::connect(t, SIGNAL(clicked(QTimeSlot*)), this, SLOT(openEditTimeSlot(QTimeSlot*)));
}

void Controller::removeTimeSlot(QTimeSlot *t) {
    list<TimeSlot*> *lts = schedule.GetTimeSlotList();
    list<TimeSlot*>::iterator it = lts->begin();
    list<TimeSlot*>::const_iterator itMax = lts->end();
    for(;it!=itMax;it++){
        if( (*it)->GetId() == t->getId() ){
            delTimeSlot((*it));
            window->reloadQTimeSlots();
            break;
        }
    }
}

void Controller::tabIndexChanged(){
    window->reloadQTimeSlots();
}

void Controller::changeDate(QDate date) {
    window->changeDate(date);
}

void Controller::openEditTimeSlot() { 
    window->openEditTimeSlot();
}

void Controller::openEditTimeSlot(QTimeSlot* timeSlot) {   
    window->openEditTimeSlot(timeSlot);
}

void Controller::openAdministrator() {
    window->openAdministrator();
}

void Controller::addClassroom(Classroom* cr) {
    schedule.GetClassroomList()->push_back(cr);
    database.addClassroom(cr);
    if(dynamic_cast<PracticalClassroom*>(cr) != NULL)
        database.addPracticalClassroom((PracticalClassroom*) cr);
    else if(dynamic_cast<TutorialClassroom*>(cr) != NULL)
        database.addTutorialClassroom((TutorialClassroom*) cr);
    else
        database.addLectureHall((LectureHall*) cr);
}

void Controller::addGroup(Group *group) {
    database.addGroup(group);
    this->schedule.GetGroupList()->push_back(group);
}

void Controller::setStudent(Student* s, Group* group, string id, string lastname, string firstname, string addr, string email) {
    database.updateStudent(s, group, id, lastname, firstname, addr, email);
    s->SetId(id);
    s->SetLastname(lastname);
    s->SetFirstname(firstname);
    s->SetAddr(addr);
    s->SetEmail(email);
}

void Controller::delClassroom(Classroom* cr) {
    list<TimeSlot*>::iterator it = schedule.GetTimeSlotList()->begin(); 
    list<TimeSlot*>::iterator itMax = schedule.GetTimeSlotList()->end();
    for(; it!=itMax; it++) {
        if((*it)->GetClassroom() == cr) {
            delTimeSlot(*it);
        }
    }
    
    schedule.GetClassroomList()->remove(cr);
    if(dynamic_cast<PracticalClassroom*>(cr) != NULL)
        database.delPracticalClassroom((PracticalClassroom*) cr);
    else if(dynamic_cast<TutorialClassroom*>(cr) != NULL)
        database.delTutorialClassroom((TutorialClassroom*) cr);
    else
        database.delLectureHall((LectureHall*) cr);
}

bool intToBool(int i) {
    if(i==0) return false;
    else return true;
}

void Controller::setClassroom(Classroom* cr, string id, int capacity, int specificity) {
    Classroom* cr2;
    database.updateClassroom(cr, id, capacity);
    if(dynamic_cast<PracticalClassroom*>(cr) != NULL) {
        cr2 = new PracticalClassroom((PracticalClassroom*) cr);
        database.updatePracticalClassroom((PracticalClassroom*) cr, id, specificity);
        ((PracticalClassroom*)cr2)->SetElementsNumber(specificity);
    }     
    else if(dynamic_cast<LectureHall*>(cr) != NULL) {
        cr2 = new LectureHall((LectureHall*) cr);
        ((LectureHall*)cr2)->SetVideoconferencing(intToBool(specificity));
        database.updateLectureHall((LectureHall*) cr, id, intToBool(specificity));
    }
    else {
        cr2 = new TutorialClassroom((TutorialClassroom*) cr);
        ((TutorialClassroom*)cr2)->SetVideoprojector(intToBool(specificity));
        database.updateTutorialClassroom((TutorialClassroom*) cr, id, intToBool(specificity));
    }
    
    schedule.GetClassroomList()->remove(cr);
    schedule.GetClassroomList()->push_back(cr2);
    cr2->SetCapacity(capacity);
}

void Controller::setClassPeriod(Module *mod, ClassPeriod* cp, string type, string teacher, int duration, list<Group*>* lg){
    int id_type = 2;
    ClassPeriod* cp2;
    if(type == "Tutorial") {
        cp2 = new TutorialClass(cp);
        id_type = 3;
    }
    else if(type == "Practical") {
        cp2 = new PracticalClass(cp);   
        id_type = 1;
    }     
    else if(type == "Magistral") {
        cp2 = new MagistralClass(cp);
        id_type = 2;
    }
    database.updateClassPeriod(mod, cp, id_type, teacher, duration, lg);
    
    mod->GetClassPeriodList()->remove(cp);
    mod->GetClassPeriodList()->push_back(cp2);
    cp2->SetTeacher(teacher);
    cp2->SetDuration(duration);
    cp2->SetGroupList(lg);
}

void Controller::addStudent(Student *stud, Group *group){
    database.addStudent(stud, group);
    group->GetStudentList()->push_back(stud);
}

/*void Controller::addGroup(Group* group)
  {    if(group->GetDaddy() != NULL){
        this->history << "insert into 'Group' values('"<<group->GetId()<<"', ''"<<group->GetDaddy()->GetId()<<"');"<<endl;
    }
    else {
        this->history << "insert into 'Group' values('"<<group->GetId()<<"', '')"<<endl;
    }
    schedule.GetGroupList()->push_back(group);
}*/

void Controller::addModule(Module* mod){
    database.addModule(mod);
    schedule.GetModuleList()->push_back(mod);
}

void Controller::delGroup(Group* group) {
    while(group->GetStudentList() != NULL && group->GetStudentList()->size() != 0){
        delStudent(*(group->GetStudentList()->begin()), group);
    }
    while(group->GetGroupList() != NULL && group->GetGroupList()->size() != 0){
        delGroup(*(group->GetGroupList()->begin()));
        group->GetGroupList()->remove(*(group->GetGroupList()->begin()));
    }
    database.delGroup(group);
    this->schedule.GetGroupList()->remove(group);
}

void Controller::delModule(Module* mod) {
    list<ClassPeriod*>::iterator it = mod->GetClassPeriodList()->begin();
    list<ClassPeriod*>::iterator itMax = mod->GetClassPeriodList()->end();
    for(; it!=itMax; it++) {
        delClassPeriod(*it, mod);
    }
    
    database.delModule(mod);
    this->schedule.GetModuleList()->remove(mod);
}

void Controller::delStudent(Student *stud, Group *group) {
    database.delStudent(stud, group);
    group->GetStudentList()->remove(stud);
}
string Controller::intToStr(int i){
    ostringstream oss;
    oss << i;
    return oss.str();
}

bool Controller::addTimeSlot(TimeSlot* timeSlot) {
    list<TimeSlot*> *timeSlotList = new list<TimeSlot*>();
    list<TimeSlot*>::iterator it = this->schedule.GetTimeSlotList()->begin();
    list<TimeSlot*> ::const_iterator itMax = this->schedule.GetTimeSlotList()->end();
    for(; it!=itMax; it++) {
        cout<< "timeSlot->GetStartDate() = "<< *(timeSlot->GetStartDate()) << endl
                << "timeSlot->GetEndtDate() = "<< *(timeSlot->GetEndDate()) << endl
                << "(*it)->GetStartDate() = " << *((*it)->GetStartDate()) << endl
                << "(*it)->GetEndDate() = " << *((*it)->GetEndDate()) << endl
                << "test >=  = " << (*((timeSlot->GetStartDate())) >= (*((*it)->GetStartDate()))) <<endl
                << "test <=  = " << ((*(timeSlot->GetStartDate())) <= (*((*it)->GetEndDate()))) << endl
                << "test <  = " << ((*(timeSlot->GetStartDate())) < (*((*it)->GetStartDate()))) <<endl
                << "test >  = " << ((*(timeSlot->GetEndDate())) > (*((*it)->GetStartDate()))) << endl;
        if( 
                    (
                    (*((timeSlot->GetStartDate())) >= (*((*it)->GetStartDate()))) 
                    && (*(timeSlot->GetStartDate())) <= (*((*it)->GetEndDate()))
                    ) 
                || 
                    ( 
                    (*(timeSlot->GetStartDate())) < (*((*it)->GetStartDate())) 
                    && (*(timeSlot->GetEndDate())) > (*((*it)->GetStartDate()))
                    ) 
                ){
            timeSlotList->push_back(*it);
        }
    }
    cout << "count liste timeslot a conflit : "<<timeSlotList->size()<<endl;
    it = timeSlotList->begin();
    itMax = timeSlotList->end();
    for(; it!=itMax; it++) {
        if((*it)->GetClassroom()->GetId() == timeSlot->GetClassroom()->GetId())
            return false;
        else {
            list<Group*>::iterator itG = (*it)->GetClassPeriod()->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = (*it)->GetClassPeriod()->GetGroupList()->end();
            for(; itG != itGMax; itG++) {
                list<Group*>* lg = timeSlot->GetClassPeriod()->GetGroupList();
                 if( find(lg->begin(), lg->end(), &(*(*itG))) != lg->end() )
                    return false;
            }
        }
    }
    
    database.addTimeSlot(timeSlot);
    this->schedule.GetTimeSlotList()->push_back(timeSlot);
    
    delete timeSlotList;
    return true;
}

void Controller::setGroup(Group* g, string id, list<Group*> *lg) {
    list<Group*>::iterator it = this->schedule.GetGroupList()->begin();
    list<Group*>::const_iterator itMax = this->schedule.GetGroupList()->end();
    Group* popa = NULL;
    for(;it != itMax ; it++){
        if((*it)->GetId() == g->GetId()){
            popa = (*it);
        }
    }
    
    list<Group*>::iterator it2 = lg->begin();
    list<Group*>::const_iterator it2Max = lg->end();
    for(;it2 != it2Max ; it2++){
        database.updateGroup((*it2), (*it2)->GetId(), g);
    }
    
    database.updateGroup(g, id, popa);
    g->SetGroupList(lg);
    g->SetId(id);
}

void Controller::delTimeSlot(TimeSlot* timeSlot) {
    database.delTimeSlot(timeSlot);
    this->schedule.GetTimeSlotList()->remove(timeSlot);
}
    
void Controller::addClassPeriod(ClassPeriod* classPeriod, Module *mod) {
    if(dynamic_cast<PracticalClass*>(classPeriod) != NULL)
        database.addClassPeriod(classPeriod, 1, mod);
    else if(dynamic_cast<MagistralClass*>(classPeriod) != NULL)
        database.addClassPeriod(classPeriod, 2, mod);
    else
        database.addClassPeriod(classPeriod, 3, mod);
    mod->GetClassPeriodList()->push_back(classPeriod);
}

void Controller::delClassPeriod(ClassPeriod* classPeriod, Module *mod) {    
    list<TimeSlot*>::iterator it = schedule.GetTimeSlotList()->begin(); 
    list<TimeSlot*>::iterator itMax = schedule.GetTimeSlotList()->end();
    for(; it!=itMax; it++) {
        if((*it)->GetClassPeriod() == classPeriod) {
            delTimeSlot(*it);
        }
    }
    
    database.delClassPeriod(classPeriod, mod);
    mod->GetClassPeriodList()->remove(classPeriod);
}

void Controller::commit(){
    database.commit();
}
int Controller::strToInt(string str){
    int val = 0;
    
    for(unsigned int i= 0 ; i < str.length() ; i++){
        val *= 10;
        val += str[i] - '0';
    }
   return val; 
}

Date* Controller::strToDate(string date){
    int h = 0;
    int m = 0;
    
    if(date.length() > 10){
        h = strToInt(date.substr(11,2));
        m = strToInt(date.substr(15,2));
    }
    Date *dateh = new Date(strToInt(date.substr(0,2)), strToInt(date.substr(3,2)), strToInt(date.substr(6,4)), h, m);
    return dateh;
}

bool Controller::strToBool(string str){
    return (str == "true");
}

struct groupString{
    Group* group;
    string str;
};

void Controller::setModule(Module* mod, string id, string name, string theHead){
    database.updateModule(mod, id, name, theHead);
    mod->SetId(id);
    mod->SetName(name);
    mod->SetTheHead(theHead);
}

void addChildrenToGroup(list<Group*> *lgBase, list<struct groupString*>* lgs, Group* group){
    list<Group*>* lChildren = new list<Group*>();
    group->SetGroupList(lChildren);
    list< struct groupString* >::iterator itLGS = lgs->begin();
    list< struct groupString* >::const_iterator itMaxLGS = lgs->end();
    int count = 0;
    while(itLGS != itMaxLGS){
        if( (*itLGS)->str == group->GetId() ){
            Group *groupChld = new Group((*itLGS)->group);
            lChildren->push_back(groupChld);
            lgBase->push_back(groupChld);
            lgs->erase(itLGS);
            itLGS = lgs->begin();
            itMaxLGS = lgs->end();
            count = count - 1;
            for(int i = 0 ; i < count ; i++){
                itLGS++;
            }
        }
        itLGS++; count++;
    }
    list<Group*>::iterator it = lChildren->begin();
    list<Group*>::const_iterator itMax = lChildren->end();
    for(; it!=itMax; it++) {
        addChildrenToGroup(lgBase, lgs, (*it));
    }
}


void Controller::loadSchedule(){
    cout<<"loading schedule..."<<endl;
    /*if(this->schedule != NULL)
        delete this->schedule;*/
    list< list<string> >* result;
    try{
         result = database.request("select * from vlecturehall");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                //list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule.GetClassroomList()->push_back(new LectureHall(*itList, strToInt(*(++itList)), strToBool(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database.request("select * from vpracticalclassroom");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
//                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule.GetClassroomList()->push_back(new PracticalClassroom(*itList, strToInt(*(++itList)), strToInt(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database.request("select * from vtutorialclassroom");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
//                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                this->schedule.GetClassroomList()->push_back(new TutorialClassroom(*itList, strToInt(*(++itList)), strToBool(*(++itList)) ));
             } 
         }
         result->clear();
         
         result = database.request("select * from 'group'");
         if(result != NULL){
             list<struct groupString*>* lgs = new list<struct groupString*>();
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
//              list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                
                string id = (*itList);
                string idP = *(++itList);
                 
                Group *g = new Group(id, NULL);
                if(idP == "") {
                    this->schedule.GetGroupList()->push_back(g);
                }
                else {
                    struct groupString *gs = new struct groupString();
                    gs->str = idP; 
                    gs->group = g;
                    lgs->push_back(gs);
                }
                
             } 

            list<Group*>::iterator itG = this->schedule.GetGroupList()->begin();
            list<Group*>::const_iterator itMaxG = this->schedule.GetGroupList()->end();
            for(; itG!=itMaxG; itG++) {
                addChildrenToGroup(this->schedule.GetGroupList(), lgs, (*itG));
            }
            
            if(lgs->size() != 0) {
                list< struct groupString* >::iterator itLGS = lgs->begin();
                list< struct groupString* >::const_iterator itMaxLGS = lgs->end();
                for(;itLGS != itMaxLGS ; itLGS++){
                        Group *groupChld = new Group((*itLGS)->group);
                        this->schedule.GetGroupList()->push_back(groupChld);
                }
            }
            delete lgs;             
         }
         
         result->clear();      
         
         result = database.request("select * from student");
         if(result != NULL){
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
//                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                string stuId = *itList;
                string groupId = *(++itList);
                Student *stud = new Student(stuId, *(++itList), *(++itList), *(++itList), *(++itList));
                
                list<Group*>::const_iterator MaxGroupList = this->schedule.GetGroupList()->end();                
                list<Group*>::iterator elemGroupList = this->schedule.GetGroupList()->begin();                
                for(;elemGroupList != MaxGroupList ; elemGroupList++){
                    if((*elemGroupList)->GetId() == groupId){
                        (*elemGroupList)->GetStudentList()->push_back(stud);
                        break;
                    }
                }
                
             } 
         }
         
         
         
         result->clear();
         result = database.request("select m.id, m.name, m.theHead, c.id, c.teacher, c.duration, c.id_type, a.id_group from Module m left join Classperiod c on m.id = c.id_module left join assign a on c.id = a.id_classPeriod order by m.id, c.id, a.id_group");
         if(result != NULL){
             string idModule = "";
             string idClassPeriod = "";
             Module *mod;
             ClassPeriod *classPeriod;
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
                //list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                if(idModule != *itList) {
                    idModule = *itList;
                    mod = new Module(idModule, *(++itList), *(++itList));
                    this->schedule.GetModuleList()->push_back(mod);
                }
                else {
                    itList++;
                    itList++;
                }
                if(*(++itList) != "") { 
                    if(idClassPeriod != (*itList) ) {
                        idClassPeriod = (*itList);
                        int id = strToInt(*(itList));
                        string teacher = *(++itList);
                        int duration = strToInt(*(++itList));
                        int type = strToInt(*(++itList));
                        switch(type){
                            case 1 :
                                classPeriod = new PracticalClass(teacher, duration, mod);
                                break;
                            case 2 :
                                classPeriod = new MagistralClass(teacher, duration, mod);
                                break;
                            case 3 :
                                classPeriod = new TutorialClass(teacher, duration, mod);
                                break;
                            default :
                                cout<< "Le type de la classPeriod en cours de chargement ne correspond pas a un type valide" <<endl;
                                break;
                        }

                        mod->GetClassPeriodList()->push_back(classPeriod);
                    }
                    else {
                        itList++;
                        itList++; 
                        itList++;
                        itList++; 
                    }
                    if(*(++itList) != "") {
                        string idGroup = (*itList);
                        list<Group*>::iterator it = this->schedule.GetGroupList()->begin();
                        list<Group*>::const_iterator itMax = this->schedule.GetGroupList()->end();
                        for(; it!=itMax; it++) {
                            if((*it)->GetId() == idGroup) {
                                classPeriod->GetGroupList()->push_back(*it);
                                break;
                            }
                        }
                    }
                }
                
             } 
         }
         
         result->clear();
         result = database.request("select id_classroom, id_classperiod, id, date from timeslot");
         if(result != NULL){
             string idModule = "";
//             Module *mod;
             list< list<string> >::iterator it = result->begin();
             list< list<string> >::const_iterator MaxList = result->end();
             for(;it != MaxList; it++){
//                list<string>::const_iterator MaxListList = it->end();
                list<string>::iterator itList = it->begin();
                Classroom *classroom;
                ClassPeriod *classperiod;
                string classroomId = *itList;
                string classPeriodId = *(++itList);
                //recherche de la salle
                list<Classroom*>::const_iterator MaxClassroomList = this->schedule.GetClassroomList()->end();                
                list<Classroom*>::iterator elemClassroomList = this->schedule.GetClassroomList()->begin();                
                for(;elemClassroomList != MaxClassroomList ; elemClassroomList++){
                    if((*elemClassroomList)->GetId() == classroomId){
                        classroom = (*elemClassroomList);
                        break;
                    }
                }
                
                list<Module*>::const_iterator MaxModuleList = this->schedule.GetModuleList()->end();                
                list<Module*>::iterator elemModuleList = this->schedule.GetModuleList()->begin();                
                for(;elemModuleList != MaxModuleList ; elemModuleList++){
                    list<ClassPeriod*>::const_iterator MaxClassPeriodList = (*elemModuleList)->GetClassPeriodList()->end();
                    list<ClassPeriod*>::iterator elemClassPeriodList = (*elemModuleList)->GetClassPeriodList()->begin();
                    for(;elemClassPeriodList != MaxClassPeriodList ; elemClassPeriodList++){
                        if((*elemClassPeriodList)->GetId() == strToInt(classPeriodId)){
                            classperiod = (*elemClassPeriodList);
                            break;
                        }
                    }
                }
                ++itList;
                TimeSlot *timeslot = new TimeSlot(strToDate(*(++itList)), classroom, classperiod);
                schedule.GetTimeSlotList()->push_back(timeslot); 
             } 
         }
         
    }catch(int){
        cout<<"Error while loading classrooms."<<endl;
    }
}

Controller::~Controller() {
    delete window; 
}


#include "QSchedule.h"

QSchedule::QSchedule(QWidget *parent) : QWidget (parent) {

    dayNameList = new QList<QString>();
    dayLabelList = new QList<QLabel*>();
    hourLabelList = new QList<QLabel*>();
    timeSlotList = new QList<QTimeSlot*>();
    borderHLabelList = new QList<QLabel*>();
    borderVLabelList = new QList<QLabel*>();

    dayNameList->push_back(LUNDI);
    dayNameList->push_back(MARDI);
    dayNameList->push_back(MERCREDI);
    dayNameList->push_back(JEUDI);
    dayNameList->push_back(VENDREDI);
    dayNameList->push_back(SAMEDI);

    marginTop = 0;
    marginLeft = 0;
    hoursHeight = 20;
    dayNameWidth = 80;
    width = 954;
    height = 520;
    numberOfHours = 12;
    hourStart = 8;
    int minw = 600;
    int minh = 400;
    borderWidth = 1;
    border = true;
    borderStyle = "gray";
    title = "Emploi du temps :";
    titleHeight = 30;
    fontSizeTitle = 15;

    labelTitle = new QLabel(this);


    QList<QString>::iterator itDay = dayNameList->begin();
    QList<QString>::const_iterator itDayEnd = dayNameList->end();
    for(; itDay != itDayEnd; itDay++){
        QLabel *label = new QLabel(*itDay, this);
        dayLabelList->push_back(label);
        label = new QLabel("", this);
        borderHLabelList->push_back(label);
    }

    for(int i=0; i<numberOfHours; i++) {
        QLabel *horraire = new QLabel(QString::number(hourStart+i)+"h", this);
        hourLabelList->push_back(horraire);
        QLabel *label = new QLabel("", this);
        borderVLabelList->push_back(label);
    }

    setMinimumSize(minw,minh);
    updateChildren();

}

void QSchedule::removeAllTimeSlots(){
    QList<QTimeSlot*>::iterator it = timeSlotList->begin();
    QList<QTimeSlot*>::const_iterator itEnd = timeSlotList->end();
    for(; it != itEnd; it++) {
        (*it)->close();
        delete (*it);
    }
    this->timeSlotList->clear();
    updateChildren();
}

#include <iostream>
QTimeSlot* QSchedule::addTimeSlot(QTimeSlot *timeSlot) {
    if(startDate<=timeSlot->getDate() && endDate>=timeSlot->getDate() && 
            timeSlot->getHour()>=hourStart && 
            (timeSlot->getHour()*60+timeSlot->getDuration()+timeSlot->getMinute())<(hourStart*60+numberOfHours*60)) {      
        timeSlotList->push_back(timeSlot);
        timeSlot->setGeometry((timeSlot->getHour()-hourStart)*minMinutesWidth*MIN_TIME_IN_HOUR+dayNameWidth+((int)minMinutesWidth*timeSlot->getMinute()/MIN_TIME+marginLeft),
                                (timeSlot->getDate().dayOfWeek()-1)*dayHeight+marginTop+hoursHeight+titleHeight,(int)(minMinutesWidth*timeSlot->getDuration()/MIN_TIME), dayHeight);
        timeSlot->show();
        return timeSlot;
    }
    else {
        std::cout<<"Je suis embarassé, je n'ai pas réussi à ajouter un timeslot!"<<std::endl;
    }
    return NULL;
}
void QSchedule::setMarginLeft ( int ml) {
    marginLeft = ml;
    updateChildren();
}
void QSchedule::setMarginTop ( int mt) {
    marginTop = mt;
    updateChildren();
}
void QSchedule::setHoursHeight ( int hh) {
    hoursHeight = hh;
    updateChildren();
}
void QSchedule::setDayNameWidth ( int dnw) {
    dayNameWidth = dnw;
    updateChildren();
}
void QSchedule::setWidth ( int w) {
    width = w;
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
}
void QSchedule::setHeight ( int h) {
    height = h;
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
}
void QSchedule::setNumberOfHours ( int nh) {
    numberOfHours = nh;
    updateChildren();
}
void QSchedule::setHourStart ( int hs) {
    hourStart = hs;

    QList<QLabel*>::iterator itHour = hourLabelList->begin();
    QList<QLabel*>::const_iterator itHourEnd = hourLabelList->end();
    for(; itHour != itHourEnd; itHour++) {
        (*itHour)->clear();
        (*itHour)->close();
        delete (*itHour);
    }
    hourLabelList->clear();

    this->show();
    for(int i=0; i<numberOfHours; i++) {
        QLabel *horraire = new QLabel(QString::number(hourStart+i)+"h", this);
        hourLabelList->push_back(horraire);
    }
    updateChildren();
}
void QSchedule::setBorderWidth (int w) {
    borderWidth = w;
    updateChildren();
}
void QSchedule::setBorder (int b) {
    border = b;
    updateChildren();
}
void QSchedule::setBorderStyle (QString s) {
    borderStyle = s;
    updateChildren();
}
void QSchedule::setTitle(QString t) {
    title = t;
    updateChildren();
}
void QSchedule::setTitleHeight(int h) {
    titleHeight = h;
    updateChildren();
}
void QSchedule::setFontSizeTitle(int s) {
    fontSizeTitle = s;
    updateChildren();
}
void QSchedule::setDate(QDate date) {
    startDate = date.addDays((-1)*(date.dayOfWeek()-1));
    endDate = date.addDays(7-date.dayOfWeek());

    title = "Emploi du temps du : "+startDate.toString("dd/MM/yyyy")+" au "+endDate.toString("dd/MM/yyyy");

    updateChildren();
}
void QSchedule::setDayNameList(QList<QString> *list) {

    delete dayNameList;
    dayNameList = list;

    QList<QLabel*>::iterator itLDay = dayLabelList->begin();
    QList<QLabel*>::const_iterator itLDayEnd = dayLabelList->end();
    for(; itLDay != itLDayEnd; itLDay++) {
        (*itLDay)->clear();
        (*itLDay)->close();
        delete (*itLDay);
    }
    dayLabelList->clear();

    QList<QLabel*>::iterator itBorderH = borderHLabelList->begin();
    QList<QLabel*>::const_iterator itBorderHEnd = borderHLabelList->end();
    for(; itBorderH != itBorderHEnd; itBorderH++) {
        (*itBorderH)->clear();
        (*itBorderH)->close();
        delete (*itBorderH);
    }
    borderHLabelList->clear();

    QList<QString>::iterator itDay = dayNameList->begin();
    QList<QString>::const_iterator itDayEnd = dayNameList->end();
    for(; itDay != itDayEnd; itDay++){
        QLabel *label = new QLabel(*itDay, this);
        dayLabelList->push_back(label);
        label = new QLabel("", this);
        borderHLabelList->push_back(label);
    }
    updateChildren();
    this->show();
}

void QSchedule::updateChildren() {    
    minMinutesWidth = (int)((width-dayNameWidth-marginLeft)/(numberOfHours*MIN_TIME_IN_HOUR));
    dayHeight = (height-marginTop-titleHeight-hoursHeight)/dayNameList->count();

    labelTitle->setText(title);
    labelTitle->setGeometry(marginLeft, marginTop, width, titleHeight);
    labelTitle->setStyleSheet("font-weight : bold; font-size: "+QString::number(fontSizeTitle)+"px; padding-bottom: 5px;");

    QList<QLabel*>::iterator itBorderH = borderHLabelList->begin();
    QList<QLabel*>::const_iterator itBorderHEnd = borderHLabelList->end();
    for(int i=0; itBorderH != itBorderHEnd; itBorderH++) {
        (*itBorderH)->setGeometry(marginLeft, (i*dayHeight)+marginTop+titleHeight+hoursHeight-((int)borderWidth/2), width, borderWidth);
        (*itBorderH)->setStyleSheet("background-color : "+borderStyle+";");
        if(border)
            (*itBorderH)->setVisible(true);
        else
            (*itBorderH)->setVisible(false);
        i++;
    }

    QList<QLabel*>::iterator itBorderV = borderVLabelList->begin();
    QList<QLabel*>::const_iterator itBorderVEnd = borderVLabelList->end();
    for(int i=0; itBorderV != itBorderVEnd; itBorderV++) {
        (*itBorderV)->setGeometry(i*minMinutesWidth*MIN_TIME_IN_HOUR+dayNameWidth+marginLeft-((int)borderWidth/2), marginTop+titleHeight+hoursHeight, borderWidth, height-marginTop-hoursHeight);
        (*itBorderV)->setStyleSheet("background-color : "+borderStyle+";");
        if(border)
            (*itBorderV)->setVisible(true);
        else
            (*itBorderV)->setVisible(false);
        i++;
    }

    QList<QLabel*>::iterator itDay = dayLabelList->begin();
    QList<QLabel*>::const_iterator itDayEnd = dayLabelList->end();
    for(int i=0; itDay != itDayEnd; itDay++) {
        (*itDay)->setGeometry(marginLeft, (i*dayHeight)+marginTop+hoursHeight+titleHeight, dayNameWidth, dayHeight);
        i++;
    }

    QList<QLabel*>::iterator itHour = hourLabelList->begin();
    QList<QLabel*>::const_iterator itHourEnd = hourLabelList->end();
    for(int i=0; itHour != itHourEnd; itHour++) {
        (*itHour)->setGeometry(i*minMinutesWidth*MIN_TIME_IN_HOUR+dayNameWidth+marginLeft, marginTop+titleHeight,
                               minMinutesWidth*MIN_TIME_IN_HOUR, hoursHeight);
        i++;
    }

    QList<QTimeSlot*>::iterator itTimeS = timeSlotList->begin();
    QList<QTimeSlot*>::const_iterator itTimeSEnd = timeSlotList->end();
    for(;itTimeS != itTimeSEnd; itTimeS++)
        (*itTimeS)->setGeometry(((*itTimeS)->getHour()-hourStart)*minMinutesWidth*MIN_TIME_IN_HOUR+dayNameWidth+((int)minMinutesWidth*(*itTimeS)->getMinute()/MIN_TIME)+marginLeft,
                            ((*itTimeS)->getDate().dayOfWeek()-1)*dayHeight+marginTop+hoursHeight+titleHeight,
                                (int)(minMinutesWidth*(*itTimeS)->getDuration()/MIN_TIME), dayHeight);
}

void QSchedule::resizeEvent(QResizeEvent* event) {
    width = event->size().width();
    height = event->size().height();
    updateChildren();
    event->accept();
}

QTimeSlot* QSchedule::getTimeSlot(int i) {
    return timeSlotList->toVector()[i];
}

void QSchedule::removeTimeSlot(int i) {
    QTimeSlot *t = timeSlotList->toVector()[i];
    t->close();
    timeSlotList->removeAt(i);
    updateChildren();
}

QSchedule::~QSchedule() {
    QList<QLabel*>::iterator itBorderH = borderHLabelList->begin();
    QList<QLabel*>::const_iterator itBorderHEnd = borderHLabelList->end();
    for(; itBorderH != itBorderHEnd; itBorderH++) {
        (*itBorderH)->close();
        delete (*itBorderH);
    }
    QList<QLabel*>::iterator itBorderV = borderVLabelList->begin();
    QList<QLabel*>::const_iterator itBorderVEnd = borderVLabelList->end();
    for(; itBorderV != itBorderVEnd; itBorderV++) {
        (*itBorderV)->close();
        delete (*itBorderV);
    }
    QList<QLabel*>::iterator itDay = dayLabelList->begin();
    QList<QLabel*>::const_iterator itDayEnd = dayLabelList->end();
    for(; itDay != itDayEnd; itDay++) {
        (*itDay)->close();
        delete (*itDay);
    }
    QList<QLabel*>::iterator itHour = hourLabelList->begin();
    QList<QLabel*>::const_iterator itHourEnd = hourLabelList->end();
    for(; itHour != itHourEnd; itHour++) {
        (*itHour)->close();
        delete (*itHour);
    }
    QList<QTimeSlot*>::iterator itTimeS = timeSlotList->begin();
    QList<QTimeSlot*>::const_iterator itTimeSEnd = timeSlotList->end();
    for(;itTimeS != itTimeSEnd; itTimeS++) {
        (*itTimeS)->close();
        delete (*itTimeS);
    }
    delete dayLabelList;
    delete hourLabelList;
    delete borderHLabelList;
    delete borderVLabelList;
    delete timeSlotList;
    delete labelTitle ;
    delete dayNameList;
}

#include "QTimeSlot.h"

QTimeSlot::QTimeSlot(int id, QDate date, int hour, int minute, int duration, QString classPeriod,
    QString classRoom, QString module, QString teacher, QString group, QWidget *parent) : QPushButton(parent)
{
    this->id = id;
    this->date = date;
    this->hour = hour;
    this->minute = minute;
    this->duration = duration;
    this->classPeriod = classPeriod;
    this->classRoom = classRoom;
    this->module = module;
    this->teacher = teacher;
    this->group = group;

    fontFize = 9;
    fontColor = "white";
    backgroundColor = "blue";

    QVBoxLayout *layout = new QVBoxLayout();

    labelTime = new QLabel();
    layout->addWidget(labelTime);
    labelContent = new QLabel();
    layout->addWidget(labelContent);

    layout->setSpacing(0);
    this->setLayout(layout);

    updateChildren();
}

void QTimeSlot::updateChildren() {
    int endHour = (hour+((int) duration/60))%24;
    int endMinute = minute+duration%60;

    QString time = withZero(QString::number(hour))+":"+withZero(QString::number(minute))+"-"
                                      +withZero(QString::number(endHour))+":"+withZero(QString::number(endMinute));
    
    labelTime->setText(time);
    labelTime->setMinimumHeight(15);
    labelTime->setMaximumHeight(15);
    labelTime->setStyleSheet("background-color : "+backgroundColor+"; color: "+fontColor+"; font-weight: bold; font-size: "+
                             QString::number(fontFize)+"px;");

    labelContent->setText(classPeriod+" - "+classRoom+"\n"+module+"\n"+teacher+"\n"+group);
    labelContent->setStyleSheet("font-size: "+QString::number(fontFize)+"px;");
    labelContent->setWordWrap(true);
    
    this->setToolTip(time+"\n\n"+classPeriod+" - "+classRoom+"\n"+module+"\n"+teacher+"\n"+group);
}

QString QTimeSlot::withZero(QString s) {
    if(s.count() == 1)
        return "0"+s;
    else
        return s;
}

QTimeSlot::~QTimeSlot() {
    delete labelContent;
    delete labelTime;
//    delete &date;
}

void QTimeSlot::mousePressEvent(QMouseEvent* e) {
    QPushButton::mousePressEvent(e);
    emit clicked(this);
}
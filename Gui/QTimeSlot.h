#ifndef QTIMESLOT_H
#define QTIMESLOT_H

#include <QtGui>
#include <QString>

class QTimeSlot : public QPushButton
{
    Q_OBJECT
public:
    explicit QTimeSlot(int id, QDate date, int hour, int minute, int duration, QString classPeriod = "",
            QString classRoom = "", QString module = "", QString teacher = "", QString group = "", QWidget *parent = 0);

    ~QTimeSlot();
    QString getClassPeriod() const { return classPeriod; }
    QString getClassRoom() const { return classRoom; }
    QString getModule() const { return module; }
    QString getTeacher() const { return teacher; }
    QString getGroup() const { return group; }
    QDate getDate() const { return date; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getDuration() const { return duration; }
    int getFontFize() const { return fontFize; }
    QString getFontColor() const { return fontColor; }
    QString getBackgroundColor() const { return backgroundColor; }

    void setClassPeriod(QString s) { classPeriod = s; updateChildren(); }
    void setClassRoom(QString s) { classRoom = s; updateChildren(); }
    void setModule(QString s) { module = s; updateChildren(); }
    void setTeacher(QString s) { teacher = s; updateChildren(); }
    void setGroup(QString s) { group = s; updateChildren(); }
    void setDate(QDate d) { date = d; updateChildren(); }
    void setHour(int n) { hour = n; updateChildren(); }
    void setMinute(int n) { minute = n; updateChildren(); }
    void setDuration(int n) { duration = n; updateChildren(); }
    void setFontFize(int n) { fontFize = n; updateChildren(); }
    void setFontColor(QString s) { fontColor = s; updateChildren(); }
    void setBackgroundColor(QString s) { backgroundColor = s; updateChildren(); }
    int getId() const {
        return id;
    }

    void mousePressEvent(QMouseEvent* e);

private:
    int id;
    QString classPeriod;
    QString classRoom;
    QString module;
    QString teacher;
    QString group;
    QDate date;
    int hour;
    int minute;
    int duration;
    int fontFize;
    QString fontColor;
    QString backgroundColor;
    QLabel *labelContent;
    QLabel *labelTime;
    QString withZero(QString s);
    void updateChildren();

signals:
        void clicked(QTimeSlot* timeSlot); 

public slots:

};

#endif // QTIMESLOT_H

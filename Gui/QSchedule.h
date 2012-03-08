#ifndef QSCHEDULE_H
#define QSCHEDULE_H

#include <QtGui>
#include <QList>
#include <QString>
<<<<<<< HEAD
#include "QTimeSlot.h"
=======
#include <QTimeSlot.h>
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9

#define LUNDI "Lundi"
#define MARDI "Mardi"
#define MERCREDI "Mercredi"
#define JEUDI "Jeudi"
#define VENDREDI "Vendredi"
#define SAMEDI "Samedi"
#define MIN_TIME 10
#define MIN_TIME_IN_HOUR 6
#define MIN_TIME_HALF_IN_HOUR 3

class QSchedule : public QWidget
{
    Q_OBJECT
public:
    explicit QSchedule(QWidget *parent = 0);
    ~QSchedule();
    void addTimeSlot(QDate date, int hour, int minute, int duration, QString classPeriod = "",
                QString classRoom = "", QString module = "", QString teacher = "", QString group = "");

    void setMarginLeft ( int ml);
    void setMarginTop ( int mt);
    void setHoursHeight ( int hh);
    void setDayNameWidth ( int dnw);
    void setWidth ( int w);
    void setHeight ( int h);
    void setNumberOfHours ( int nh);
    void setHourStart ( int hs);
    void setBorderWidth (int w);
    void setBorder (int b);
    void setBorderStyle (QString s);
    void setTitle(QString t);
    void setTitleHeight(int h);
    void setFontSizeTitle(int s);
    void setDate(QDate date);

    int getMarginLeft() const { return marginLeft; }
    int getMarginTop() const { return marginTop; }
    int getHoursHeight() const { return hoursHeight; }
    int getDayNameWidth() const { return dayNameWidth; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getNumberOfHours() const { return numberOfHours; }
    int getHourStart() const { return hourStart; }
    int getBorderWidth() const { return borderWidth; }
    bool getBorder() const { return border; }
    QString getBorderStyle() const { return borderStyle; }
    QString getTitle() const { return title; }
    int getTitleHeight() const { return titleHeight; }
    int getFontSizeTitle() const { return fontSizeTitle; }
    QDate getStartDate() const { return startDate; }
    QDate getEndDate() const { return endDate; }

    QList<QString>* getDayNameList() const { return dayNameList; }
    void setDayNameList(QList<QString> *list);

    QList<QTimeSlot*>* getTimeSlotList() const { return timeSlotList;}
    QTimeSlot* getTimeSlot(int i);
    void removeTimeSlot(int i);

protected:
    void resizeEvent(QResizeEvent* event);

 private:
    QList<QString> *dayNameList;
    QList<QLabel*> *dayLabelList;
    QList<QLabel*> *hourLabelList;
    QList<QLabel*> *borderHLabelList;
    QList<QLabel*> *borderVLabelList;
    QList<QTimeSlot*> *timeSlotList;
    QLabel *labelTitle ;
    QString title;
    int titleHeight;
    int fontSizeTitle;
    QDate startDate;
    QDate endDate;
    int marginLeft;
    int marginTop;
    int hoursHeight;
    int dayHeight;
    int dayNameWidth;
    int width;
    int height;
    int numberOfHours;
    int hourStart;
    int minMinutesWidth;
    int borderWidth;
    bool border;
    QString borderStyle;
    void updateChildren();

signals:

public slots:

};

#endif // QSCHEDULE_H

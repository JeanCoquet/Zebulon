/* 
 * File:   Date.h
 * Author: bicodul
 *
 * Created on February 8, 2012, 6:32 PM
 */

#ifndef DATE_H
#define	DATE_H
#include <string>
#include <iostream>
using namespace std;

class Date {
public:
    Date(int day, int month, int year, int hour, int min);
    Date(const Date& orig);
    static bool isLeapYear(int y);
    int duration() const;
    
    virtual ~Date();

    int GetDay() const {
        return day;
    }

    void SetDay(int day) {
        this->day = day;
    }

    int GetHour() const {
        return hour;
    }

    void SetHour(int hour) {
        this->hour = hour;
    }

    int GetMin() const {
        return min;
    }

    void SetMin(int min) {
        this->min = min;
    }

    int GetMonth() const {
        return month;
    }

    void SetMonth(int month) {
        this->month = month;
    }

    int GetYear() const {
        return year;
    }

    void SetYear(int year) {
        this->year = year;
    }

private:
    int day;
    int month;
    int year;
    int hour;
    int min;
};

ostream& operator <<(ostream& os, const Date &d);
Date& operator+(Date const& date, int min);
bool operator==(Date const& d1, Date const& d2);
bool operator<(Date const& d1, Date const& d2);
bool operator>(Date const& d1, Date const& d2);
bool operator<=(Date const& d1, Date const& d2);
bool operator>=(Date const& d1, Date const& d2);




#endif	/* DATE_H */


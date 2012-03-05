/* 
 * File:   Date.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:32 PM
 */

#include "Date.h"
ostream& operator <<(ostream& os, Date *d) {
    os << d->GetDay() << "/" << d->GetMonth() << "/" << d->GetYear() << " " << d->GetHour() << ":" << d->GetMin();
    return os;
}
Date::Date(int day, int month, int year, int hour, int min) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->min = min;
}


Date::Date(const Date& orig) {
}

Date::~Date() {
}




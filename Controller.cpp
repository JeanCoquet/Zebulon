/* 
 * File:   Controller.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 8:34 PM
 */

#include "Controller.h"

Controller::Controller() {
         this->schedule = loadSchedule(); //constructeur statique au lieu de dynamique
    
}

Schedule* Controller::loadSchedule(){
    return NULL;
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}


/* 
 * File:   main.cpp
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:28
 */

#include <iostream>
#include "Controller.h"
#include "sqlite/lib/sqlite3.h"
#include "sqlite/Database.h"


using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main(int argc, char** argv) {    
    Controller *ctrl;
    try{
         ctrl = new Controller();
    }catch(int){
        cout<<"Error while Controller initialisation."<<endl;
        return (1);
    }
}




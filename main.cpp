/* 
 * File:   main.cpp
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:28
 */

#include <iostream>
#include "Controller.h"
#include "sqlite/lib/sqlite3.h"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main(int argc, char** argv) {
    
//---- test sqlite ----
    sqlite3 *database;
    
    if(sqlite3_open("./sqlite/Zebulon_database.sqlite", &database) == SQLITE_OK) {
        cout<<"Database is open"<<endl;
        
        string sql = "SELECT * FROM Table_test";
        char *zErrMsg = 0;
        
        int rc = sqlite3_exec(database, sql.c_str(), callback, 0, &zErrMsg);
        if(rc != SQLITE_OK) {
            cout<<"Error sql"<<endl;
            sqlite3_free(zErrMsg);
        }
        
        sqlite3_close(database);
    }
    
    
//---------------------
    
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i=0; i<argc; i++) {
        cout<<azColName[i]<<" : "<<argv[i]<<endl;
    }
    return 0;
}


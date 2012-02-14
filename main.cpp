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
 
    
    Database *database = new Database();
    list< list<string> >* result = database->request("select * from Studient");
    
    
    list< list<string> >::iterator it = result->begin();
    list< list<string> >::const_iterator MaxList = result->end();
    
    for(;it != MaxList; it++){
        //cout<<"ligne magenta\n";
       list<string>::const_iterator MaxListList = it->end();
       list<string>::iterator itList = it->begin();
       for(;itList!=MaxListList;itList++){
           //cout<<"ligne pourpre\n";
           cout<<*itList<<" 8)";
       }
       cout<<"#"<<endl;
    }






    
//---- test sqlite ----
   /* sqlite3 *database;
    
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
    */
    
//---------------------
    
}




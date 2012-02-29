/* 
 * File:   Database.cpp
 * Author: bicodul
 * 
 * Created on February 10, 2012, 4:54 PM
 */
#include <iostream>
#include "Database.h"
using namespace std;

list< list<string> >* Database::request(string request) throw(int){
   list< list<string> >* result = new list< list<string> >();
   char *zErrMsg = NULL;
   cout<<"execution de la requete : "<<request<<endl;
   int rc = sqlite3_exec(this->database, request.c_str(), callback, (void*)result, &zErrMsg);
   cout<<"requete executee"<<endl;
   if(rc != SQLITE_OK) {
        cout<<"Error sql"<<endl;
        sqlite3_free(zErrMsg);
        throw 1;
        return NULL;
   }
   return result;
}

int Database::callback(void *result, int argc, char **argv, char **azColName) {
    cout<<"traitement de la ligne"<<endl;
    list<string>* line = new list<string>();
    for(int i=0 ; i<argc ; i++){
         line->push_back(argv[i]);    
    }
    ((list< list<string> >*)result)->push_back(*line);
    return 0;
}


Database::Database() {
    if(sqlite3_open("./sqlite/Zebulon_database.sqlite", &database) == SQLITE_OK) {
        cout<<"Database is open"<<endl;
    }
}

Database::Database(const Database& orig) {
}

Database::~Database() {
       sqlite3_close(database);
}


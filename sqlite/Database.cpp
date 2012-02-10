/* 
 * File:   Database.cpp
 * Author: bicodul
 * 
 * Created on February 10, 2012, 4:54 PM
 */

#include "Database.h"


list< list<string> >* Database::request(string request, int numberOfColumns){
   result = new list< list<string> >();
   char *zErrMsg = NULL;
   int rc = sqlite3_exec(database, request.c_str(), callback, (void*)&numberOfColumns, &zErrMsg);
   if(rc != SQLITE_OK) {
        cout<<"Error sql"<<endl;
        sqlite3_free(zErrMsg);
        return NULL;
   }
   return result;
}

static int Database::callback(void *nbOfColumns, int argc, char **argv, char **azColName) {
    int i = 0;
    list<string>* line;
    while(i<argc){
        line = new list();
        for(int j=0; j<*((int*)nbOfColumns);j++){
            line->push_back(argv[i++]);
        }
        this->result->push_back(*line);
    }
    return 0;
}

Database::Database() {
    result = NULL;
    if(sqlite3_open("./sqlite/Zebulon_database.sqlite", &database) == SQLITE_OK) {
        cout<<"Database is open"<<endl;
    }
}

Database::Database(const Database& orig) {
}

Database::~Database() {
       sqlite3_close(database);
       delete result[];
}


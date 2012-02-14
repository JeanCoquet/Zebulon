/* 
 * File:   Database.cpp
 * Author: bicodul
 * 
 * Created on February 10, 2012, 4:54 PM
 */
#include <iostream>
#include "Database.h"
using namespace std;
int Database::coucou(void *nbOfColumns, int argc, char **argv, char **azColName){
    cout << "salut\n";
    return 1;
}
list< list<string> >* Database::request(string request){
   list< list<string> >* result = new list< list<string> >();
   char *zErrMsg = NULL;
   int rc = sqlite3_exec(this->database, request.c_str(), callback, (void*)result, &zErrMsg);
   if(rc != SQLITE_OK) {
        cout<<"Error sql"<<endl;
        sqlite3_free(zErrMsg);
        return NULL;
   }
   return result;
}

int Database::callback(void *result, int argc, char **argv, char **azColName) {
    //cout<<"fonction callback\n";
    int i = 0;
    list<string>* line = new list<string>();
    string colName0 = azColName[0];
    while(i<argc){
        //cout<<"boucle mauve -> "<<argv[i]<<"\n";
        line->push_back(argv[i]);     
        cout<<"COLNAME:"<<azColName[i]<<" COL0:"<<colName0<<endl;
        if(colName0 == azColName[i+1]){
            //cout<<"condition rouge\n";
            ((list< list<string> >*)result)->push_back(*line);
            line = new list<string>();
        }
        i++;
        //cout<<"apres test bleu\n";
    }
    //cout<<"fin de la fonction callback\n";
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


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
    list< list<string> >* result = database->request("select * from student");
    if(result == NULL){
        cout<<"requete invalide\n";
        return 1;
    }
    list< list<string> >::iterator it = result->begin();
    list< list<string> >::const_iterator MaxList = result->end();
    cout<<"Affichage arc en ciel!!\n";
    for(;it != MaxList; it++){
        //cout<<"ligne magenta\n";
       list<string>::const_iterator MaxListList = it->end();
       list<string>::iterator itList = it->begin();
       for(;itList!=MaxListList;itList++){    
           cout<<*itList<<" ";
       }
       cout<<"#"<<endl;
    }    
    
}




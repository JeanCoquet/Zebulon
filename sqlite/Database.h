/* 
 * File:   Database.h
 * Author: bicodul
 *
 * Created on February 10, 2012, 4:54 PM
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include <list>
#include <string>
#include "sqlite/lib/sqlite3.h"
using namespace std;

class Database {
public:
    Database();
    Database(const Database& orig);
    virtual ~Database();
    list< list<string> >* request(string request);
    
private:
    sqlite3 *database;
    static int callback(void*, int, char**, char**);
    list< list<string> >* result;
};

#endif	/* DATABASE_H */


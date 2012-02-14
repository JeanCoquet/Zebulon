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
#include "lib/sqlite3.h"
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
    static int coucou(void *nbOfColumns, int argc, char **argv, char **azColName);

};

#endif	/* DATABASE_H */


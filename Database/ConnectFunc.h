//? CONNECT TO SQLite Database Section
//? THIS FILE IS TO STORE ALL THE CONNECTION INFO

#ifndef CONNECTFUNC_H
#define CONNECTFUNC_H

#define CONNECT_FAIL    0
#define CONNECT_SUCCESS 1
#define CLOSE_SUCCESS   2

#include <sqlite3.h>
#include <string>
#include <iostream>

// RETURN CONNECT STATUS
int connectSQLite(std::string path_to_db, sqlite3** ppDb);
int closeSQLite(sqlite3* ppDb);

int connectSQLite(std::string path_to_db, sqlite3** ppDB)
{
    int success = sqlite3_open_v2("projects.db", ppDB, SQLITE_OPEN_READWRITE, NULL);
    if (success == SQLITE_ERROR)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(*ppDB) << std::endl;
        return CONNECT_FAIL;
    }
    return CONNECT_SUCCESS;
}

int closeSQLite(sqlite3* ppDB)
{
    sqlite3_close_v2(ppDB);
    return CLOSE_SUCCESS;
}
#endif
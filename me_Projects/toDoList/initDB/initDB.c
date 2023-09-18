#include "initDB.h"

int initDb(sqlite3** db){
    int rc = sqlite3_open("toDo.db",db);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }

    const char* create_table_sql = "CREATE TABLE IF NOT EXISTS tasks ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "taskName TEXT NOT NULL"
                                ");";

    
    rc = sqlite3_exec(*db,create_table_sql,0,0,0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(*db));
        sqlite3_close(*db);
        return rc;
    }
    return SQLITE_OK;
}
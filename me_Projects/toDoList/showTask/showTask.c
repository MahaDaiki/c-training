#include "./showTask.h"
#include "../task.h" 

void showTask(sqlite3* db){
    const char* sql = "SELECT * FROM tasks;";
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }

    printf("\t\t\t****************TASKS******************\n");
    while((rc = sqlite3_step(stmt)) == SQLITE_ROW){
        int id = sqlite3_column_int(stmt,0);
        const char* taskName = (const char*)sqlite3_column_text(stmt,1);
        printf("\t\t\t\t\t %d ,  %s \n", id, taskName);
        printf("\t\t\t--------------------------------------\n");
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }




}
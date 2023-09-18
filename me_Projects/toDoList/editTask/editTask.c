#include "editTask.h"

int editTask(sqlite3* db){
    const char* sql = "UPDATE tasks SET taskName = ? WHERE id = ? ;";
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    int id;
    char taskName[20];
    printf("\t\t\t\tEnter task Id : \n");
    scanf("%d",&id);
    printf("\t\t\t\tEnter task name : \n");
    scanf("%s",taskName);

    sqlite3_bind_text(stmt, 1, taskName, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("xxx");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);

    return rc;

}
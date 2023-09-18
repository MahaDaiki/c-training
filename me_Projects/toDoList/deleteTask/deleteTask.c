#include "./deleteTask.h"
#include "../task.h" 

int deleteTask(sqlite3* db){
    const char* sql ="DELETE FROM tasks WHERE id = ?;";
    sqlite3_stmt* stmt;
    int rc;

    rc=sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    int id;
    printf("\t\t\t\tEnter task Id : \n");
    scanf("%d",&id);

    sqlite3_bind_int(stmt,1,id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("xxx");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);

    return rc;
}
#include "./addTask.h"
#include "../task.h" 

int addTask(sqlite3* db){
    char another;
    char sql[1000];
    sqlite3_stmt* stmt;

    struct Task newTask;
    
	do{
        printf("\t\t\t\tEnter task name : \n");scanf("\t\t\t%s",newTask.name);

        // Create an SQL INSERT statement with placeholders for name and age
    snprintf(sql, sizeof(sql), "INSERT INTO tasks (taskName) VALUES (?);");

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("hhhh");
        return rc;
    }

    // Bind the parameters (name and age)
    sqlite3_bind_text(stmt, 1, newTask.name, -1, SQLITE_STATIC);
    

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("xxx");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement
    
    sqlite3_finalize(stmt);

    return rc;



	
        printf("Do you want to add another task? (y/n): ");
        scanf(" %c", &another); 
	 }while(another == 'y' || another == 'Y');
}
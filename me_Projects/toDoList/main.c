#include "main.h"

int main(){
    int choice,rc;
    sqlite3* db = NULL;
    rc = initDb(&db);
    if(rc != SQLITE_OK){
        return 1;
    }
    while(1){
        printf("\t\t\t****************TODO LIST**************\n");
        printf("\t\t\t\t 1 : Add New task  \n");
        printf("\t\t\t\t 2 : Edit Task  \n");
        printf("\t\t\t\t 3 : Show Tasks  \n");
        printf("\t\t\t\t 4 : Delete Task  \n");
        printf("\t\t\t\t 5 : Exit  \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            rc = addTask(db);
            if (rc != SQLITE_OK)
            {
                printf("\t\t\t\t Task added succesufly \n");
            }
            
            break;
        case 2 :
            rc = editTask(db);
            if (rc != SQLITE_OK)
            {
                printf("\t\t\t\t Task edited succesufly \n");
            }
            break;
        case 3 :
            showTask(db);
            break;
        case 4 :
            rc = deleteTask(db);
            if (rc != SQLITE_OK)
            {
                printf("\t\t\t\t Task deleted succesufly \n");
            }
            break;
        case 5 :
            sqlite3_close(db);
			return 0;
        default:
            printf("\t\t\t Invalid choice \n");
            break;
        }
    }
    
}
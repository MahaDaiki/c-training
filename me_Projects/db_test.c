#include<stdio.h>
#include <sqlite3.h>
#include<stdlib.h>
#include<stdlib.h>
struct employee{
	int id;
	char nom[20];
	char prenom[20];
	int age;
};
int addEmployee();
void showEmployees();
void saveEmployeeData();
int initializeDatabase(sqlite3** db) {
    int rc = sqlite3_open("employee_db.db", db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
        printf("aaaad");
        return rc;
    }

    const char* create_table_sql = "CREATE TABLE IF NOT EXISTS employees ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                   "first_name TEXT NOT NULL,"
                                   "second_name TEXT NOT NULL,"
                                   "age INT NOT NULL"
                                   ");";

    rc = sqlite3_exec(*db, create_table_sql, 0, 0, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(*db));
        printf("ddd");
        sqlite3_close(*db);
        return rc;
    }

    return SQLITE_OK;
}

int main(){

    

    int choice;
	printf("Employee Management System \n");
    sqlite3* db;
    int rc = initializeDatabase(&db);

    if (rc != SQLITE_OK) {
        return 1;
    }
	while(1){
		printf("\n*************** MENU *************\n");
		printf("1 . Add Employee \n");
		printf("2 . Show Employees \n");
		printf("3 . Exit \n");

		scanf("%d",&choice);
		switch(choice){
			case 1 :
                rc = addEmployee(db);
                if (rc == SQLITE_OK) {
                    printf("Employee added successfully!\n");
                }

    sqlite3_close(db);
				break;
			case 2 :showEmployees();
				break;
			case 3 : 
				return 0;
			default : printf("Invalid choice\n");

		}

	}


}

int addEmployee(sqlite3* db){
    char another;
    char sql[1000];
    sqlite3_stmt* stmt;
    

	do{
	struct employee newEmployee;

        printf("Enter employee ID  ");
        scanf("%d", &newEmployee.id);


	// if(isIdInUse(newEmployee.id)){
	//     printf("Employee ID %d is already in use. Please choose a different ID.\n",newEmployee.id);
    //         continue;
	// }
        printf("Enter employee first name: ");
        scanf("%s", newEmployee.nom);

        printf("Enter employee last name: ");
        scanf("%s", newEmployee.prenom);

        printf("Enter employee age: ");
        scanf("%d", &newEmployee.age);

        // Create an SQL INSERT statement with placeholders for name and age
    snprintf(sql, sizeof(sql), "INSERT INTO employees (first_name, second_name, age) VALUES (?, ?, ?);");

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("hhhh");
        return rc;
    }

    // Bind the parameters (name and age)
    sqlite3_bind_text(stmt, 1, newEmployee.nom, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newEmployee.prenom, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, newEmployee.age);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("xxx");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement
    printf("Employee added succe");
    sqlite3_finalize(stmt);

    return rc;



	saveEmployeeData(newEmployee);
        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &another); 
	 }while(another == 'y' || another == 'Y');
}

void showEmployees(){

}
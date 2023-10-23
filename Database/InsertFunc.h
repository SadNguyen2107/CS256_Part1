#ifndef INSERTFUNC_H
#define INSERTFUNC_H

#define INSERT_FAIL 0
#define INSERT_SUCCESS 1

#include <string>
#include "../Base/Group.h"
#include "../Base/Project.h"
#include <sqlite3.h>

int insertStudentInfo(sqlite3 *DB, Student *student, int group_id);
int insertGroupInfo(sqlite3 *DB, Group *group, int group_id);
int insertProjectInfo(sqlite3 *DB, Project *project, int project_id);
int insertSubmitDate(sqlite3 *DB, Date *submitDate, int group_id, int project_id);

// INSERT INTO students table in projects.db
int insertStudentInfo(sqlite3 *DB, Student *student)
{
    // SET FLAG
    int success = INSERT_SUCCESS;

    // The prepared statment object
    sqlite3_stmt *stmt = nullptr;
    const char *sql_statement = "INSERT INTO students VALUES (:id, :name, NULL)";

    // Prepare the SQL Statement
    // The sql_statement -> byte-code
    int rc = sqlite3_prepare_v2(DB, sql_statement, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(DB) << std::endl;

        // Finalize the statement and close the database
        sqlite3_finalize(stmt);

        return INSERT_FAIL;
    }

    int id = student->student_id;
    const char *student_name = (student->student_name).c_str();

    // Bind the paramenter
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, student_name, -1, SQLITE_STATIC);

    // Execute the prepared statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        // ERROR OCCUR
        std::cerr << "Error: " << sqlite3_errmsg(DB) << std::endl;
        success = INSERT_FAIL;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);

    return success;
}

// INSERT GROUP INFO into groups tale
int insertGroupInfo(sqlite3 *DB, Group *group, int group_id)
{
    // SET FLAG
    int success = INSERT_SUCCESS;

    // The prepared statment object
    sqlite3_stmt *stmt = nullptr;
    const char *sql_statement = "INSERT INTO groups VALUES (:id, :name)";

    // Prepare the SQL Statement
    // The sql_statement -> byte-code
    int rc = sqlite3_prepare_v2(DB, sql_statement, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(DB) << std::endl;

        // Finalize the statement and close the database
        sqlite3_finalize(stmt);

        return INSERT_FAIL;
    }

    int id = group_id;
    const char *group_name = (group->getGroupName()).c_str();

    // Bind the paramenter
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, group_name, -1, SQLITE_STATIC);

    // Execute the prepared statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        // ERROR OCCUR
        std::cerr << "Error: " << sqlite3_errmsg(DB) << std::endl;
        success = INSERT_FAIL;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);

    return success;
}

int insertProjectInfo(sqlite3 *DB, Project *project, int id)
{
    int success = INSERT_SUCCESS;
    sqlite3_stmt *stmt = nullptr;
    const char *sql_statement = "INSERT INTO projects VALUES(:id, :description, :due_date)";
    int rc = sqlite3_prepare_v2(DB, sql_statement, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(DB) << std::endl;

        // Finalize the statement and close the database
        sqlite3_finalize(stmt);

        return INSERT_FAIL;
    }
    // get ID
    sqlite3_bind_int(stmt, 1, id);

    // get description
    std::string d = project->getDescription();
    const char *desc = d.c_str();
    sqlite3_bind_text(stmt, 2, desc, -1, SQLITE_STATIC);

    // get date-time
    unsigned short year = project->getDueDate()->getYear();
    unsigned short month = project->getDueDate()->getMonth();
    unsigned short day = project->getDueDate()->getDay();

    std::string date_string = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    const char *res = date_string.c_str();
    sqlite3_bind_text(stmt, 3, res, -1, SQLITE_STATIC);

    // int id = project->id;
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        // ERROR OCCUR
        std::cerr << "Error: " << sqlite3_errmsg(DB) << std::endl;
        success = INSERT_FAIL;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);

    return success;
}
int insertSubmitDate(sqlite3 *DB, Date *submitDate, int group_id, int project_id)
{
    int success = INSERT_SUCCESS;
    sqlite3_stmt *stmt = nullptr;
    const char *sql_statement = "INSERT INTO groups_submit_dates VALUES(:project_id, :group_id, :submit_date)";
    int rc = sqlite3_prepare_v2(DB, sql_statement, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(DB) << std::endl;

        // Finalize the statement and close the database
        sqlite3_finalize(stmt);

        return INSERT_FAIL;
    }
    // get ID
    sqlite3_bind_int(stmt, 1, project_id);

    sqlite3_bind_int(stmt, 2, group_id);

    // get date-time
    unsigned short year = submitDate->getYear();
    unsigned short month = submitDate->getMonth();
    unsigned short day = submitDate->getDay();

    std::string date_string = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    const char *res = date_string.c_str();
    sqlite3_bind_text(stmt, 3, res, -1, SQLITE_STATIC);

    // int id = project->id;
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        // ERROR OCCUR
        std::cerr << "Error: " << sqlite3_errmsg(DB) << std::endl;
        success = INSERT_FAIL;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);

    return success;
}
#endif
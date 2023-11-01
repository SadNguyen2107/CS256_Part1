#include <bits/stdc++.h>
#include "./Validate/ValidateFile.h"
#include "./Functions/Display_Func.h"
#include "./Validate/ValidateRegex.h"
#include "./Validate/ValidateFunc.h"
#include "./Functions/Extract_Data_Func.h"
#include "./Functions/Other_Func.h"
#include "./Functions/Group_Func.h"
#include "./Functions/Project_Func.h"
#include "./src/include/json.hpp"
#include <sqlite3.h>
#include <cstring>
using namespace std;
int main()
{
    std::vector<Group *> groups;
    std::vector<Project *> projects;

    // int groups_size = askUserNumberOfGroups();
    // groups = std::vector<Group*>(groups_size);
    // for (int group_index = 0; group_index < groups_size; group_index++)
    // {
    //     groups[group_index] = inputGroupInfo(group_index);
    // }

    // int projects_size = askUserNumberOfProjects();
    // projects = std::vector<Project*>(projects_size);
    // for (int project_index = 0; project_index < projects_size; project_index++)
    // {
    //     projects[project_index] = inputProjectInfo(project_index);
    // }
    // saveProjectsInfo(&projects, "OutputFiles/ProjectInfo.txt" );

    // extractGroupInfoFile(&groups, "InputFiles/GroupInfo.txt");

    // for (size_t index = 0; index < groups.size(); index++)
    // {
    //     if (groups[index] != nullptr)
    //     {
    //         std::cout << groups[index] << std::endl;
    //     }
    // }

    // Date *date = new Date(10, 12, 2003);
    // Project *project = new Project("Hello World", date);
    // project->addSubmissionDate(4, date);

    // Date *new_date = new Date(30, 12, 2004);
    // project->addSubmissionDate(10, new_date);

    // projects.push_back(project);
    // // std::cout << project << std::endl;

    // displayTableTest(&groups, &projects);

    // std::ifstream fileObj("test.json");
    // json data = json::parse(fileObj);

    // std::cout << data["happy"] << std::endl;

    // std::string filePath = "";
    // if (std::strcmp(OS_NAME, "Windows") == 0)
    // {
    //     while (true)
    //     {
    //         int success = getFileTxtPathWindow(filePath);
    //         if (success == SUCCESS)
    //         {
    //             std::cout << filePath << std::endl;
    //             if (isRightFile(filePath, GROUP_INFO_FILE))
    //             {
    //                 std::cout << "Right File" << std::endl;
    //                 break;
    //             }
    //             else
    //             {
    //                 std::cerr << "Wrong File!!!" << std::endl;
    //             }
    //         }
    //         else if (success == FAIL)
    //         {
    //             std::cerr << "Could not get the file!!!" << std::endl;
    //             break;
    //         }
    //     }
    // }

    // The Database connection object
    sqlite3 *DB = nullptr;
    int exit = 0;

    // Open the SQLite database file
    exit = sqlite3_open_v2("projects.db", &DB, SQLITE_OPEN_READWRITE, NULL);
    std::cout << exit << std::endl;
    if (exit == SQLITE_ERROR)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;

    // The prepared statment object
    sqlite3_stmt *stmt = nullptr;
    const char *sql_statement = "SELECT * FROM projects WHERE id = :id AND due_date = :due_date";

    // Prepare the SQL Statement
    // The sql_statement -> byte-code
    int rc = sqlite3_prepare_v2(DB, sql_statement, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(DB) << std::endl;
    }

    int id = 1;
    const char* due_date = "21/07/2003";

    //? Find the index of the PLACEHOLDER in the Statement
    int index = sqlite3_bind_parameter_index(stmt, ":due_date");
    std::cout << index << std::endl;

    // Bind the paramenter
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, due_date, -1, SQLITE_STATIC);

    // Execute the prepared statement
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        // Process the result set
        const unsigned char* resultColumn1 = sqlite3_column_text(stmt, 2);
        // You can access other columns here as well.
        std::cout << "Result: " << resultColumn1 << std::endl;
    }

    // For Insert
    rc = sqlite3_step(stmt);
    while (rc != SQLITE_DONE)
    {
        //? HANDLE THE ERROR
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);

    // CLOSE THE CONNECTION
    sqlite3_close(DB);

    return 0;
}
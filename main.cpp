#include "./GUI/Windows/GetFileWindow.h"
#include "./GUI/ValidateOS.h"
#include "./Functions/Display_Func.h"
#include "./Validate/ValidateRegex.h"
#include "./Functions/Extract_Data_Func.h"
#include "./src/include/json.hpp"
#include <sqlite3.h> 
#include <cstring>

using json = nlohmann::json;

int main(int argc, char const *argv[])
{
    //? To Store numbers of Groups AND PROJECTS
    std::vector<Group *> groups;
    std::vector<Project *> projects;

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
    // sqlite3 *DB;
    // int exit = 0;
    // exit = sqlite3_open("C:\\Users\\User\\OneDrive - Hanoi University of Science and Technology\\Desktop\\shows.db", &DB);

    // if (exit)
    // {
    //     std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
    //     return (-1);
    // }
    // else
    //     std::cout << "Opened Database Successfully!" << std::endl;
    // sqlite3_close(DB);

    if (std::strcmp(OS_NAME, "Windows") == 0)
    {
        std::string filePath = getFilePathWindow();
        std::cout << filePath << std::endl;
    }
    
    return 0;
}


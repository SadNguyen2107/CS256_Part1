#include "./Base/Project.h"
#include "./Base/Group.h"
#include "./Functions/Display_Func.h"

int main(int argc, char const *argv[])
{
    //? To Store numbers of Groups AND PROJECTS
    std::vector<Group *> groups;
    std::vector<Project *> projects;

    Date *date = new Date(10, 12, 2003);
    Project *project = new Project("Hello World", date);
    project->addSubmissionDate(4, date);

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

    // if (std::strcmp(OS_NAME, "Windows") == 0)
    // {
    //     while (true)
    //     {
    //         std::string filePath = getFileTxtPathWindow();
    //         if (isRightFile(filePath, 1))
    //         {
    //             std::cout << "Right File" << std::endl;
    //             break;
    //         }
    //         else
    //         {
    //             std::cerr << "Wrong File!!!" << std::endl;
    //         }
    //     }
    // }

    return 0;
}

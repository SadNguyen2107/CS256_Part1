#ifndef OTHERFUNC_H
#define OTHERFUNC_H

#include <string>
#include <iostream>
#include <limits>
#include "../Validate/ValidateFunc.h"
#include "../Validate/ValidateRegex.h"
#include "../Validate/ValidateFile.h"
#include "../Base/Project.h"

int askUserNumberOfGroups();
int askUserNumberOfProjects();
int askGroupIDToSubmit();
int askProjectIDToSubmit();
std::string askUserFileDirectory();
void quitProgram();

int askUserNumberOfGroups()
{
    int numGroups = 0;
    std::string numGroups_string = "";

    // ENTER NUMBER GROUPS
    std::cout << "Enter the number of groups: ";
    std::cin >> numGroups_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numGroups_string = getValueAfterValidate(numGroups_string, validateID);
    numGroups = std::stoi(numGroups_string);

    std::cout << "================================================\n";

    return numGroups;
}
int askUserNumberOfProjects()
{
    int numProjects = 0;
    std::string numProjects_string = "";

    // ENTER NUMBER PROJECTS
    std::cout << "Enter the number of projects: ";
    std::cin >> numProjects_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numProjects_string = getValueAfterValidate(numProjects_string, validateID);
    numProjects = std::stoi(numProjects_string);

    std::cout << "================================================\n";

    return numProjects;
}
int askGroupIDToSubmit()
{
    int groupID = 0;
    std::string groupID_string = "";

    // ENTER NUMBER PROJECTS
    std::cout << "Enter the Group ID to submit: ";
    std::cin >> groupID_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    groupID_string = getValueAfterValidate(groupID_string, validateID);
    groupID = std::stoi(groupID_string);

    std::cout << "================================================\n";

    return groupID;
}
int askProjectIDToSubmit()
{
    int projectID = 0;
    std::string projectID_string = "";

    // ENTER NUMBER PROJECTS
    std::cout << "Enter the Project ID to submit: ";
    std::cin >> projectID_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    projectID_string = getValueAfterValidate(projectID_string, validateID);
    projectID = std::stoi(projectID_string);

    std::cout << "================================================\n";

    return projectID;
}
std::string askUserFileDirectory()
{
    string fileGroups = "";
    string fileProjects = "";
    int option = 0;
    int groupsInfo = 0;

    std::vector<Group *> groups;
    std::vector<Project *> projects;

    // ASK INPUT
    cout << "Load corporation from file(1) or input from terminal(2)? ";
    std::cin >> option;
    while (!(option == 1 || option == 2))
    {
        std::cout << "Enter the option again!!!!!!" << endl;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Do File Path
    if (option == 1)
    {
        // ASK PEOPLE FILE PATH GROUPS
        cout << "Enter groups file Path: ";
        std::cin >> fileGroups;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (!isRightFile(fileGroups, GROUP_INFO_FILE))
        {
            cout << "Wrong file! Enter groups file Path Again: ";
            std::getline(std::cin, fileGroups);
        }
        //! VAILIDATE FILE PATH GROUPS
        fileGroups = getValueAfterValidate(fileGroups, validateFileTxt);
        std::cout << fileGroups << " has been loaded successfully!\n";

        // ASK PEOPLE FILE PATH PROJECTS
        std::cout << "Enter projects file Path: ";
        std::cin >> fileProjects;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (!isRightFile(fileProjects, PROJECT_INFO_FILE))
        {
            cout << "Wrong file! Enter projects file Path Again: ";
            std::getline(std::cin, fileProjects);
        }
        //! VAILIDATE FILE PATH PROJECTS
        fileProjects = getValueAfterValidate(fileProjects, validateFileTxt);
        std::cout << fileProjects << " has been loaded successfully!\n";

        //! PREVENT MEMORY LEAK
        delete &groups;
        delete &projects; 
        // Load data from file
        groupsInfo = extractGroupInfoFile(&groups, fileGroups);
        extractProjectInfoFile(&projects, groupsInfo,fileProjects);

    }
    // Do Terminal
    else if (option == 2)
    {
        delete &groups;
        delete &projects;  //! PREVENT MEMORY LEAK
        groupsInfo = extractGroupInfoFile(&groups, fileGroups);
        extractProjectInfoFile(&projects, groupsInfo,fileProjects);
    }
}
void quitProgram()
{
    exit(0);
}
#endif

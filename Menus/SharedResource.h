#ifndef SHARED_RESOURCE_H
#define SHARED_RESOURCE_H

#include "../GUI/ValidateOS.h"
#include "../Validate/ValidateFile.h"
#include "../Functions/Display_Func.h"
#include "../Validate/ValidateRegex.h"
#include "../Validate/ValidateFunc.h"
#include "../Functions/Extract_Data_Func.h"
#include "../Functions/Other_Func.h"
#include "../Functions/Group_Func.h"
#include "../Functions/Project_Func.h"
#include "../Base/Project.h"
#include "../Base/Group.h"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <thread>

// Define Menu Message
#define QUIT_PROGRAM 0

#define INPUT_FAIL 1
#define INPUT_SUCCESS 2

// Define Menu Constants
#define MENU_CONSTANTS_H

// To Store Vector All the Groups
std::vector<Group *> groups;

// To Store Vector All the Projects
std::vector<Project *> projects;

// Create namespace menu 1 to reuse the same constants after that without causing conflicts due to redefinitions
namespace Menu1
{
    extern const int AddGroup;
    extern const int DisplayGroupInfo;
    extern const int QuitProgram;
}

namespace Menu2
{
    extern const int AddGroups;
    extern const int AddProjects;
    extern const int DisplayGroupInfo;
    extern const int DisplayProjectInfo;
    extern const int QuitProgram;
}

namespace Menu3
{
    extern const int AddGroups;
    extern const int AddProjects;
    extern const int SubmitProjects;
    extern const int DisplayAll;
    extern const int DisplayGroupInfo;
    extern const int DisplayProjectInfo;
    extern const int DisplaySubmissionSpecificDate;
    extern const int DisplayGroupsSubmitOnTime;
    extern const int DisplayGroupsTurnInLate;
    extern const int QuitProgram;
}

void cleanUpResources()
{
    std::cout << "Cleaning Resources In Progress...\n";

    for (int i = 0; i < groups.size(); i++)
    {
        delete[] groups[i];
    }
    for (int i = 0; i < projects.size(); i++)
    {
        delete[] projects[i];
    }
    std::cout << "\nCleaned Everything Before Quitting\n";
    std::cout << "Thank You!\n";
}

// void cleanUpResources()
// {
//     std::cout << "Cleaning Resources In Progress...\n";

//     // Assuming groups and projects are vectors of pointers to dynamically allocated objects
//     for (auto group : groups) {
//         delete group;  // Delete each dynamically allocated object in groups
//     }
//     groups.clear();  // Clear the vector

//     for (auto project : projects) {
//         delete project;  // Delete each dynamically allocated object in projects
//     }
//     projects.clear();  // Clear the vector

//     std::cout << "Cleaned Everything Before Quitting\n";
//     std::cout << "Thank You!\n";
// }

void askUserInputMethodForGroup()
{
    // Display The Menu And Get The User's Choice
    int inputMethodChoiceForGroup;
    std::cout << "What Method Would You Like To Use?\n";
    std::cout << "1. Input From File\n";
    std::cout << "2. Input From Terminal\n";
    std::cout << "Your Choice: ";
    std::cin >> inputMethodChoiceForGroup;

    if (inputMethodChoiceForGroup == 1)
    {
        std::string filePath = askUserFileGroupsDirectory();
        extractGroupInfoFile(&groups, filePath);
    }

    else if (inputMethodChoiceForGroup == 2)
    {
        int numOfGroups = askUserNumberOfGroups();

        // ALocate AMount of Space
        groups = std::vector<Group *>(numOfGroups);

        for (int group_index = 0; group_index < numOfGroups; group_index++)
        {
            groups[group_index] = inputGroupInfo(group_index);
        }

        std::string filePath = "OutputFiles/GroupInfo.txt";
        saveGroupsInfo(&groups, filePath);
    }

    else
    {
        std::cout << "Invalid Option, Only Option 1 and 2. Please Try Again!\n";
    }
}

void askUserInputMethodForProject()
{
    // Display The Menu And Get The User's Choice
    int inputMethodChoiceForProject;
    std::cout << "What Method Would You Like To Use?\n";
    std::cout << "1. Input From File\n";
    std::cout << "2. Input From Terminal\n";
    std::cout << "Your Choice: ";
    std::cin >> inputMethodChoiceForProject;

    if (inputMethodChoiceForProject == 1)
    {
        int number_of_groups;
        std::string filePath = askUserFileProjectsDirectory();
        extractProjectInfoFile(&projects, groups.size(), filePath);   
        
    }
    
    else if (inputMethodChoiceForProject == 2)
    {
        int numOfProjects = askUserNumberOfProjects();
        projects.resize(numOfProjects);  // Resize the Projects size according to Num Of Projects

        for (int project_index = 0; project_index < numOfProjects; project_index++)
        {
            projects[project_index] = inputProjectInfo(project_index);
        }

        std::string filePath = "OutputFiles/ProjectInfo.txt";
        saveProjectsInfo(&projects, filePath);
    }

    else
    {
        std::cout << "Invalid Option, Only Option 1 And 2. Please Try Again!\n";
    }
}

#endif
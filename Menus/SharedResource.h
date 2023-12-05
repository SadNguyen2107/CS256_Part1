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

void askUserInputMethodForGroup();
void askUserInputMethodForProject();
int getUserChoice();
bool back();
void quitProgram();

void askUserInputMethodForGroup()
{
    // Display The Menu And Get The User's Choice
    int inputMethodChoiceForGroup = 0;
    string inputMethodChoiceForGroup_string = "";
    do
    {
        std::cout << "What Method Would You Like To Use?\n";
        std::cout << "1. Input From File\n";
        std::cout << "2. Input From Terminal\n";
        std::cout << "Your Choice: ";
        std::cin >> inputMethodChoiceForGroup_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMethodChoiceForGroup_string = getValueAfterValidate(inputMethodChoiceForGroup_string, validateID);
        inputMethodChoiceForGroup = std::stoi(inputMethodChoiceForGroup_string);

        if (inputMethodChoiceForGroup == 1)
        {
            std::string filePath = askUserFileGroupsDirectory();
            extractGroupInfoFile(&groups, filePath);
        }

        else if (inputMethodChoiceForGroup == 2)
        {
            int numOfGroups = askUserNumberOfGroups();
            groups.resize(numOfGroups);

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
    } while (inputMethodChoiceForGroup != 1 && inputMethodChoiceForGroup != 2);
}

void askUserInputMethodForProject()
{
    // Display The Menu And Get The User's Choice
    int inputMethodChoiceForProject = 0;
    string inputMethodChoiceForProject_string = "";
    do
    {
        std::cout << "What Method Would You Like To Use?\n";
        std::cout << "1. Input From File\n";
        std::cout << "2. Input From Terminal\n";
        std::cout << "Your Choice: ";
        std::cin >> inputMethodChoiceForProject_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMethodChoiceForProject_string = getValueAfterValidate(inputMethodChoiceForProject_string, validateID);
        inputMethodChoiceForProject = std::stoi(inputMethodChoiceForProject_string);

        if (inputMethodChoiceForProject == 1)
        {
            std::string filePath = askUserFileProjectsDirectory();
            extractProjectInfoFile(&projects, groups.size(), filePath);
        }

        else if (inputMethodChoiceForProject == 2)
        {
            int numOfProjects = askUserNumberOfProjects();
            projects.resize(numOfProjects); // Resize the Projects size according to Num Of Projects

            projects = std::vector<Project *>(numOfProjects);

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
    } while (inputMethodChoiceForProject != 1 && inputMethodChoiceForProject != 2);
}

int getUserChoice()
{
    std::string choice_string;

    std::cout << "Please enter your choice: ";

    int choice;
    std::cin >> choice_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    choice_string = getValueAfterValidate(choice_string, validateID);
    choice = std::stoi(choice_string);
    return choice;
}

// Ask User to go back to the menu or exit the program
bool back()
{
    std::string backOrNotChoice;

    while (true)
    {
        std::cout << "Do you want to go back to the menu? (y/n): ";
        std::getline(std::cin, backOrNotChoice);

        if (backOrNotChoice == "y" || backOrNotChoice == "Y")
        {
            return true;
        }
        else if (backOrNotChoice == "n" || backOrNotChoice == "N")
        {
            return false;
        }
        else
        {
            cout << "Invalid choice. Please enter 'Y' or 'N'.\n";
        }
    }
}
void quitProgram()
{
    std::cout << "EXITTING THE PROGRAM...\n";

    for (std::vector<Group *>::size_type i = 0; i < groups.size(); i++)
    {
        if (groups[i] != nullptr)
        {
            delete groups[i];
        }
    }
    for (std::vector<Project *>::size_type i = 0; i < projects.size(); i++)
    {
        if (projects[i] != nullptr)
        {
            delete projects[i];
        }
    }
    groups.clear();
    projects.clear();
    std::cout << "Cleaned Everything Before Quitting\n";
    std::cout << "Thank You!\n";

    exit(0);
}

#endif
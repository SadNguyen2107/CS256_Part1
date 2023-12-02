#ifndef OTHERFUNC_H
#define OTHERFUNC_H

#include "../Menus/SharedResource.h"

// To Store Vector All the Groups
std::vector<Group *> groups;

// To Store Vector All the Projects
std::vector<Project *> projects;

int askUserNumberOfGroups();
int askUserNumberOfProjects();
int askGroupIDToSubmit();
int askProjectIDToSubmit();
std::string askUserFileGroupsDirectory();
std::string askUserFileProjectsDirectory();
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
    std::cout << "Enter the VALID Group ID to submit: ";
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
    std::cout << "Enter the VALID Project ID to submit: ";
    std::cin >> projectID_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    projectID_string = getValueAfterValidate(projectID_string, validateID);
    projectID = std::stoi(projectID_string);

    std::cout << "================================================\n";

    return projectID;
}
std::string askUserFileGroupsDirectory()
{
    string fileGroups = "";

    std::vector<Group *> groups;

    // ASK PEOPLE FILE PATH GROUPS
    cout << "Enter groups file Path: ";
    std::cin >> fileGroups;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!isRightFile(fileGroups, GROUP_INFO_FILE))
    {
        std::cout << "Wrong file! Enter groups file Path Again: ";
        std::getline(std::cin, fileGroups);
    }
    //! VAILIDATE FILE PATH GROUPS
    fileGroups = getValueAfterValidate(fileGroups, validateFileTxt);
    std::cout << fileGroups << " has been loaded successfully!\n";

    return fileGroups;
}

std::string askUserFileProjectsDirectory()
{
    string fileProjects = "";

    std::vector<Project *> projects;

    // ASK PEOPLE FILE PATH PROJECTS
    cout << "Enter projects file Path: ";
    std::cin >> fileProjects;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!isRightFile(fileProjects, PROJECT_INFO_FILE))
    {
        std::cout << "Wrong file! Enter projects file Path Again: ";
        std::getline(std::cin, fileProjects);
    }
    //! VAILIDATE FILE PATH PROJECTS
    fileProjects = getValueAfterValidate(fileProjects, validateFileTxt);
    std::cout << fileProjects << " has been loaded successfully!\n";

    return fileProjects;
}

bool confirmExit()
{
    std::string userInput;
    std::cout << "Are you sure you want to exit? (y/n): ";
    std::getline(std::cin, userInput);
    while (true)
    {
        if (userInput == "Y" || userInput == "y")
        {
            quitProgram();
            return true;
        }
        else if (userInput == "N" || userInput == "n")
        {
            return false;
        }
        else
        {
            std::cout << "Invalid input. Please enter 'y' or 'n'\n";
        }
    }
}

void BackOrNot(bool &continueProgram)
{
    std::string backOrNotChoice;

    while (true)
    {
        std::cout << "Do you want to go back to the menu? (y/n): ";
        std::cin >> backOrNotChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (backOrNotChoice == "y" || backOrNotChoice == "Y")
        {
            break;
        }
        else if (backOrNotChoice == "n" || backOrNotChoice == "N")
        {
            if (confirmExit())
            {
                continueProgram = false;
                break; // Exit the loop and end the program
            }
        }
        else
        {
            std::cout << "Invalid choice. Please enter 'Y' or 'N'.\n";
        }
    }
}
void quitProgram()
{
    std::cout << "Cleaning Resources In Progress...\n";

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
    // for (Group *group : groups)
    // {
    //     delete group;
    // }

    // for (Project *project : projects)
    // {
    //     delete project;
    // }

    groups.clear();
    projects.clear();
    std::cout << "Cleaned Everything Before Quitting\n";
    std::cout << "Thank You!\n";

    exit(0);
}

#endif

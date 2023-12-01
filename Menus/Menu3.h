#ifndef MENU3_H
#define MENU3_H

#include "../Menus/SharedResource.h"
#include "Menu2.h"

std::vector<Project *>::size_type projectID = 0;
std::vector<Group *>::size_type groupID = 0;
// Constants Representing Menu Options For Menu 3
namespace Menu3
{
    const int AddGroups = 1;
    const int AddProjects = 2;
    const int SubmitProjects = 3;
    const int DisplayAll = 4;
    const int DisplayGroupInfo = 5;
    const int DisplayProjectInfo = 6;
    const int DisplaySubmissionSpecificDate = 7;
    const int DisplayGroupsSubmitOnTime = 8;
    const int DisplayGroupsTurnInLate = 9;
    const int QuitProgram = 10;
}

int getUserChoice();
std::queue<std::tuple<int, Group *>> groupsInfo;

// Function To Display Menu 3 Options
void displayMenu3()
{

    int menuWidth = 47;
    for (int i = 0; i < menuWidth; i++)
    {
        std::cout << "-";
    }

    std::cout << "\n";
    std::cout << "|                 Print menu                  |\n"
              << "|---------------------------------------------|\n"
              << "|  1.  Input A New Group                      |\n"
              << "|  2.  Input A New Project                    |\n"
              << "|  3.  Submit Project                         |\n"
              << "|  4.  Display All Info                       |\n"
              << "|  5.  Display Info About Group ID            |\n"
              << "|  6.  Display Info About Project ID          |\n"
              << "|  7.  Display Submission To A Specific Date  |\n"
              << "|  8.  Display Groups Submit On Time          |\n"
              << "|  9.  Display Groups Turn In Late            |\n"
              << "|  10. Quit The Program                       |\n";

    for (int i = 0; i < menuWidth; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

// Maps User's Choice To Actions For Menu 3 And Handles Input Validation, User Interactions And Program Flows
int mapUserChoiceToActionMenu3(int userChoiceM3)
{
    bool continueProgram = true;
    switch (userChoiceM3)
    {
    case Menu3::AddGroups:
        askUserInputMethodForGroup();
        BackOrNot(continueProgram);
        break;

    case Menu3::AddProjects:
        askUserInputMethodForProject();
        BackOrNot(continueProgram);
        break;

    case Menu3::SubmitProjects:

        // Ask for project and group IDs and update them by reference
        projectID = askProjectIDToSubmit();
        groupID = askGroupIDToSubmit();

        submitProject(projects[projectID -1 ], groupID);

        BackOrNot(continueProgram);
        break;

    case Menu3::DisplayAll:
        displayAllTable(&groups, &projects);
        BackOrNot(continueProgram);
        break;

    case Menu3::DisplayGroupInfo:
        displayGroupsInfo(&groups);
        if (groups.empty())
        {
            bool continueProgram = true;
        }
        BackOrNot(continueProgram);
        break;

    case Menu3::DisplayProjectInfo:
        displayProjectsInfo(&projects);
        if (projects.empty())
        {
            std::cout << "Please Return To Menu To Perform This Task!\n";
            BackOrNot(continueProgram);
        }
        BackOrNot(continueProgram);
        break;

    case Menu3::DisplaySubmissionSpecificDate:
        showSubmissionToASpecificDate(&groups, &projects);
        BackOrNot(continueProgram);
        break;

    case Menu3::DisplayGroupsSubmitOnTime:
        findGroupsCompleteOnTime(&groups, &projects);
        printGroups(groupsInfo, GROUP_ON_TIME);
        BackOrNot(continueProgram);
        break;

    case Menu3::DisplayGroupsTurnInLate:

        findGroupsNotCompleteOnTime(&groups, &projects);
        printGroups(groupsInfo, GROUP_LATE);
        BackOrNot(continueProgram);
        break;

    case Menu3::QuitProgram:
        quitProgram();

    default:
        std::cout << "Invalid Option. Please Try Again!\n";
        BackOrNot(continueProgram);
        break;
    }
    return userChoiceM3;
}

int loadMenu3()
{
    bool continueProgram = true;
    while (continueProgram)
    {
        displayMenu3();
        int choice = getUserChoice();
        int status = mapUserChoiceToActionMenu3(choice);
        if (status == QUIT_PROGRAM || status == INPUT_FAIL)
        {
            continueProgram = false;
        }
    }
    return 0;
}

#endif
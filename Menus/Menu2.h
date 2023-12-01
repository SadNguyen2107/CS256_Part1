#ifndef MENU2_H
#define MENU2_H

#include "../Menus/SharedResource.h"
#include "Menu1.h"

// Constants Representing Menu Options For Menu 2
namespace Menu2
{
    const int AddGroups = 1;
    const int AddProjects = 2;
    const int DisplayGroupInfo = 3;
    const int DisplayProjectInfo = 4;
    const int QuitProgram = 5;
}

int getUserChoice();
int loadMenu3();

// Function To Display Menu 2 Options
void displayMenu2()
{
    int menuWidth = 47;
    for (int i = 0; i < menuWidth; i++)
    {
        std::cout << "-";
    }

    std::cout << "\n";
    std::cout << "|                 Print menu                  |\n"
              << "|---------------------------------------------|\n"
              << "|  1. Input A New Group                       |\n"
              << "|  2. Input A New Project                     |\n"
              << "|  3. Display Info About Group ID             |\n"
              << "|  4. Display Info About Project ID           |\n"
              << "|  5. Quit The Program                        |\n";

    for (int i = 0; i < menuWidth; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

// Maps User's Choice To Actions For Menu 2 And Handles Input Validation, User Interactions And Program Flows
int mapUserChoiceToActionMenu2(int userChoiceM2)
{
    bool continueProgram = true;
    switch (userChoiceM2)
    {
    case Menu2::AddGroups:
        askUserInputMethodForGroup();
        BackOrNot(continueProgram);
        break;

    case Menu2::AddProjects:
        askUserInputMethodForProject();
        loadMenu3();
        BackOrNot(continueProgram);
        break;
        
    case Menu2::DisplayGroupInfo:
        displayGroupsInfo(&groups);
        if (groups.empty())
        {
            bool continueProgram = true;
        }
        BackOrNot(continueProgram);
        break;

    case Menu2::DisplayProjectInfo:
        displayProjectsInfo(&projects);
        if (projects.empty())
        {
            std::cout << "Please Return To Menu To Perform This Task!\n";
            BackOrNot(continueProgram);
        }
        BackOrNot(continueProgram);
        break;

    case Menu2::QuitProgram:
        quitProgram();

    default:
        std::cout << "Invalid Option. Please Try Again!\n";
        BackOrNot(continueProgram);
        break;
    }
    return userChoiceM2;
}

// Function to load and manage menu 2
int loadMenu2()
{
    bool continueProgram = true;
    while (continueProgram)
    {
        displayMenu2();
        int choice = getUserChoice();
        int status = mapUserChoiceToActionMenu2(choice);
        if (status == QUIT_PROGRAM || status == INPUT_FAIL)
        {
            continueProgram = false;
        }
    }
    return 0;
}

#endif
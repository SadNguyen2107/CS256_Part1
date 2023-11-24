#ifndef MENU1_H
#define MENU1_H

#include "..\Menus\SharedResource.h"
#include "Menu2.h"

// Constants Representing Menu Options For Menu 1
namespace Menu1
{
    const int AddGroups = 1;
    const int DisplayGroupInfo = 2;
    const int QuitProgram = 3;
}

int loadMenu2();

// Function To Display Menu 1 Options
void displayMenu1()
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
              << "|  2. Display Info About Group ID             |\n"
              << "|  3. Quit The Program                        |\n";

    for (int i = 0; i < menuWidth; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

// Receive Input And Validate From User
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

// Maps User's Choice To Actions For Menu 1 And Handles Input Validation, User Interactions And Program Flows 
int mapUserChoiceToActionMenu1(int userChoiceM1)
{
    bool continueProgram = true;
    switch (userChoiceM1)
    {
    case Menu1::AddGroups:
        askUserInputMethodForGroup();
        loadMenu2();
        return INPUT_SUCCESS;

    case Menu1::DisplayGroupInfo:
        displayGroupsInfo(&groups);
        if(groups.empty())
        {
            std::cout << "Please Return To Menu To Perform This Task!\n";
            BackOrNot(continueProgram);
        }
        return INPUT_SUCCESS;

    case Menu1::QuitProgram:
        if (confirmExit() == true)
        {
            cleanUpResources();
            return QUIT_PROGRAM;
        }
        break;

    default:
        std::cout << "Invalid Option. Please Try Again!\n"; 
        BackOrNot(continueProgram);
    }
    return INPUT_FAIL;
}

// Function to load and mangage menu 1
int loadMenu1()
{
    bool continueProgram = true;
    while (continueProgram)
    {
        displayMenu1();
        int choice = getUserChoice();
        int status = mapUserChoiceToActionMenu1(choice);

        if (status == QUIT_PROGRAM || status == INPUT_FAIL)
        {
            continueProgram = false;
        }
    }
    return 0;
}

#endif
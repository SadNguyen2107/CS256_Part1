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

void loadMenu1()
{
    while (true)
    {
        // Print Menu 1
        std::cout << "-----------------------------------------------\n";
        std::cout << "|                 Print menu                  |\n"
                  << "|---------------------------------------------|\n"
                  << "|  1. Input A New Group                       |\n"
                  << "|  2. Display Infomation All Group            |\n"
                  << "|  3. Quit The Program                        |\n";
        std::cout << "-----------------------------------------------\n";

        // Option in Menu 1
        int choiceMenu1 = getUserChoice();
        switch (choiceMenu1)
        {
        case Menu1::AddGroups:
            // If None OF the group is input
            if (groups.size() <= 0)
            {
                askUserInputMethodForGroup();
            }
            // Else That Vector has already have at least 1 group then append
            else
            {
                groups.push_back(inputGroupInfo(groups.size()));

                int new_size = groups.size();
                for (size_t index = 0; index < projects.size(); index++)
                {
                    resizeSubmissionDates(projects[index], new_size);
                }
            }
            loadMenu2();

        case Menu1::DisplayGroupInfo:
            displayGroupsInfo(&groups);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu1::QuitProgram:
            quitProgram();

        default:
            std::cout << "Invalid Option. Please Try Again!\n";
            if (!back())
            {
                quitProgram();
            }
        }
    }
}

#endif
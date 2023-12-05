#ifndef MENU2_H
#define MENU2_H

#include "../Menus/SharedResource.h"
#include "Menu3.h"

// Constants Representing Menu Options For Menu 2
namespace Menu2
{
    const int AddGroups = 1;
    const int AddProjects = 2;
    const int DisplayGroupInfo = 3;
    const int DisplayProjectInfo = 4;
    const int QuitProgram = 5;
}

void loadMenu2()
{
    while (true)
    {
        // Print Menu 2
        std::cout << "-----------------------------------------------\n";
        std::cout << "|                 Print menu                  |\n"
                  << "|---------------------------------------------|\n"
                  << "|  1. Input A New Group                       |\n"
                  << "|  2. Input A New Project                     |\n"
                  << "|  3. Display Infomation All Group            |\n"
                  << "|  4. Display Infomation All Project          |\n"
                  << "|  5. Quit The Program                        |\n";
        std::cout << "-----------------------------------------------\n";

        // Option in Menu2
        int choiceMenu2 = getUserChoice();
        switch (choiceMenu2)
        {
        case Menu2::AddGroups:
            askUserInputMethodForGroup();
            saveGroupsInfo(&groups, "OutputFiles/GroupInfo.txt");
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu2::AddProjects:
            askUserInputMethodForProject();
            saveProjectsInfo(&projects, "OutputFiles/ProjectInfo.txt");
            loadMenu3();
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu2::DisplayGroupInfo:
            displayGroupsInfo(&groups);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu2::DisplayProjectInfo:
            displayProjectsInfo(&projects);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu2::QuitProgram:
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
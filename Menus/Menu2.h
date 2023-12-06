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
                  << "|  1. Input New Group                         |\n"
                  << "|  2. Input New Project (require to upload)   |\n"
                  << "|  3. Display Infomation All Group            |\n"
                  << "|  4. Display Infomation All Project          |\n"
                  << "|  5. Quit The Program                        |\n";
        std::cout << "-----------------------------------------------\n";

        // Option in Menu2
        int choiceMenu2 = getUserChoice();
        switch (choiceMenu2)
        {
        case Menu2::AddGroups:
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
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu2::AddProjects:
            if (projects.size() <= 0)
            {
                askUserInputMethodForProject();
            }
            else
            {
                Project *newProject = inputProjectInfo(projects.size());
                projects.push_back(newProject);

                // Add PlaceHolder For The Submission Dates
                size_t groups_size = groups.size();
                for (size_t group = 1; group <= groups_size; group++)
                {
                    resizeSubmissionDates(newProject, group);
                }
            }
            std::system("cls");
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
            std::system("cls");
            break;

        case Menu2::DisplayProjectInfo:
            displayProjectsInfo(&projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu2::QuitProgram:
            quitProgram();

        default:
            std::cout << "Invalid Option. Please Try Again!\n";
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
        }
    }
}

#endif
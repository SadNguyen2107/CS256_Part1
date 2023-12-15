#ifndef MENU3_H
#define MENU3_H

#include "../Menus/SharedResource.h"
#include "Menu2.h"

// Constants Representing Menu Options For Menu 3
namespace Menu3
{
    const int AddGroups = 1;
    const int AddProjects = 2;
    const int SubmitProjects = 3;
    const int DisplayAll = 4;
    const int DisplayGroupInfo = 5;
    const int DisplayByGroup = 6;
    const int DisplayProjectInfo = 7;
    const int DisplayByProject = 8;
    const int DisplaySubmissionSpecificDate = 9;
    const int DisplayGroupsSubmitOnTime = 10;
    const int DisplayGroupsTurnInLate = 11;
    const int QuitProgram = 12;
}

void loadMenu3()
{
    while (true)
    {
        // Print Menu 3
        std::cout << "-----------------------------------------------\n";
        std::cout << "|                 Print menu                  |\n"
                  << "|---------------------------------------------|\n"
                  << "|  1.  Input A New Group                      |\n"
                  << "|  2.  Input A New Project                    |\n"
                  << "|  3.  Submit Project                         |\n"
                  << "|  4.  Display All Info                       |\n"
                  << "|  5.  Display Infomation All Group           |\n"
                  << "|  6.  Display Infomation by GroupID          |\n"
                  << "|  7.  Display Infomation All Project         |\n"
                  << "|  8.  Display Infomation by ProjectID        |\n"
                  << "|  9.  Display Submission To A Specific Date  |\n"
                  << "|  10. Display Groups Submit On Time          |\n"
                  << "|  11. Display Groups Turn In Late            |\n"
                  << "|  12. Quit The Program                       |\n";
        std::cout << "-----------------------------------------------\n";

        // Option in Menu 3
        int choiceMenu3 = getUserChoice();
        switch (choiceMenu3)
        {
        case Menu3::AddGroups:
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

        case Menu3::AddProjects:
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

            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::SubmitProjects:
            submitProject(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayAll:
            displayAllTable(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayGroupInfo:
            displayGroupsInfo(&groups);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayByGroup:
            displayByGroup(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayProjectInfo:
            displayProjectsInfo(&projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayByProject:
            displayByProject(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplaySubmissionSpecificDate:
            showSubmissionToASpecificDate(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayGroupsSubmitOnTime:
            printGroups(findGroupsCompleteOnTime(&groups, &projects), GROUP_ON_TIME);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::DisplayGroupsTurnInLate:
            printGroups(findGroupsNotCompleteOnTime(&groups, &projects), GROUP_LATE);
            if (!back())
            {
                quitProgram();
            }
            std::system("cls");
            break;

        case Menu3::QuitProgram:
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
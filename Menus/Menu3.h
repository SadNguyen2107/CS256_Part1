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
    const int DisplayProjectInfo = 6;
    const int DisplaySubmissionSpecificDate = 7;
    const int DisplayGroupsSubmitOnTime = 8;
    const int DisplayGroupsTurnInLate = 9;
    const int QuitProgram = 10;
}

void loadMenu3()
{
    // Declare variable used in this function
    std::queue<std::tuple<int, Group *>> groupsCompleteOnTime = findGroupsCompleteOnTime(&groups, &projects);
    std::queue<std::tuple<int, Group *>> groupsNotCompleteOnTime = findGroupsNotCompleteOnTime(&groups, &projects);
    std::vector<Project *>::size_type projectID = 0;
    std::vector<Group *>::size_type groupID = 0;

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
                  << "|  6.  Display Infomation All Project         |\n"
                  << "|  7.  Display Submission To A Specific Date  |\n"
                  << "|  8.  Display Groups Submit On Time          |\n"
                  << "|  9.  Display Groups Turn In Late            |\n"
                  << "|  10. Quit The Program                       |\n";
        std::cout << "-----------------------------------------------\n";

        // Option in Menu 3
        int choiceMenu3 = getUserChoice();
        switch (choiceMenu3)
        {
        case Menu3::AddGroups:
            askUserInputMethodForGroup();
            saveGroupsInfo(&groups, "OutputFiles/GroupInfo.txt");
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::AddProjects:
            askUserInputMethodForProject();
            saveProjectsInfo(&projects, "OutputFiles/ProjectInfo.txt");
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::SubmitProjects:

            // Ask for project and group IDs and update them by reference
            projectID = askProjectIDToSubmit();
            groupID = askGroupIDToSubmit();

            submitProject(projects[projectID - 1], groupID);

            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplayAll:
            displayAllTable(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplayGroupInfo:
            displayGroupsInfo(&groups);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplayProjectInfo:
            displayProjectsInfo(&projects);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplaySubmissionSpecificDate:
            showSubmissionToASpecificDate(&groups, &projects);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplayGroupsSubmitOnTime:
            printGroups(groupsCompleteOnTime, GROUP_ON_TIME);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::DisplayGroupsTurnInLate:
            printGroups(groupsNotCompleteOnTime, GROUP_LATE);
            if (!back())
            {
                quitProgram();
            }
            break;

        case Menu3::QuitProgram:
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
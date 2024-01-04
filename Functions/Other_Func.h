#ifndef OTHERFUNC_H
#define OTHERFUNC_H

#include "../Menus/SharedResource.h"

// To Store Vector All the Groups
std::vector<Group *> groups;

// To Store Vector All the Projects
std::vector<Project *> projects;

int askUserNumberOfGroups();
int askUserNumberOfProjects();
std::string askUserFileGroupsDirectory();
std::string askUserFileProjectsDirectory();
void saveSubmissionsInfo(std::vector<Project *> *projects, std::vector<Group *> *groups, std::string filePath);

int askGroupIDToSubmit()
{
    int groupID = 0;
    std::string groupID_string = "";

    // ENTER NUMBER PROJECTS
    std::cout << "Enter the Group ID to submit: ";
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
    std::cout << "Enter the Project ID to submit: ";
    std::cin >> projectID_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    projectID_string = getValueAfterValidate(projectID_string, validateID);
    projectID = std::stoi(projectID_string);

    std::cout << "================================================\n";

    return projectID;
}
int askUserNumberOfGroups()
{
    int numGroups = 0;
    std::string numGroups_string = "";

    // ENTER NUMBER GROUPS
    do {
        std::cout << "Enter the number of groups (must be at least 1): ";
        std::cin >> numGroups_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numGroups_string = getValueAfterValidate(numGroups_string, validateID);
        numGroups = std::stoi(numGroups_string);

        if (numGroups < 1) {
            std::cout << "Error: Number of groups must be at least 1. Please enter a valid number.\n";
        }
    } while (numGroups < 1);

    std::cout << "================================================\n";

    return numGroups;
}
int askUserNumberOfProjects()
{
    int numProjects = 0;
    std::string numProjects_string = "";

    // ENTER NUMBER PROJECTS
    do {
        std::cout << "Enter the number of projects (must be at least 1): ";
        std::cin >> numProjects_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numProjects_string = getValueAfterValidate(numProjects_string, validateID);
        numProjects = std::stoi(numProjects_string);

        if (numProjects < 1) {
            std::cout << "Error: Number of projects must be at least 1. Please enter a valid number.\n";
        }
    } while (numProjects < 1);

    std::cout << "================================================\n";

    return numProjects;
}
std::string askUserFileGroupsDirectory()
{
    std::string fileGroups = "";

    std::vector<Group *> groups;

    int getfile;
    do
    {
        getfile = getFileTxtPathWindow(fileGroups);

        if (getfile == SUCCESS && isRightFile(fileGroups, GROUP_INFO_FILE))
        {
            std::cout << "Selected file path: " << fileGroups << std::endl;
        }
        else
        {
            std::cout << "Wrong file!!! Please choose the correct file." << std::endl;
        }

    } while (getfile != SUCCESS || !isRightFile(fileGroups, GROUP_INFO_FILE));

    return fileGroups;
}

std::string askUserFileProjectsDirectory()
{
    std::string fileProjects = "";

    std::vector<Project *> projects;

    int getfile;
    do
    {
        getfile = getFileTxtPathWindow(fileProjects);

        if (getfile == SUCCESS && isRightFile(fileProjects, PROJECT_INFO_FILE))
        {
            std::cout << "Selected file path: " << fileProjects << std::endl;
        }
        else
        {
            std::cout << "Wrong file!!! Please choose the correct file." << std::endl;
        }

    } while (getfile != SUCCESS || !isRightFile(fileProjects, PROJECT_INFO_FILE));

    return fileProjects;
}

void saveSubmissionsInfo(std::vector<Project *> *projects, std::vector<Group *> *groups, std::string filePath)
{
    std::ofstream file(filePath);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    // Write To File
    file << "Group_ID\tDates\n";

    size_t projects_length = projects->size();
    size_t groups_length = groups->size();

    //? CHECK WHICH LENGTH IS LARGER
    if (groups_length >= projects_length) // THEN CHOOSE THE GROUP_INDEX AS THE PIVOT
    {
        size_t project_index = 0;

        //? INFOMATION
        for (std::vector<Group *>::size_type rows = 0; rows < groups->size(); rows++)
        {
            int times = 0; // To Know How Many Times It Print
            if (times == 1)
            {
                break;
            }

            file << rows + 1 << "\t";
            for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
            {
                Project *project = projects->at(project_index);
                std::vector<Date *> submission_dates = project->getSubmissionDateCopy();

                Date *date = submission_dates[rows];
                if (date != nullptr)
                {
                    file << date->getDay() << "/" << date->getMonth() << "/" << date->getYear() << "\t";
                }
                else
                {
                    file << "Unknown"
                         << "\t";
                }

                times++;
            }
            file << "\n";

            if (project_index + 1 < projects_length)
            {
                project_index++;
            }

            times++;
        }
    }
    //------------------------------------------------------------------------------------------------------------

    else // THEN CHOOSE THE PROJECT_INDEX AS THE PIVOT
    {
        size_t group_index = 0;

        //? INFOMATION
        for (std::vector<Project *>::size_type rows = 0; rows < projects->size(); rows++)
        {
            int times = 0; // To Know How Many Times It Print
            if (times == 1)
            {
                break;
            }

            file << group_index + 1 << "\t";

            for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
            {
                Project *project = projects->at(project_index);
                std::vector<Date *> submission_dates = project->getSubmissionDateCopy();

                Date *date = submission_dates[rows];
                if (date != nullptr)
                {
                    file << date->getDay() << "/" << date->getMonth() << "/" << date->getYear() << "\t";
                }
                else
                {
                    file << "Unknown"
                         << "\t";
                }
            }
            file << "\n";
            group_index++;
            if (group_index >= groups_length)
            {
                break;
            }

            times++;
        }
    }
    //------------------------------------------------------------------------------------------------------------

    // Close The File
    file.close();
}

#endif

#ifndef PROJECTFUNC_H
#define PROJECTFUNC_H
#include <iostream>
#include <string>
#include <vector>
#include "../Base/Project.h"
#include "../Base/Date.h"
#include "../Base/Date.h"
#include "../Validate/ValidateFunc.h"
#include "../Validate/ValidateRegex.h"
#include <fstream>
using namespace std;

// PROTOTYPE
Project *inputProjectInfo(int project_index);
void displayProjectsInfo(std::vector<Project *> *projects);
void submitProject(std::vector<Group *> *groups, std::vector<Project *> *projects);
void saveProjectsInfo(std::vector<Project *> *projects, std::string filePath);

Project *inputProjectInfo(int project_index)
{
    cout << "Project " << project_index + 1 << " Information:" << endl;
    std::cout << "================================================\n";

    string description;
    cout << "Description: ";
    getline(cin, description);

    string dueDateString = "";
    do
    {
        cout << "Due date (DD/MM/YYYY): ";
        getline(cin, dueDateString);

        //! VALIDATE dueDate FORMAT
        dueDateString = getValueAfterValidate(dueDateString, validateDate);
    } while (isSmallerOrEqualThanToday(dueDateString));

    // CREATE Date Object
    Date *dueDate = new Date(dueDateString);

    // Create a new Project object and add it to the vector
    Project *project = new Project(description, dueDate);

    std::cout << "================================================\n";
    cout << "Project " << project_index + 1 << " added successfully." << endl;

    return project;
}

void displayProjectsInfo(std::vector<Project *> *projects)
{
    if (projects->empty())
    {
        std::cout << "There are no projects to display." << std::endl;
        return;
    }
    else
    {
        // Iterate over the vector of projects and display their information
        for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
        {
            std::cout << "Project #" << project_index + 1 << ":" << std::endl;
            std::cout << "Description:" << std::left << projects->at(project_index)->getDescription() << std::endl;
            std::cout << "Due Date: " << projects->at(project_index)->getDueDate() << std::endl;
            std::cout << "+==============================================================+\n";
        }
    }
}
void saveProjectsInfo(std::vector<Project *> *projects, std::string filePath)
{
    std::ofstream file;
    file.open(filePath, std::ios::out | std::ios::trunc);

    if (file.is_open())
    {
        file << "ProjectNumber   Due_date    Description\n";
        for (std::vector<Project *>::size_type i = 0; i < projects->size(); i++)
        {
            // WRITE PROJECT NUMBER
            file << i + 1 << "\t";

            // WRITE DUE DATE
            const Date *dueDate = projects->at(i)->getDueDate();
            if (dueDate != nullptr)
            {
                file << dueDate->getDay() << "/" << dueDate->getMonth() << "/" << dueDate->getYear() << "\t";
            }
            else
            {
                file << "N/A\t"; // No due date specified
            }

            // WRITE PROJECT DESCRIPTION

            file << projects->at(i)->getDescription() << "\n";
        }

        file.close();
    }
    else
    {
        std::cout << "Error opening file: " << filePath << std::endl;
    }
}
void submitProject(std::vector<Group *> *groups, std::vector<Project *> *projects)
{
    std::string projectNumber_string = "";
    std::vector<Project *>::size_type projectNumber = 0;
    do
    {
        std::cout << "Enter the VALID project number you want to submit: ";
        std::cin >> projectNumber_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        projectNumber_string = getValueAfterValidate(projectNumber_string, validateID);
        projectNumber = std::stoi(projectNumber_string);
    } while (projectNumber < 1 || projectNumber > projects->size());

    std::string submissionDateStr = "";
    // ENTER SUBMISSION DATE OF THAT GROUP
    std::cout << "Enter the submission date (DD/MM/YYYY): ";
    std::getline(std::cin, submissionDateStr);
    submissionDateStr = getValueAfterValidate(submissionDateStr, validateDate);

    Date *submissionDate = new Date(submissionDateStr);

    for (std::vector<Group *>::size_type group_index = 0; group_index < groups->size(); group_index++)
    {
        std::string option = "";
        do
        {
            std::cout << "Group " << group_index + 1 << " submit project " << projectNumber << "? (ONLY[y/n]): ";
            std::getline(std::cin, option);
        } while (option != "y" && option != "Y" && option != "n" && option != "N");

        if (option == "y" || option == "Y")
        {
            (*projects)[projectNumber - 1]->addSubmissionDate(group_index + 1, submissionDate);
            std::cout << "Group " << group_index + 1 << " submitted Project " << projectNumber << " successfully on " << submissionDateStr << "." << std::endl;
        }
    }
    std::cout << "================================================\n";
}

#endif
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
void submitProject(Project *project, int groupID);
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
void submitProject(Project *project, int groupID)
{
    string submissionDateStr = "";
    // ENTER SUBMISSION DATE OF THAT GROUP
    cout << "Enter the submission date (DD/MM/YYYY): ";
    getline(cin, submissionDateStr);
    submissionDateStr = getValueAfterValidate(submissionDateStr, validateDate);

    Date *submissionDate = new Date(submissionDateStr);

    project->addSubmissionDate(groupID, submissionDate);

    cout << "Project submitted successfully on " << submissionDateStr << "." << endl;
}
#endif
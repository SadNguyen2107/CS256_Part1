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
Project* inputProjectInfo(int project_index);
void submitProject(std::vector<Project*>* projects);
void saveProjectsInfo(std::vector<Project*>* projects, std::string filePath);

Project* inputProjectInfo(int project_index)
{
    cout << "Project " << project_index + 1 << " Information:" << endl;

    string description;
    cout << "Description: ";
    getline(cin, description);

    string dueDateString = "";
    do
    {
        cout << "Input VALID Due date (DD/MM/YYYY): ";
        getline(cin, dueDateString);

        //! VALIDATE dueDate FORMAT
        dueDateString = getValueAfterValidate(dueDateString, validateDate);
    }
    while(isSmallerOrEqualThanToday(dueDateString));

    // CREATE Date Object
    Date* dueDate = new Date(dueDateString);

    // Create a new Project object and add it to the vector
    Project* project = new Project(description, dueDate);

    cout << "Project " << project_index + 1 << " added successfully." << endl;
    return project;
}

void saveProjectsInfo(std::vector<Project*>* projects, std::string filePath)
{
    std::ofstream file;
    file.open(filePath, std::ios::out | std::ios::trunc);

    if (file.is_open())
    {
        file << "ProjectNumber   Due_date    Description\n";
        for (std::vector<Project*>::size_type i = 0; i < projects->size(); i++)
        {
            // WRITE PROJECT NUMBER
            file << i + 1 << "\t";

            // WRITE DUE DATE
            const Date* dueDate = projects->at(i)->getDueDate();
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
void submitProject(std::vector<Project*>* projects)
{
    int groupNumber = 0;
    string groupNumber_string = "";

    // ENTER NUMBER OF GROUP
    cout << "Enter the group number that is submitting the project: ";
    cin >> groupNumber_string;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    groupNumber_string = getValueAfterValidate(groupNumber_string, validateID);
    groupNumber = std::stoi(groupNumber_string);


    string submissionDateStr = "";

    //ENTER SUBMISSION DATE OF THAT GROUP
    cout << "Enter the submission date (DD/MM/YYYY): ";
    getline(cin, submissionDateStr);
    submissionDateStr = getValueAfterValidate(submissionDateStr, validateDate);

    Date* submissionDate = new Date(submissionDateStr);

    cout << "Project for group " << groupNumber << " submitted successfully on " << submissionDateStr << "." << endl;

    projects->at(groupNumber - 1)->addSubmissionDate(groupNumber, submissionDate); 
}
#endif
#ifndef PROJECTFUNC_H
#define PROJECTFUNC_H
#include <iostream>
#include <string>
#include <vector>
#include "../Base/Project.h"
#include "../Base/Date.h"
#include "../Validate/ValidateFunc.h"
#include "../Validate/ValidateRegex.h"
using namespace std;

// PROTOTYPE
void inputProjectsInfo(std::vector<Project *>* projects);
void submitProject(std::vector<Project*>* projects);

void inputProjectsInfo(vector<Project *>* projects){
    int numProjects;
    cout << "Enter the number of projects: ";
    cin >> numProjects;

    for (int i = 1; i <= numProjects; ++i)
    {
        cout << "Project " << i << " Information:" << endl;

        string description;
        cout << "Description: ";
        cin.ignore();
        getline(cin, description);

        string dueDateStr;
        cout << "Submission Deadline (DD/MM/YYYY): ";
        cin >> dueDateStr;

        //! VALIDATE dueDate FORMAT
        dueDateStr = getValueAfterValidate(dueDateStr, validateDate);

        // CREATE Date Object
        Date* dueDate = new Date(dueDateStr);

        // Create a new Project object and add it to the vector
        Project* project = new Project(description, dueDate);
        projects->push_back(project);

        cout << "Project " << i << " added successfully." << endl;
    }
}

#endif
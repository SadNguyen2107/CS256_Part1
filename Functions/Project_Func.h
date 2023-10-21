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
Project* inputProjectInfo(int project_index);
void submitProject(std::vector<Project*>* projects);

Project* inputProjectInfo();

<<<<<<< HEAD
Project* inputProjectInfo(int project_index)
{
    cout << "Project " << project_index + 1 << " Information:" << endl;

    string description;
    cout << "Description: ";
    cin.ignore();
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
=======
Project* inputProjectInfo();

>>>>>>> 6eccf9999e459d22bbe9ce80c2e5b8aad0ff9acc
#endif
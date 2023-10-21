#ifndef OTHERFUNC_H
#define OTHERFUNC_H

#include <string>
#include <iostream>
#include <limits>
#include "../Validate/ValidateFunc.h"
#include "../Validate/ValidateRegex.h"

int askUserNumberOfGroups();
int askUserNumberOfProjects();
std::string askUserFileDirectory();
void quitProgram();

int askUserNumberOfGroups(){
    int numGroups = 0;
    std::string numGroups_string = "";

    // ENTER NUMBER GROUPS
    std::cout << "Enter the number of groups: ";
    std::cin >> numGroups_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numGroups_string = getValueAfterValidate(numGroups_string, validateID);
    numGroups = std::stoi(numGroups_string);

    std::cout << "================================================\n";

    return numGroups;
}

int askUserNumberOfProjects(){
    int numProjects = 0;
    std::string numProjects_string= "";

    //ENTER NUMBER PROJECTS
    std::cout << "Enter the number of projects: ";
    std::cin >> numProjects_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numProjects_string = getValueAfterValidate(numProjects_string, validateID);
    numProjects = std::stoi(numProjects_string);

    std::cout << "================================================\n";

    return numProjects;
}

#endif
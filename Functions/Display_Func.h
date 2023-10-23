#ifndef DISPLAYFUNC_H
#define DISPLAYFUNC_H

#include "../Base/Project.h"
#include "../Base/Group.h"
#include <queue>

void displayByProject(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayByGroup(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);

void displayByGroup(std::vector<Group *> *groups, std::vector<Project *> *projects){
    std::cout << "Enter the group index: ";
    int group_index;
    std::cin >> group_index;

    // Group *group = groups->at(group_index);

    for (Project *project : *projects) {
            std::vector<Date*> submission_dates = project->getSubmissionDateCopy();
            Date* submission_date_group = submission_dates[group_index - 1];

            std::cout << "Project name: " << project->getDescription() << std::endl;
            std::cout << "Submission date: " << submission_date_group << std::endl;
            std::cout << "State: " << checkState(project->getDueDate(), submission_date_group) << std::endl;
            std::cout << std::endl;
        }
}

#endif
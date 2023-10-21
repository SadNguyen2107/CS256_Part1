#ifndef DISPLAYFUNC_H
#define DISPLAYFUNC_H

#include "../Base/Project.h"
#include "../Base/Group.h"
#include <queue>

<<<<<<< HEAD
void displayByProject(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayByGroup(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);

=======
void displayTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showGroupInfo(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects);
>>>>>>> 6eccf9999e459d22bbe9ce80c2e5b8aad0ff9acc

#endif
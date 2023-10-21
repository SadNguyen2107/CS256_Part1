#ifndef DISPLAYFUNC_H
#define DISPLAYFUNC_H

#include "../Base/Project.h"
#include "../Base/Group.h"
#include <queue>

void displayTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showGroupInfo(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *>* findGroupsCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects);

#endif
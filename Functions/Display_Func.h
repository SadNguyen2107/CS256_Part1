#include "./Base/Project.h"
#include "./Base/Group.h"
#include <queue>


void displayTable(std::vector<Group *>* groups, std::vector<Project *>* projects);
void showGroupInfo(std::vector<Group *>* groups, std::vector<Project *>* projects);
std::queue<Group> findGroupNotCompleteOnTime(std::vector<Group *>* groups, std::vector<Project *>* projects);
std::queue<Group> findGroupCompleteOnTime(std::vector<Group *>* groups, std::vector<Project *>* projects);
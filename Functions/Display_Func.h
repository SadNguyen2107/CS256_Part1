#include "../Base/Project.h"
#include "../Base/Group.h"
#include <queue>

void displayTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showGroupInfo(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group> findGroupNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group> findGroupCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);


// Example Code
void displayTableTest(std::vector<Group *> *groups, std::vector<Project *> *projects)
{
    for (size_t index = 0; index < projects->size(); index++)
    {
        std::cout << projects->at(index) << std::endl;
    }
}
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

    for (Project *project : *projects) {
        std::vector<Date*> submission_dates = project->getSubmissionDateCopy();
        Date* submission_date_group = submission_dates[group_index - 1];

        std::cout << "Project name: " << project->getDescription() << std::endl;
        std::cout << "Submission date: " << submission_date_group << std::endl;
        std::cout << "State: " << checkState(project->getDueDate(), submission_date_group) << std::endl;
        std::cout << std::endl;
    }
}

void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects){
    std::cout << "\n" << "|" << std::left << std::setw(3) << "ID"
              << "|" << std::left << std::setw(20) << "GROUP NAME"
              << "|" << std::left << std::setw(25) << "STUDENT NAME"
              << "|" << std::left << std::setw(15) << "STUDENT ID"; 
              for (int project_index = 0; project_index < 6; project_index++){
                    std::cout << "|" << std::left << std::setw(15) << "Project" << project_index + 1;
              }
              std::cout << std::endl;
              std::cout << "+==============================================================+\n";

    for (std::vector<Group*>::size_type rows = 0; rows < groups->size(); rows++)
    {
        for (std::vector<Student>::size_type columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
        {
            for (Project *project : *projects) {
                int project_index = 0;
                std::vector<Date*> submission_dates = project->getSubmissionDateCopy();
                Date* submission_date_group = submission_dates[project_index - 1];

                std::cout << "|" << std::left << std::setw(3) << rows + 1
                      << "|" << std::left << std::setw(20) << groups->at(rows)->getGroupName()
                      << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                      << "|" << std::left << std::setw(15) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id;
                      for (int project_index = 0; project_index < 6; project_index++){
                            std::cout << "|" << std::left << std::setw(15) << checkState(project->getDueDate(), submission_date_group);
                      }
                      std::cout << std::endl;
              std::cout << "+==============================================================+\n";
            }
        }
    }
        std::cout << std::endl;

    
}
#endif
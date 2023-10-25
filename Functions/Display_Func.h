#ifndef DISPLAYFUNC_H
#define DISPLAYFUNC_H

#include "../Base/Project.h"
#include "../Base/Group.h"
#include "../Validate/ValidateFunc.h"
#include "../Validate/ValidateRegex.h"
#include <queue>

void displayByProject(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayByGroup(std::vector<Group *> *groups, std::vector<Project *> *projects);
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects);
void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *> *findGroupsNotCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);
std::queue<Group *> *findGroupsCompleteOnTime(std::vector<Group *> *groups, std::vector<Project *> *projects);

void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects)
{
  // string specificDate_string = "";
  // cout << "Enter the specific date you want to display: ";
  // getline(cin, specificDate_string);
  // specificDate_string = getValueAfterValidate(specificDate_string, validateDate);

  // Date *specificDate = new Date(specificDate_string);

  // std::vector<Project *> projects_due_before_x;

  // // Iterate over all of the projects.
  // for (Project *project : *projects)
  // {
  //   // Check if the project's due date is sooner than x.
  //   Date dateptr = *(project->getDueDate());

  //   if (dateptr.sooner(*specificDate))
  //   {
  //     // Add the project to the vector.
  //     projects_due_before_x.push_back(project);
  //   }
  // }

  //! HEADLINE
  std::cout << "\n"
            << "|" << std::left << std::setw(3) << "ID"
            << "|" << std::left << std::setw(12) << "GroupName"
            << "|" << std::left << std::setw(25) << "StudentName"
            << "|" << std::left << std::setw(9) << "StudentID";

  for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
  {
    std::cout << "|" << std::left << std::setw(8) << "Project" << project_index + 1;
  }
  std::cout << std::endl;
  std::cout << "+======================================================================================+\n";

  //? INFOMATION
  for (std::vector<Group *>::size_type rows = 0; rows < groups->size(); rows++)
  {
    for (std::vector<Student>::size_type columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
    {

      std::cout << "|" << std::left << std::setw(3) << rows + 1
                << "|" << std::left << std::setw(12) << groups->at(rows)->getGroupName()
                << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                << "|" << std::left << std::setw(9) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id;

      // CURRENT PROJECT
      Project *project = projects->at(rows);
      std::vector<Date *> submission_dates = project->getSubmissionDateCopy();
      for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
      {
        std::cout << "|" << std::left << std::setw(9) << checkState(project->getDueDate(), submission_dates[project_index]);
      }
      std::cout << std::endl;
      std::cout << "+======================================================================================+\n";
    }
    std::cout << std::endl;
  }
}

#endif
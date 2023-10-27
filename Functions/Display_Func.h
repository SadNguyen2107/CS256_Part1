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

void displayByProject(std::vector<Group *> *groups, std::vector<Project *> *projects) {
    // Get the project number from the instructor
    std::cout << "Enter the project number you want to display: ";
    int projectNumber;
    std::cin >> projectNumber;

    // Check if the project number is valid
    if (projectNumber < 1 || projectNumber > projects->size()) {
        std::cout << "Invalid project number. Please enter a valid project number." << std::endl;
        return;
    }

    // Get the selected project
    Project *selectedProject = projects->at(projectNumber - 1);
    std::vector<Date *> submissionDates = selectedProject->getSubmissionDateCopy();

    // Display the table
    std::cout << "\nTable for Project " << projectNumber << " Submission Status:\n";
    std::cout << "\n|" << std::left << std::setw(3) << "ID"
              << "|" << std::left << std::setw(12) << "GroupName"
              << "|" << std::left << std::setw(25) << "StudentName"
              << "|" << std::left << std::setw(9) << "StudentID"
              << "|" << std::left << std::setw(15) << "Submission Status";

    std::cout << "\n+=============================================================+\n";


    for (std::vector<Group *>::size_type groupIndex = 0; groupIndex < groups->size(); groupIndex++) {
        for (std::vector<Student>::size_type studentIndex = 0; studentIndex < groups->at(groupIndex)->getGroupStudentCopy().size(); studentIndex++) {
            std::cout << "|" << std::left << std::setw(3) << groupIndex + 1
                      << "|" << std::left << std::setw(12) << groups->at(groupIndex)->getGroupName()
                      << "|" << std::left << std::setw(25) << groups->at(groupIndex)->getGroupStudentCopy().at(studentIndex).student_name
                      << "|" << std::left << std::setw(9) << groups->at(groupIndex)->getGroupStudentCopy().at(studentIndex).student_id;

            // Check the submission status for the selected project
            std::string submissionStatus = checkState(selectedProject->getDueDate(), submissionDates[groupIndex]);
            std::cout << "|" << std::left << std::setw(15) << submissionStatus;
            std::cout << "\n+=============================================================+\n";
        }
    }
}



void displayAllTable(std::vector<Group *> *groups, std::vector<Project *> *projects)
{
  std::cout << "\n"
            << "|" << std::left << std::setw(3) << "No."
            << "|" << std::left << std::setw(12) << "Group Name"
            << "|" << std::left << std::setw(25) << "Student Name"
            << "|" << std::left << std::setw(10) << "Student ID";

  for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
  {
    std::cout << "|" << std::left << std::setw(8) << "Project" << project_index + 1;
  }
  std::cout << std::endl;
  std::cout << "+======================================================================================+\n";

  size_t projects_length = projects->size();
  size_t groups_length = groups->size();

  //? CHECK WHICH LENGTH IS LARGER
  if (groups_length >= projects_length) // THEN CHOOSE THE GROUP_INDEX AS THE PIVOT
  {
    size_t project_index = 0;

    //? INFOMATION
    for (std::vector<Group *>::size_type rows = 0; rows < groups->size(); rows++)
    {
      for (std::vector<Student>::size_type columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
      {

        std::cout << "|" << std::left << std::setw(3) << rows + 1
                  << "|" << std::left << std::setw(12) << groups->at(rows)->getGroupName()
                  << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                  << "|" << std::left << std::setw(10) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id;

        for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
        {
          Project *project = projects->at(project_index);
          std::vector<Date *> submission_dates = project->getSubmissionDateCopy();
          std::cout << "|" << std::left << std::setw(9) << checkState(project->getDueDate(), submission_dates[rows]);
        }
        std::cout << std::endl;
        std::cout << "+======================================================================================+\n";
      }
      std::cout << std::endl;
      if (project_index + 1 < projects_length)
      {
        project_index++;
      }
    }
    //------------------------------------------------------------------------------------------------------------
  }
  else // THEN CHOOSE THE PROJECT_INDEX AS THE PIVOT
  {
    size_t group_index = 0;

    //? INFOMATION
    for (std::vector<Project *>::size_type rows = 0; rows < projects->size(); rows++)
    {
      for (std::vector<Student>::size_type columns = 0; columns < groups->at(group_index)->getGroupStudentCopy().size(); columns++)
      {

        std::cout << "|" << std::left << std::setw(3) << group_index + 1
                  << "|" << std::left << std::setw(12) << groups->at(group_index)->getGroupName()
                  << "|" << std::left << std::setw(25) << groups->at(group_index)->getGroupStudentCopy().at(columns).student_name
                  << "|" << std::left << std::setw(10) << groups->at(group_index)->getGroupStudentCopy().at(columns).student_id;

        for (std::vector<Project *>::size_type project_index = 0; project_index < projects->size(); project_index++)
        {
          Project *project = projects->at(project_index);
          std::vector<Date *> submission_dates = project->getSubmissionDateCopy();
          std::cout << "|" << std::left << std::setw(9) << checkState(project->getDueDate(), submission_dates[group_index]);
        }
        std::cout << std::endl;
        std::cout << "+======================================================================================+\n";
      }
      std::cout << std::endl;
      group_index++;
      if (group_index >= groups_length)
      {
        break;
      }
    }
    //------------------------------------------------------------------------------------------------------------
  }
}
void showSubmissionToASpecificDate(std::vector<Group *> *groups, std::vector<Project *> *projects)
{
  string specificDate_string = "";
  cout << "Enter the specific date you want to display: ";
  getline(cin, specificDate_string);
  specificDate_string = getValueAfterValidate(specificDate_string, validateDate);

  Date *specificDate = new Date(specificDate_string);

  // Iterate over all of the projects.
  std::vector<Project *> projects_before_specific_date;
  for (Project *project : *projects)
  {
    // Get the project's due date.
    Date *dueDate = project->getDueDate();

    // If the submission date is earlier than the specific date, push the specific date into the project.
    if (dueDate->soonerOrEqual(specificDate))
    {
      projects_before_specific_date.push_back(project);
    }
  }

  //! HEADLINE
  std::cout << "\n"
            << "|" << std::left << std::setw(3) << "No."
            << "|" << std::left << std::setw(12) << "Group Name"
            << "|" << std::left << std::setw(25) << "Student Name"
            << "|" << std::left << std::setw(10) << "Student ID";

  for (std::vector<Project *>::size_type project_index = 0; project_index < projects_before_specific_date.size(); project_index++)
  {
    std::cout << "|" << std::left << std::setw(8) << "Project" << project_index + 1;
  }
  std::cout << std::endl;
  std::cout << "+======================================================================================+\n";

  size_t projects_length = projects->size();
  size_t groups_length = groups->size();

  //? CHECK WHICH LENGTH IS LARGER
  if (groups_length >= projects_length) // THEN CHOOSE THE GROUP_INDEX AS THE PIVOT
  {
    size_t project_index = 0;

    //? INFOMATION
    for (std::vector<Group *>::size_type rows = 0; rows < groups->size(); rows++)
    {
      for (std::vector<Student>::size_type columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
      {

        std::cout << "|" << std::left << std::setw(3) << rows + 1
                  << "|" << std::left << std::setw(12) << groups->at(rows)->getGroupName()
                  << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                  << "|" << std::left << std::setw(10) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id;

        for (std::vector<Project *>::size_type project_index = 0; project_index < projects_before_specific_date.size(); project_index++)
        {
          Project *project = projects->at(project_index);
          std::vector<Date *> submission_dates = project->getSubmissionDateCopy();
          std::cout << "|" << std::left << std::setw(9) << checkState(project->getDueDate(), submission_dates[rows]);
        }
        std::cout << std::endl;
        std::cout << "+======================================================================================+\n";
      }
      std::cout << std::endl;
      if (project_index + 1 < projects_length)
      {
        project_index++;
      }
    }
    //------------------------------------------------------------------------------------------------------------
  }
  else // THEN CHOOSE THE PROJECT_INDEX AS THE PIVOT
  {
    size_t group_index = 0;

    //? INFOMATION
    for (std::vector<Project *>::size_type rows = 0; rows < projects->size(); rows++)
    {
      for (std::vector<Student>::size_type columns = 0; columns < groups->at(group_index)->getGroupStudentCopy().size(); columns++)
      {

        std::cout << "|" << std::left << std::setw(3) << group_index + 1
                  << "|" << std::left << std::setw(12) << groups->at(group_index)->getGroupName()
                  << "|" << std::left << std::setw(25) << groups->at(group_index)->getGroupStudentCopy().at(columns).student_name
                  << "|" << std::left << std::setw(10) << groups->at(group_index)->getGroupStudentCopy().at(columns).student_id;

        for (std::vector<Project *>::size_type project_index = 0; project_index < projects_before_specific_date.size(); project_index++)
        {
          Project *project = projects->at(project_index);
          std::vector<Date *> submission_dates = project->getSubmissionDateCopy();
          std::cout << "|" << std::left << std::setw(9) << checkState(project->getDueDate(), submission_dates[group_index]);
        }
        std::cout << std::endl;
        std::cout << "+======================================================================================+\n";
      }
      std::cout << std::endl;
      group_index++;
      if (group_index >= groups_length)
      {
        break;
      }
    }
    //------------------------------------------------------------------------------------------------------------
  }
}

#endif
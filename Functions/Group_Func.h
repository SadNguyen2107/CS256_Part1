#ifndef GROUPFUNC_H
#define GROUPFUNC_H

#include "../Base/Group.h"
#include "../Base/Date.h"
#include "../Base/Project.h"
#include "../Validate/ValidateRegex.h"
#include "../Validate/ValidateFunc.h"
#include <fstream>

Group *inputGroupInfo(int group_index);
void displayGroupsInfo(std::vector<Group *> *groups);
void saveGroupsInfo(std::vector<Group *> *groups, std::string filePath);

Group *inputGroupInfo(int group_index)
{
    cout << "Group " << group_index + 1 << " Information:" << endl;
    std::cout << "================================================\n";
    // ENTER GROUPS NAME
    std::string groupName;
    std::cout << "Enter the name of group " << group_index + 1 << ": ";
    std::getline(std::cin, groupName);

    Group *newGroup = new Group(groupName);

    // ENTER NUMBER STUDENTS
    std::vector<Student>::size_type numStudents = 0;
    std::string numStudents_string = "";
    std::cout << "Enter the number of students in this group: ";
    std::cin >> numStudents_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numStudents_string = getValueAfterValidate(numStudents_string, validateID);
    numStudents = std::stoi(numStudents_string);

    std::cout << "________________________________________________\n";

    for (std::vector<Student>::size_type j = 0; j < numStudents; j++)
    {
        // ENTER STUDENTS NAME
        std::string student_name;
        std::cout << "Enter the name of student " << j + 1 << ": ";
        std::getline(std::cin, student_name);
        student_name = getValueAfterValidate(student_name, validateName);

        // ENTER STUDENTS ID
        std::vector<Student>::size_type student_id = 0;
        string string_ID = "";
        std::cout << "Enter the student ID: ";
        std::cin >> string_ID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string_ID = getValueAfterValidate(string_ID, validateID);
        student_id = std::stoi(string_ID);

        newGroup->addStudent(newStudent(student_name, student_id));
    }
    std::cout << "================================================\n";
    cout << "Group " << group_index + 1 << " added successfully." << endl;

    return newGroup;
}
void displayGroupsInfo(std::vector<Group *> *groups)
{
    if (groups->empty())
    {
        std::cout << "There are no groups to display." << std::endl;
        return;
    }
    else
    {
        std::cout << "\n"
                  << "|" << std::left << std::setw(3) << "ID"
                  << "|" << std::left << std::setw(20) << "GROUP NAME"
                  << "|" << std::left << std::setw(25) << "STUDENT NAME"
                  << "|" << std::left << std::setw(15) << "STUDENT ID" << std::endl
                  << "+==============================================================+\n";

        for (std::vector<Group *>::size_type rows = 0; rows < groups->size(); rows++)
        {
            for (std::vector<Student>::size_type columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
            {
                std::cout << "|" << std::left << std::setw(3) << rows + 1
                          << "|" << std::left << std::setw(20) << groups->at(rows)->getGroupName()
                          << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                          << "|" << std::left << std::setw(15) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id << std::endl
                          << "+==============================================================+\n";
            }

            std::cout << std::endl;
        }
    }
}
void saveGroupsInfo(std::vector<Group *> *groups, std::string filePath)
{
    std::ofstream file;
    file.open(filePath, std::ios::out | std::ios::trunc);

    if (file.is_open())
    {
        file << "GroupNumber GroupName   GroupMembers\n";
        for (std::vector<Group *>::size_type group_index = 0; group_index < groups->size(); group_index++)
        {
            file << group_index + 1 << "\t";
            // WRITE GROUPS NAME
            file << groups->at(group_index)->getGroupName() << "\t";

            // WRITE STUDENT INFORMATION
            for (std::vector<Student>::size_type student_num = 0; student_num < groups->at(group_index)->getGroupStudentCopy().size(); student_num++)
            {
                // WRITE STUDENT NAMES
                file << groups->at(group_index)->getGroupStudentCopy().at(student_num).student_name << "/" << groups->at(group_index)->getGroupStudentCopy().at(student_num).student_id << "\t";
            }

            file << "\n";
        }

        file.close();
    }
    else
    {
        std::cout << "Error opening file: " << filePath << std::endl;
    }
}

#endif
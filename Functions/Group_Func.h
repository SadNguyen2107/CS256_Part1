#ifndef GROUPFUNC_H
#define GROUPFUNC_H

#include "../Base/Group.h"
#include "../Base/Date.h"
#include "../Base/Project.h"
#include "../Validate/ValidateRegex.h"
#include "../Validate/ValidateFunc.h"
#include <fstream>

void inputGroupInfo(std::vector<Group*>* groups);
void displayGroupInfo(std::vector<Group*>* groups);
void saveGroupInfo(std::vector<Group*> *groups, std::string filePath);

void inputGroupInfo(std::vector<Group*>* groups){
    int numGroups = 0;
    std::string numGroups_string = "";

    // ENTER NUMBER GROUPS
    std::cout << "Enter the number of groups: ";
    std::cin >> numGroups_string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    numGroups_string = getValueAfterValidate(numGroups_string, validateID);
    numGroups = std::stoi(numGroups_string);

    std::cout << "================================================\n";

    for (int i = 0; i < numGroups; i++) {
        // ENTER GROUPS NAME
        std::string groupName;
        std::cout << "Enter the name of group " << i + 1 << ": ";
        std::getline(std::cin, groupName);
        groupName = getValueAfterValidate(groupName, validateName);

        Group* newGroup = new Group(groupName);

        // ENTER NUMBER STUDENTS
        int numStudents = 0;
        std::string numStudents_string = "";
        std::cout << "Enter the number of students in this group: ";
        std::cin >> numStudents_string;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numStudents_string = getValueAfterValidate(numStudents_string, validateID);
        numStudents = std::stoi(numStudents_string);

        std::cout << "________________________________________________\n";

        for (int j = 0; j < numStudents; j++) {
            // ENTER STUDENTS NAME
            std::string student_name;
            std::cout << "Enter the name of student " << j + 1 << ": ";
            std::getline(std::cin, student_name);
            student_name = getValueAfterValidate(student_name, validateName);

            // ENTER STUDENTS ID
            unsigned short student_id = 0;
            string string_ID = "";
            std::cout << "Enter the student ID: ";
            std::cin >> string_ID;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            string_ID = getValueAfterValidate(string_ID, validateID);
            student_id = std::stoi(string_ID);

            newGroup->addStudent(newStudent(student_name, student_id));
        }
        std::cout << "================================================\n";

        groups->push_back(newGroup);
    }
}

void displayGroupInfo(std::vector<Group*>* groups){
    std::cout << "\n" << "|" << std::left << std::setw(20) << "GROUP NAME"
              << "|" << std::left << std::setw(25) << "STUDENT NAME"
              << "|" << std::left << std::setw(15) << "STUDENT ID" << std::endl
              << "+==============================================================+\n";

    for (int rows = 0; rows < groups->size(); rows++)
    {
        for (int columns = 0; columns < groups->at(rows)->getGroupStudentCopy().size(); columns++)
        {
            std::cout << "|" << std::left << std::setw(20) << groups->at(rows)->getGroupName()
                      << "|" << std::left << std::setw(25) << groups->at(rows)->getGroupStudentCopy().at(columns).student_name
                      << "|" << std::left << std::setw(15) << groups->at(rows)->getGroupStudentCopy().at(columns).student_id << std::endl
                      << "+==============================================================+\n";
        }

        std::cout << std::endl;
    }
}

void saveGroupInfo(std::vector<Group*> *groups, std::string filePath)
{
    std::ofstream file;
    file.open(filePath, std::ios::out | std::ios::trunc);

    if (file.is_open())
    {
        file << "GroupNumber GroupName   GroupMembers\n";
        for (int i = 0; i < groups->size(); i++)
        {
            // WRITE GROUPS NAME
            file << groups->at(i)->getGroupName() << "\t";

            // WRITE STUDENT INFORMATION
            for (int j = 0; j < groups->at(i)->getGroupStudentCopy().size(); j++)
            {
                // WRITE STUDENT NAMES
                file << groups->at(i)->getGroupStudentCopy().at(j).student_name << "/" << groups->at(i)->getGroupStudentCopy().at(j).student_id << "\t";
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
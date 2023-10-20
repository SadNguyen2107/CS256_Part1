#ifndef EXTRACTDATAFUNC_H
#define EXTRACTDATAFUNC_H

#include <bits/stdc++.h>
#include "../Base/Group.h"
#include "../Base/Date.h"
#include "../Base/Project.h"
//? ALL THE EXTRACT FUNCTIONS
void extractGroupInfoFile(std::vector<Group *> *groups_to_store, std::string filePath);
void extractProjectInfoFile(std::vector<Project *> *projects_to_store, std::string filePath);
void extractSubmissionInfoFile(std::vector<Project *> *projects_to_store, std::string filePath);

//! EXTRACT DATA FROM GroupInfo.txt FILES
// groups_to_store parameter is a place to store the RESULT after extract finish
void extractGroupInfoFile(std::vector<Group *> *groups_to_store, std::string filePath)
{
    fstream fs;
    fs.open(filePath);
    string str;
    getline(fs, str);
    srand((unsigned)time(0));
    while (getline(fs, str))
    {

        istringstream ss(str);

        int id;
        string name;
        ss >> id;
        if (id > groups_to_store->size())
        {
            groups_to_store->resize(id);
        }
        ss >> name;
        (*groups_to_store)[id - 1] = new Group(name);
        string student_name;
        int x = 0;

        while (ss >> student_name)
        {
            unsigned short random = rand();
            (*groups_to_store)[id - 1]->addStudent(newStudent(student_name, random));
        }
    }
}
/*
Extract info file :))))

*/
void extractProjectInfoFile(std::vector<Project *> *projects_to_store, std::string filePath)
{
    fstream fs;
    fs.open(filePath);
    // Providing a seed value

    // Get a random number

    // Print the random number

    // fs.ignore();
    string str;
    getline(fs, str);
    // std::vector<Project *> projects(0);
    while (getline(fs, str))
    {
        stringstream ss(str);
        // cout << str << endl;
        string desc;
        int id;
        string date;
        // char delim;
        ss >> id >> date;
        getline(ss, desc, '\n');
        ss >> id >> date;

        projects_to_store->push_back(new Project(desc, new Date(date)));
    }
}

#endif
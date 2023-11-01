#ifndef EXTRACTDATAFUNC_H
#define EXTRACTDATAFUNC_H

#include "../Base/Group.h"
#include "../Base/Date.h"
#include "../Base/Project.h"
#include <fstream>

//! EXTRACT DATA FROM GroupInfo.txt FILES
// groups_to_store parameter is a place to store the RESULT after extract finish
// Return the number of groups in the file
void extractGroupInfoFile(std::vector<Group *> *groups_to_store,std::string filePath);

// Extract info file 
void extractProjectInfoFile(std::vector<Project *> *projects_to_store, int number_of_groups, std::string filePath);

//! EXTRACT DATA FROM GroupInfo.txt FILES
void extractGroupInfoFile(std::vector<Group *> *groups_to_store,std::string filePath)
{
    fstream fs;
    fs.open(filePath);
    string str;
    getline(fs, str);
    // srand((unsigned)time(0));
    while (getline(fs, str))
    {

        istringstream ss(str);

        std::vector<Group*>::size_type id;
        string name;
        ss >> id;
        if (id > groups_to_store->size())
        {
            groups_to_store->resize(id);
        }
        ss >> name;
        if ((*groups_to_store)[id - 1] ==nullptr){
               (*groups_to_store)[id - 1] = new Group(name);
        }

        string student_name;

        while (ss >> student_name)
        {
            // unsigned short random = rand();
            smatch result;
            // string s = "Nguyen Hoang Tuan Anh/20218105";
            regex pattern1 = regex("(\\D+)\\/(\\d+)");
            unsigned int student_id;
            string name;
            if (regex_search(student_name, result, pattern1))
            {
                student_id = atoi(string(result[2]).c_str());
                name = result[1];
            }

            groups_to_store->at(id - 1)->addStudent(newStudent(name, student_id));
        }
    }
}
/*
Extract info file :))))

*/
void extractProjectInfoFile(std::vector<Project *> *projects_to_store, int number_of_groups, std::string filePath)
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
        std::vector<Project*>::size_type id;
        string date;
        // char delim;
        ss >> id >> date;
        getline(ss, desc, '\n');
        ss >> id >> date;

        Project* project = new Project(desc, new Date(date));
        resizeSubmissionDates(project, number_of_groups);
        if (id>projects_to_store->size()){
            projects_to_store->resize(id);
        }
        // projects_to_store->push_back(project);
        (*projects_to_store)[id-1] = project;
    }
}

#endif
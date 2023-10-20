#ifndef EXTRACTDATAFUNC_H
#define EXTRACTDATAFUNC_H

#include <bits/stdc++.h>
#include "../Base/Group.h"
#include "../Base/Date.h"

//! EXTRACT DATA FROM GroupInfo.txt FILES
// groups_to_store parameter is a place to store the RESULT after extract finish
void extractGroupInfoFile(std::vector<Group* >* groups_to_store, std::string filename)
{ 
    fstream fs;
    fs.open(filename);
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
#endif
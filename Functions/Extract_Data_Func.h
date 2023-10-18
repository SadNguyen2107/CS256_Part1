#ifndef EXTRACTDATAFUNC_H
#define EXTRACTDATAFUNC_H

#include <bits/stdc++.h>
#include "../Base/Group.h"
#include "../Base/Date.h"

//! EXTRACT DATA FROM GroupInfo.txt FILES
void extractGroupInfoFile(std::vector<Group* >* groups, std::string filename)
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
        if (id > groups->size())
        {
            groups->resize(id);
        }
        ss >> name;
        (*groups)[id - 1] = new Group(name);
        string student_name;
        int x = 0;

        while (ss >> student_name)
        {
            unsigned short random = rand();
            (*groups)[id - 1]->addStudent(newStudent(student_name, random));
        }
    }
}
#endif
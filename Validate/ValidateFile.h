#ifndef VALIDATEFILE_H
#define VALIDATEFILE_H

#define GROUP_INFO_FILE 1
#define PROJECT_INFO_FILE 2
#include <iostream>
#include <string>
#include <fstream>

// In flag Parameter:
// USE GROUP_INFO_FILE as flag
// OR PROJECT_INFO_FILE as flag
bool isRightFile(std::string filePath, int flag)
{
    std::ifstream file(filePath);

    if (file.is_open())
    {
        std::string firstLine;
        if (std::getline(file, firstLine))
        {
            if (flag == GROUP_INFO_FILE)
            {
                return firstLine == "GroupNumber GroupName   GroupMembers";
            }
            else if (flag == PROJECT_INFO_FILE)
            {
                return firstLine == "ProjectNumber   Due_date    Description";
            }
            else
            {
                return false;
            }
        }
        else
        {
            std::cerr << "Error: Failed to read the first line!!!" << std::endl;
            return false;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to open the file!!!" << std::endl;
    }
    return false;
}

#endif

// x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -Wall -o main main.cpp -lsqlite3 -lole32 -lshell32 -lcomdlg32 -luuid
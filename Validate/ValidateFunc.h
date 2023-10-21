#ifndef VALIDATEFUNC_H
#define VALIDATEFUNC_H

#include "../Base/Date.h"
#include <ctime>
#include <string>
#include <iostream>
#include <functional>
#include <limits>
#include <fstream>

//! FOR VALIDATE DAY DATE UPPER BOUND PURPOSE
bool isSmallerOrEqualThanToday(Date *date_to_evaluate)
{
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a tm struct
    std::tm *now = std::localtime(&currentTime);

    // Get today year, month, day
    int today_day = now->tm_mday;
    int today_month = (now->tm_mon + 1); // Month is 0-based
    int today_year = (now->tm_year + 1900);

    if (date_to_evaluate->getYear() < today_year) //? If large than today -> IMPOSSIBLE
    {
        return true;
    }
    else if (date_to_evaluate->getYear() == today_year && date_to_evaluate->getMonth() < today_month)
    {
        return true;
    }
    else if (date_to_evaluate->getYear() == today_year && date_to_evaluate->getMonth() == today_month && date_to_evaluate->getDay() <= today_day)
    {
        return true;
    }
    std::cout << "Impossible!!" << std::endl;
    std::cout << "Today is just only: ";
    // Print the current date in the desired format
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mday << '/'
              << std::setw(2) << (now->tm_mon + 1) << '/' // Month is 0-based
              << (now->tm_year + 1900) << std::endl;

    return false;
}

//! FOR VALIDATE DAY STRING UPPER BOUND PURPOSE
bool isSmallerOrEqualThanToday(std::string string_date_to_evaluate)
{
    //! DATE TO EVALUATE
    Date date_to_evaluate(string_date_to_evaluate);

    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a tm struct
    std::tm *now = std::localtime(&currentTime);

    // Get today year, month, day
    int today_day = now->tm_mday;
    int today_month = (now->tm_mon + 1); // Month is 0-based
    int today_year = (now->tm_year + 1900);

    if (date_to_evaluate.getYear() < today_year) //? If large than today -> IMPOSSIBLE
    {
        return true;
    }
    else if (date_to_evaluate.getYear() == today_year && date_to_evaluate.getMonth() < today_month)
    {
        return true;
    }
    else if (date_to_evaluate.getYear() == today_year && date_to_evaluate.getMonth() == today_month && date_to_evaluate.getDay() <= today_day)
    {
        return true;
    }
    std::cout << "Impossible!!" << std::endl;
    std::cout << "Today is just only: ";
    // Print the current date in the desired format
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mday << '/'
              << std::setw(2) << (now->tm_mon + 1) << '/' // Month is 0-based
              << (now->tm_year + 1900) << std::endl;

    return false;
}

// In option Parameter:
// 1 is For GroupInfo File Template
// 2 is For ProjectInfo File Template
bool isRightFile(std::string filePath, int option = 1)
{
    std::ifstream file(filePath);

    if (file.is_open())
    {
        std::string firstLine;
        if (std::getline(file, firstLine))
        {
            if (option == 1)
            {
                return firstLine == "GroupNumber GroupName   GroupMembers";
            }
            else
            {
                return firstLine == "ProjectNumber   Due_date    Description";
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

// DO THE VALUE VALIDATION FUNCTION
std::string getValueAfterValidate(std::string value, std::function<bool(std::string)> validateFunc)
{
    while (true)
    {
        if (validateFunc(value))
        {
            return value;
        }
        std::cout << "Wrong Format!!!" << std::endl;
        std::cout << "Enter Again: ";
        std::getline(std::cin, value);
    }
}

#endif
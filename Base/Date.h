#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
bool validateThroughLib(string date);
bool validateWithStream(string date);
bool validate(unsigned short a, unsigned short b, unsigned short c);
class Date
{
private:
    unsigned short day = 0;
    unsigned short month = 0;
    unsigned short year = 9999;

public:
    // CONSTRUCTTORS
    Date(const unsigned short day = 0, const unsigned short month = 0, const unsigned short year = 9999)
    {
        if (validate(day, month, year))
        {
            this->day = day;
            this->month = month;
            this->year = year;
            return;
        }
        else
        {
            this->day = 0;
            this->month = 0;
            this->year = 9999;
            return;
        }
    }

    Date(const std::string date)
    {
        unsigned day = 0, month = 0, year = 9999;
        if (validateThroughLib(date) && validateWithStream(date))
        {
            std::stringstream ss(date);
            char delimiter;
            ss >> day >> delimiter >> month >> delimiter >> year;
            this->day = day;
            this->month = month;
            this->year = year;
            return;
        }
        this->day = day;
        this->month = month;
        this->year = year;
    }
    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    // PROPERTIES
    unsigned short getDay() const
    {
        return this->day;
    }

    unsigned short getMonth() const
    {
        return this->month;
    }

    unsigned short getYear() const
    {
        return this->year;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date *date)
    {
        if (date != nullptr)
        {
            os << date->day << "/" << date->month << "/" << date->year;
        }
        else
            os << "Unknown";

        return os;
    }
    // COPY CONSTRUCTOR
    Date(const Date &date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }

    // OPERATOR
    // Date &operator=(const Date &otherDate)
    // {
    //     if (this != &otherDate)
    //     {
    //         this->day = otherDate.day;
    //         this->month = otherDate.month;
    //         this->year = otherDate.month;
    //     }
    //     return *this;
    // }
    bool operator==(const Date &otherDate)
    {
        return this->day == otherDate.day && this->month == otherDate.month && this->year == otherDate.year;
    }
    bool operator!=(const Date &otherDate)
    {
        return this->day != otherDate.day || this->month == otherDate.month || this->year == otherDate.year;
    }
    // Later
    bool later(const Date &otherDate)

    {
        if (this->year > otherDate.year)
        {
            return true;
        }
        else if (this->year == otherDate.year)
        {
            if (this->month > otherDate.month)
            {
                return true;
            }
            else if (this->month == otherDate.month)
            {
                if (this->day > otherDate.day)
                {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    // Sooner
    bool sooner(const Date &otherDate)
    {
        if (this->year < otherDate.year)
        {
            return true;
        }
        else if (this->year == otherDate.year)
        {
            if (this->month < otherDate.month)
            {
                return true;
            }
            else if (this->month == otherDate.month)
            {
                if (this->day < otherDate.day)
                {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

bool validateThroughLib(const string date)
{
    stringstream ss(date);
    tm time{};
    ss >> get_time(&time, "%d/%m/%y");
    if (ss.fail())
    {
        cout << "Failed to parse date and time\n";
        return false;
    }
    return true;
}
bool validateWithStream(const string date)
{
    stringstream ss(date);
    unsigned short day, month, year;
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year;
    if ((month == 2) && (day >= 30))
    {
        return false;
    }
    return true;
}
bool validate(const unsigned short a, const unsigned short b, const unsigned short c)
{
    if (a < 0 || b < 0 || c < 0 || a >= 32 || b >= 13)
    {
        return false;
    }
    if (b == 2 && a >= 30)
    {
        return false;
    }
    return true;
}

// check as null day :))
bool validate_null(const unsigned short a, const unsigned short b)
{
    if (a == 0 || b == 0 || b > 13)
    {
        return true;
    }
    return false;
}

#endif
#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <string>
#include <regex>
#include <tuple>

//* VALIDATE HUMAN ATTRIBUTE FUNCTIONS
bool validateID(std::string ID);
bool validateName(std::string name);
bool validateDate(std::string date);

//? VALIDATE OTHER UTILITIES
bool validateFileTxt(std::string filename);

//-------------------------------------------------------------------

//* VALIDATE HUMAN ATTRIBUTE FUNCTIONS
bool validateID(std::string ID)
{
    return std::regex_match(ID, std::regex("([0-9])+"));
}

//* FOR VALIDATE studentName. groupName
bool validateName(std::string name)
{
    return (std::regex_match(name, std::regex("(([A-Z]{1}[a-z]+)_?){1,}")));
}

// it works properly only for [1901 - 2099]
bool validateDate(std::string date)
{
    std::regex date_pattern("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)");
    return std::regex_match(date, date_pattern);
}

//? VALIDATE OTHER UTILITIES
bool validateFileTxt(std::string filename)
{
    std::regex filename_pattern("^[^\\s](.*).txt$");
    return std::regex_match(filename, filename_pattern);
}

#endif
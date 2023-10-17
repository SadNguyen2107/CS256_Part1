#ifndef GROUP_H
#define GROUP_H
#include <bits/stdc++.h>

struct Student
{
    std::string student_name;
    unsigned short student_id;
};

class Group
{
private:
    std::string group_name;
    std::vector<Student *> group_students;

public:
    Group(std::string group_name);
    ~Group();

    //* GETTER
    std::string getGroupName() { return this->group_name; }
    const std::vector<Student> getGroupStudentCopy()
    {
        std::vector<Student> list(this->group_students.size());

        for (int index = 0; index < this->group_students.size(); index++)
        {
            list[index] = *group_students[index];
        }
        return list;
    }

    //* SETTER
    void addStudent(Student *s) { this->group_students.push_back(s); }
    void changeGroupName(std::string group_name) { this->group_name = group_name; }
    void deleteStudent(unsigned short id)
    {
        delete this->group_students[id - 1];
        this->group_students.erase(this->group_students.begin() + id - 1);
    }
    void changeStudentInfo(unsigned short id, std::string new_name, unsigned short new_id)
    {
        Student *s = this->group_students[id - 1];

        s->student_name = new_name;
        s->student_id = new_id;
    }

    //* DEBUG PURPOSE
    friend std::ostream &operator<<(std::ostream &os, const Group &group)
    {
        os << "NAME: " << group.group_name << std::endl;
        os << "GROUP MEMBERS: " << std::endl;
        for (size_t index = 0; index < group.group_students.size(); index++)
        {
            os << index + 1 << ". " << group.group_students.at(index)->student_name 
               << " | ID: " << group.group_students.at(index)->student_id << std::endl;
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Group *group)
    {
        os << "NAME: " << group->group_name << std::endl;
        os << "GROUP MEMBERS: " << std::endl;
        for (size_t index = 0; index < group->group_students.size(); index++)
        {
            os << index + 1 << ". " << group->group_students.at(index)->student_name 
               << " | ID: " << group->group_students.at(index)->student_id << std::endl;
        }
        return os;
    }
};

Group::Group(std::string group_name)
{
    this->group_name = group_name;
};

Group::~Group()
{
    for (int index = 0; index < group_students.size(); index++)
    {
        delete group_students[index];
    }
};

#endif
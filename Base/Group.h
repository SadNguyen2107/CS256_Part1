#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <vector>
#include <string>

struct Student
{
    std::string student_name;
    unsigned int student_id;
};
Student* newStudent(std::string name, unsigned int id){
    Student* s = new Student();
    s->student_name = name;
    s->student_id = id;
    return s;
}
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

        for (std::vector<Student*>::size_type index = 0; index < this->group_students.size(); index++)
        {
            list[index] = *group_students[index];
        }
        return list;
    }

    //* SETTER
    void addStudent(Student *s) { this->group_students.push_back(s); }
    void changeGroupName(std::string group_name) { this->group_name = group_name; }
    void deleteStudent(unsigned int id)
    {
        delete this->group_students[id - 1];
        this->group_students.erase(this->group_students.begin() + id - 1);
    }
    void changeStudentInfo(unsigned int id, std::string new_name, unsigned int new_id)
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
    for (std::vector<Student*>::size_type index = 0; index < group_students.size(); index++)
    {
        delete group_students[index];
    }
};

#endif
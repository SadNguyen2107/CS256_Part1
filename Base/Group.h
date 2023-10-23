#ifndef GROUP_H
#define GROUP_H

#include "../DataStructures/LinkedList.h"
#include <vector>
#include <string>

struct Student
{
    std::string student_name;
    unsigned int student_id;

    //* FOR DEBUG PURPOSE
    friend std::ostream &operator<<(std::ostream &os, const Student &student)
    {
        os << "Name: " << student.student_name << " | ID: " << student.student_id;

        return os;
    }

    //* FOR DEBUG PURPOSE
    friend std::ostream &
    operator<<(std::ostream &os, const Student *student)
    {
        os << "Name: " << student->student_name
           << " | ID: " << student->student_id;

        return os;
    }
};
Student *newStudent(std::string name, unsigned int id)
{
    Student *s = new Student();
    s->student_name = name;
    s->student_id = id;
    return s;
}
class Group
{
private:
    std::string group_name;
    LinkedList<Student *> group_students;

public:
    Group(std::string group_name);
    ~Group();

    //* GETTER
    std::string getGroupName() { return this->group_name; }
    std::vector<Student> getGroupStudentCopy()
    {
        std::vector<Student> listStudent = std::vector<Student>();
        Node<Student *> *head = this->group_students.getHead();

        while (head != nullptr)
        {
            unsigned int id = head->data->student_id;
            std::string name = head->data->student_name;

            Student student = Student();
            student.student_id = id;
            student.student_name = name;

            listStudent.push_back(student);

            head = head->next;
        }

        return listStudent;
    }

    //* SETTER
    void addStudent(Student *s) { this->group_students.add(s); }
    void changeGroupName(std::string group_name) { this->group_name = group_name; }
    void deleteStudent(unsigned int id)
    {
        Student *tempStudent = new Student();
        tempStudent->student_id = id;

        this->group_students.remove([](Student *student_a, Student *student_b) -> bool { 
            return student_a->student_id == student_b->student_id; 
            }, tempStudent);
    }

    void changeStudentInfo(unsigned int id, std::string new_name, unsigned int new_id)
    {
        Node<Student *> *head = this->group_students.getHead();

        while (head != nullptr)
        {
            if (head->data->student_id == id)
            {
                head->data->student_id = new_id;
                head->data->student_name = new_name;
                return;
            }
            head = head->next;
        }
    }

    //* DEBUG PURPOSE
    friend std::ostream &operator<<(std::ostream &os, const Group &group)
    {
        os << "NAME: " << group.group_name << std::endl;
        os << "GROUP MEMBERS: " << std::endl;
        os << group.group_students << std::endl;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Group *group)
    {
        os << "NAME: " << group->group_name << std::endl;
        os << "GROUP MEMBERS: " << std::endl;
        os << group->group_students << std::endl;
        return os;
    }
};

Group::Group(std::string group_name)
{
    this->group_name = group_name;
};

Group::~Group()
{
    Node<Student*> * head = this->group_students.getHead();
    while (head != nullptr)
    {
        Node<Student*> * temp = head;
        head = head->next;
        delete temp;
    }
};

#endif
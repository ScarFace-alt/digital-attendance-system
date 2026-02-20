#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string id;
    std::string name;

    Student(std::string i, std::string n);
};

void registerStudent();
void searchStudent();
void loadStudents();

#endif

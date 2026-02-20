#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    std::string code;
    std::string title;

    Course(std::string c, std::string t);
};

void registerCourse();
void searchCourse();
void loadCourses();

#endif

#include "Course.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Course> courses;

Course::Course(string c, string t) {
    code = c;
    title = t;
}

void loadCourses() {
    ifstream file("data/courses.txt");
    string code, title;

    while (getline(file, code, ',') && getline(file, title)) {
        courses.push_back(Course(code, title));
    }

    file.close();
}

void registerCourse() {
    string code, title;

    cout << "Enter Course Code: ";
    cin >> code;
    cin.ignore();

    cout << "Enter Course Title: ";
    getline(cin, title);

    courses.push_back(Course(code, title));

    ofstream file("data/courses.txt", ios::app);
    file << code << "," << title << endl;
    file.close();

    cout << "Course registered successfully.\n";
}

void searchCourse() {
    string searchCode;
    cout << "Enter Course Code to search: ";
    cin >> searchCode;

    for (auto c : courses) {
        if (c.code == searchCode) {
            cout << "Code: " << c.code << "\n";
            cout << "Title: " << c.title << "\n";
            return;
        }
    }

    cout << "Course not found.\n";
}

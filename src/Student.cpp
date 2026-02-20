#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Student> students;

Student::Student(string i, string n) {
    id = i;
    name = n;
}

void loadStudents() {
    ifstream file("data/students.txt");
    string id, name;

    while (getline(file, id, ',') && getline(file, name)) {
        students.push_back(Student(id, name));
    }

    file.close();
}

void registerStudent() {
    string id, name;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    students.push_back(Student(id, name));

    ofstream file("data/students.txt", ios::app);
    file << id << "," << name << endl;
    file.close();

    cout << "Student registered successfully.\n";
}

void searchStudent() {
    string searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    for (auto s : students) {
        if (s.id == searchID) {
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

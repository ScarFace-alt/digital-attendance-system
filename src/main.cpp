#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string id;
    string name;

    Student(string i, string n) : id(i), name(n) {}
};

class Course {
public:
    string code;
    string name;
    string lecturer;

    Course(string c, string n, string l) : code(c), name(n), lecturer(l) {}
};

vector<Student> students;
vector<Course> courses;

void loadStudents() {
    ifstream file("students.txt");
    string id, name;

    while (getline(file, id, ',') && getline(file, name)) {
        students.push_back(Student(id, name));
    }

    file.close();
}

void loadCourses() {
    ifstream file("courses.txt");
    string code, name, lecturer;

    while (getline(file, code, ',') &&
           getline(file, name, ',') &&
           getline(file, lecturer)) {
        courses.push_back(Course(code, name, lecturer));
    }

    file.close();
}

void registerStudent() {
    string id, name;

    cout << "\nEnter Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);

    students.push_back(Student(id, name));

    ofstream file("students.txt", ios::app);
    file << id << "," << name << endl;
    file.close();

    cout << "Student registered successfully.\n";
}

void registerCourse() {
    string code, name, lecturer;

    cout << "\nEnter Course Code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, name);
    cout << "Enter Lecturer Name: ";
    getline(cin, lecturer);

    courses.push_back(Course(code, name, lecturer));

    ofstream file("courses.txt", ios::app);
    file << code << "," << name << "," << lecturer << endl;
    file.close();

    cout << "Course registered successfully.\n";
}

void searchStudent() {
    string searchID;
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;

    bool found = false;

    for (auto s : students) {
        if (s.id == searchID) {
            cout << "Student Found:\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

int main() {
    loadStudents();
    loadCourses();

    int choice;

    while (true) {
        cout << "\n=== DIGITAL ATTENDANCE SYSTEM ===\n";
        cout << "1. Register Student\n";
        cout << "2. Register Course\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                registerCourse();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "System shutting down.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

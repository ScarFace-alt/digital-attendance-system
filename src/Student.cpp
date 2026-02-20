#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string id;
    string name;
};

vector<Student> students;

void saveStudents() {
    ofstream file("students.txt");
    for (auto s : students) {
        file << s.id << "," << s.name << endl;
    }
    file.close();
}

void loadStudents() {
    students.clear();
    ifstream file("students.txt");
    string id, name;
    while (getline(file, id, ',') && getline(file, name)) {
        students.push_back({id, name});
    }
    file.close();
}

void registerStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    students.push_back(s);
    saveStudents();
    cout << "Student registered.\n";
}

void viewStudents() {
    for (auto s : students) {
        cout << s.id << " - " << s.name << endl;
    }
}

void searchStudent() {
    string id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (auto s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void createSession() {
    string course, date;
    cout << "Course code: ";
    cin >> course;
    cout << "Date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + course + "_" + date + ".txt";
    ofstream file(filename);
    file.close();
    cout << "Session created.\n";
}

void markAttendance() {
    string course, date;
    cout << "Course code: ";
    cin >> course;
    cout << "Date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + course + "_" + date + ".txt";
    ofstream file(filename, ios::app);

    for (auto s : students) {
        char status;
        cout << "Mark " << s.name << " (P/A/L): ";
        cin >> status;
        file << s.id << "," << s.name << "," << status << endl;
    }

    file.close();
    cout << "Attendance recorded.\n";
}

void viewSessionReport() {
    string course, date;
    cout << "Course code: ";
    cin >> course;
    cout << "Date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + course + "_" + date + ".txt";
    ifstream file(filename);

    string line;
    int present = 0, absent = 0, late = 0;

    while (getline(file, line)) {
        cout << line << endl;
        char status = line.back();
        if (status == 'P') present++;
        else if (status == 'A') absent++;
        else if (status == 'L') late++;
    }

    cout << "\nSummary:\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;

    file.close();
}

int main() {
    loadStudents();
    int choice;

    while (true) {
        cout << "\n1.Register Student\n";
        cout << "2.View Students\n";
        cout << "3.Search Student\n";
        cout << "4.Create Session\n";
        cout << "5.Mark Attendance\n";
        cout << "6.View Session Report\n";
        cout << "7.Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: createSession(); break;
            case 5: markAttendance(); break;
            case 6: viewSessionReport(); break;
            case 7: return 0;
            default: cout << "Invalid.\n";
        }
    }
}

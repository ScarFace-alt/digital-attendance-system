#include <iostream>
#include <limits>
#include "Student.h"
#include "Course.h"

using namespace std;

void displayMenu() {
    cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
    cout << "1. Register Student\n";
    cout << "2. Search Student\n";
    cout << "3. Register Course\n";
    cout << "4. Search Course\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {

    loadStudents();
    loadCourses();

    int choice;

    while (true) {

        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {

            case 1:
                registerStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                registerCourse();
                break;

            case 4:
                searchCourse();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid option.\n";
     }
    }

    return 0;
}

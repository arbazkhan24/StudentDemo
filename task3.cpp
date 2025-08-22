#include <iostream>
#include <string>
using namespace std;

int students = 3;
int subjects = 5;

int main() {
    string subjectNames[subjects] = {"English", "Discrete", "DSA", "Math", "OOP"};
    string studentName;
    int rollNo;
    int marks[subjects];
    int totalMarks = 100;

    for (int i = 0; i < students; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, studentName);

        cout << "Enter roll number: ";
        cin >> rollNo;

        // Ask from user that enter the marks
        for (int j = 0; j < subjects; j++) {
            cout << "Enter marks in " << subjectNames[j] << " (out of 100): ";
            cin >> marks[j];

            // check that marks is correct 
            while (marks[j] < 0 || marks[j] > 100) {
                cout << "Invalid! Enter again (0 to 100): ";
                cin >> marks[j];
            }
        }
        cout << "\n-----------------------------------------\n";
        cout << "Student: " << studentName << " | Roll No: " << rollNo << "\n";
        cout << "-----------------------------------------\n";
        cout << "Subject\t Marks\t Grade\t Status\n";

        for (int j = 0; j < subjects; j++) {
            string grade, status;
            int percent = marks[j];

            // Grade calculation
            if (percent >= 90) grade = "A+";
            else if (percent >= 80) grade = "A";
            else if (percent >= 70) grade = "B";
            else if (percent >= 60) grade = "C";
            else if (percent >= 50) grade = "D";
            else grade = "F";

            // Check that students is passed or fail
            status = (percent >= 50) ? "Pass" : "Fail";
            cout << subjectNames[j] << "\t  " << marks[j] << "\t  " << grade << "\t " << status << endl;
        }
 
    }
 
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main() {
    string name, grade;
    int rollNumber;
    float marks1, marks2, marks3, total, percentage;
   
    cout << "Enter Student Name: ";
    getline(cin, name);  // To read full name with spaces

    cout << "Enter Roll Number: ";
    cin >> rollNumber;
 
    cout << "Enter marks for Subject 1 (out of 100): ";
    cin >> marks1;

    cout << "Enter marks for Subject 2 (out of 100): ";
    cin >> marks2;

    cout << "Enter marks for Subject 3 (out of 100): ";
    cin >> marks3;
 
    total = marks1 + marks2 + marks3;
    percentage = (total / 300.0) * 100;
 
    if (percentage >= 90) {
        grade = "A+";
    } else if (percentage >= 80) {
        grade = "A";
    } else if (percentage >= 70) {
        grade = "B";
    } else if (percentage >= 60) {
        grade = "C";
    } else if (percentage >= 50) {
        grade = "D";
    } else {
        grade = "F";
    }
    
    cout << endl;
    cout << "The Student Information is Given Below :" << endl;
    cout << endl;
    cout << "The Name of the student is : " << name << endl;
    cout << "The Roll Number of The student is : " << rollNumber << endl;
    cout << "Total Marks : " << total << endl;
    cout << "Percentage : " << percentage << " %" << endl;
    cout << "The Grade of student is : " << grade << endl;
    cout << "--------------------------------" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

/* ================= PERSON STRUCT ================= */
struct Person {
    string name;
    string address;
    int age;
    string cnic;
};

/* ================= PATIENT STRUCT ================= */
struct Patient {
    Person info;
    string disease;
    int wardNumber;
};

/* ================= DOCTOR STRUCT ================= */
struct Doctor {
    Person info;
    string specialty;
    double salary;
};

/* ================= APPOINTMENT STRUCT ================= */
struct Appointment {
    string patientName;
    string doctorName;
    string date;
    string time;
};

/* ================= GLOBAL ARRAYS & COUNTS ================= */
Patient patients[50];
Doctor doctors[10];
Appointment appointments[20];

int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;

/* ================= PERSON FUNCTIONS ================= */
void setPersonInfo(Person &p) {
    cin.ignore();
    cout << "Enter Name : ";
    getline(cin, p.name);

    cout << "Enter Address : ";
    getline(cin, p.address);

    cout << "Enter Age = ";
    cin >> p.age;
    cin.ignore();

    bool valid = false;
    while (!valid) {
        cout << "Enter CNIC (13 digits): ";
        getline(cin, p.cnic);

        if (p.cnic.length() != 13) {
            cout << "Error: CNIC must be exactly 13 digits long.\n";
            continue;
        }

        valid = true;
        for (char c : p.cnic) {
            if (c < '0' || c > '9') {
                valid = false;
                cout << "Error: CNIC must contain only digits.\n";
                break;
            }
        }
    }
}

void displayPersonInfo(Person p) {
    cout << "Name : " << p.name << endl;
    cout << "Age : " << p.age << endl;
    cout << "CNIC : " << p.cnic << endl;
    cout << "Address : " << p.address << endl;
}

/* ================= PATIENT FUNCTIONS ================= */
void addPatient() {
    if (patientCount >= 50) {
        cout << "No capacity for more patients.\n";
        return;
    }

    cout << "\nEnter Patient Information\n";
    setPersonInfo(patients[patientCount].info);

    cout << "Enter Disease : ";
    getline(cin, patients[patientCount].disease);

    cout << "Enter Ward Number = ";
    cin >> patients[patientCount].wardNumber;

    patientCount++;
}

void showAllPatients() {
    if (patientCount == 0) {
        cout << "No patients added yet.\n";
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        cout << "\n*** Patient " << i + 1 << " ***\n";
        displayPersonInfo(patients[i].info);
        cout << "Disease : " << patients[i].disease << endl;
        cout << "Ward Number : " << patients[i].wardNumber << endl;
        cout << "-----------------------------\n";
    }

    cout << "\nTotal Patients = " << patientCount << endl;
}

/* ================= DOCTOR FUNCTIONS ================= */
void addDoctor() {
    if (doctorCount >= 10) {
        cout << "No capacity for more doctors.\n";
        return;
    }

    cout << "\nEnter Doctor Information\n";
    setPersonInfo(doctors[doctorCount].info);

    cout << "Enter Specialty : ";
    getline(cin, doctors[doctorCount].specialty);

    cout << "Enter Salary = ";
    cin >> doctors[doctorCount].salary;

    doctorCount++;
}

void showAllDoctors() {
    if (doctorCount == 0) {
        cout << "No doctors added yet.\n";
        return;
    }

    string role;
    cout << "Restricted Info (admin/user): ";
    cin >> role;

    for (int i = 0; i < doctorCount; i++) {
        cout << "\n*** Doctor " << i + 1 << " ***\n";
        displayPersonInfo(doctors[i].info);
        cout << "Specialty : " << doctors[i].specialty << endl;

        if (role == "admin") {
            cout << "Salary : Rs. " << doctors[i].salary << endl;
        }
    }

    cout << "\nTotal Doctors = " << doctorCount << endl;
}

/* ================= APPOINTMENT FUNCTIONS ================= */
void scheduleAppointment() {
    if (appointmentCount >= 20) {
        cout << "Appointment list is full.\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter Appointment Details\n";
    cout << "Patient Name : ";
    getline(cin, appointments[appointmentCount].patientName);

    cout << "Doctor Name : ";
    getline(cin, appointments[appointmentCount].doctorName);

    cout << "Date (DD/MM/YYYY): ";
    getline(cin, appointments[appointmentCount].date);

    cout << "Time : ";
    getline(cin, appointments[appointmentCount].time);

    appointmentCount++;
}

void showAppointments() {
    if (appointmentCount == 0) {
        cout << "No appointments scheduled yet.\n";
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        cout << "\nAppointment " << i + 1 << endl;
        cout << "Patient : " << appointments[i].patientName << endl;
        cout << "Doctor : " << appointments[i].doctorName << endl;
        cout << "Date : " << appointments[i].date << endl;
        cout << "Time : " << appointments[i].time << endl;
    }
}

/* ================= BILLING ================= */
void billingSystem() {
    string patientName;
    int days;
    int dailyCharge = 300;

    cin.ignore();
    cout << "Enter Patient Name : ";
    getline(cin, patientName);

    cout << "Enter Days Stayed : ";
    cin >> days;

    cout << "Total Bill = Rs. " << days * dailyCharge << endl;
}


/* ================= Delete Patient ================= */
  void deletePatient() {
    int option;
    bool found = false;

    cout << "\nDelete Patient By:";
    cout << "\n1. CNIC";
    cout << "\n2. Name";
    cout << "\nEnter your choice: ";
    cin >> option;

    if (option == 1) {
        string cnic;
        cout << "Enter CNIC: ";
        cin >> cnic;   

        for (int i = 0; i < patientCount; i++) {
            if (patients[i].info.cnic == cnic) {
                for (int j = i; j < patientCount - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                patientCount--;
                cout << "Patient deleted successfully (by CNIC).\n";
                found = true;
                break;
            }
        }
    }
    else if (option == 2) {
        string name;
        cin.ignore();  
        cout << "Enter Patient Name: ";
        getline(cin, name);

        for (int i = 0; i < patientCount; i++) {
            if (patients[i].info.name == name) {
                for (int j = i; j < patientCount - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                patientCount--;
                cout << "Patient deleted successfully (by Name).\n";
                found = true;
                break;
            }
        }
    }
    else {
        cout << "Invalid option!\n";
        return;
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}

/* ================= MAIN ================= */
int main() {
    int choice;

    cout << "\n====================================================\n";
    cout << "   WELCOME TO LADY READING HOSPITAL PESHAWAR\n";
    cout << "====================================================\n";

    do {
        cout << "\n-------------------- MAIN MENU ----------------------\n";
        cout << "  [1] Add Patient\n";
        cout << "  [2] Add Doctor\n";
        cout << "  [3] View All Patients\n";
        cout << "  [4] View All Doctors\n";
        cout << "  [5] Schedule Appointment\n";
        cout << "  [6] View Appointments\n";
        cout << "  [7] Billing System\n";
        cout << "  [8] Delete Patient\n";
        cout << "  [0] Exit System\n";
        cout << "----------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "\n----------------------------------------------------\n";

        switch (choice) {
        case 1: addPatient(); break;
        case 2: addDoctor(); break;
        case 3: showAllPatients(); break;
        case 4: showAllDoctors(); break;
        case 5: scheduleAppointment(); break;
        case 6: showAppointments(); break;
        case 7: billingSystem(); break;
        case 8: deletePatient(); break;
        case 0:
            cout << "Thank you for using Hospital Management System!\n";
            break;
        default:
            cout << "Invalid Option! Please try again.\n";
        }

        cout << "\n====================================================\n";

    } while (choice != 0);

    return 0;
}

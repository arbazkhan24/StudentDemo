#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name;
    string Address;
    int age;
    string CNIC; 

    void setinformation() {
        cin.ignore();
        cout << "Enter Name : ";
        getline(cin, name);
        cout << "Enter Address : ";
        getline(cin, Address);
        cout << "Enter Age = ";
        cin >> age;
        cin.ignore();

        bool valid = false;
        while (!valid) {
            cout << "Enter CNIC (13 digits): ";
            getline(cin, CNIC);

            if (CNIC.length() != 13) {
                cout << "Error: CNIC must be exactly 13 digits long.\n";
                continue;
            }

            valid = true;
            for (char c : CNIC) {
                if (c < '0' || c > '9') {
                    valid = false;
                    cout << "Error: CNIC must contain only digits.\n";
                    break;
                }
            }
        }
    }

    void displayinformation() {
        cout << "The Name : " << name << endl;
        cout << "The Age = " << age << endl;
        cout << "The CNIC Number is = " << CNIC << endl;
        cout << "The Address is : " << Address << endl;
    }
};

class Patient : public Person {
public:
    string disease;
    int wardsnumber;
    static int count;

    void EnterPatientinformation() {
        cout << "Enter information for patient : " << endl;
        setinformation();
        cout << "Enter Disease : ";
        getline(cin, disease);
        cout << "Enter ward number = ";
        cin >> wardsnumber;
        count++;
    }

    void showPatientinformation() {
        cout << "**_____The Patient Detail are below_____**" << endl;
        displayinformation();
        cout << "The Disease of Patient is : " << disease << endl;
        cout << "Patient available at ward number = " << wardsnumber << endl;
    }

    static void showPatientCount() {
        cout << "Total number of patients = " << count << endl;
    }
};

int Patient::count = 0;

ostream& operator<<(ostream& out, Patient& p) {
    out << "**_____The Patient Detail are below_____**" << endl;
    out << "The Name : " << p.name << endl;
    out << "The Address is : " << p.Address << endl;
    out << "The Age : " << p.age << endl;
    out << "The CNIC Number : " << p.CNIC << endl;
    out << "The Disease of Patient is : " << p.disease << endl;
    out << "Patient available at ward number = " << p.wardsnumber << endl;
    return out;
}

class Doctor : public Person {
private:
    double salary;
public:
    string specialty;
    static int count;

    void Doctorinformation() {
        cout << "Enter information for doctor : " << endl;
        setinformation();
        cout << "Enter Specialty of a Doctor  : ";
        getline(cin, specialty);
        cout << "Enter salary for Doctor = ";
        cin >> salary;
        count++;
    }

    void showDoctorinfoormation() {
        cout << "****_____The Doctor Detail are below_____****" << endl;
        displayinformation();
        cout << "The Doctor Specialty is : " << specialty << endl;
    }

    double getSalary() const {
        return salary;
    }

    static void showDoctorCount() {
        cout << "Total number of doctors : " << count << endl;
    }
};

int Doctor::count = 0;

ostream& operator<<(ostream& out, Doctor& d) {
    out << "****_____The Doctor Detail are below_____****" << endl;
    out << "The Name : " << d.name << endl;
    out << "The Address is : " << d.Address << endl;
    out << "The Age : " << d.age << endl;
    out << "The CNIC Number : " << d.CNIC << endl;
    out << "The Specialty of Doctor is : " << d.specialty << endl;
    return out;
}

class Appointment {
public:
    string patientName;
    string doctorName;
    string date;
    string time;

    void scheduleAppointment() {
        cin.ignore();
        cout << "*******Enter Data for appointment******" << endl;
        cout << "Enter Patient Name : ";
        getline(cin, patientName);
        cout << "Enter Doctor Name : ";
        getline(cin, doctorName);
        cout << "Enter Appointment Date (Day/Month/Year): ";
        getline(cin, date);
        cout << "Enter Appointment Time (e.g. 10:30 AM): ";
        getline(cin, time);
    }

    void showAppointment() {
        cout << "Appointment Scheduled:" << endl;
        cout << "Patient: " << patientName << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Date: " << date << " at " << time << endl;
    }
};

class Hospital : public Patient, public Doctor, public Appointment {
    Patient p[50];
    Doctor d[10];
    Appointment app[20];
    int patientCount = 0;
    int doctorCount = 0;
    int appointmentCount = 0;

public:
    void addPatient() {
        if (patientCount < 50) {
            p[patientCount].EnterPatientinformation();
            patientCount++;
        } else {
            cout << "We have no capacity for more Patients." << endl;
        }
    }

    void addDoctor() {
        if (doctorCount < 10) {
            d[doctorCount].Doctorinformation();
            doctorCount++;
        } else {
            cout << "No capacity for more Doctors." << endl;
        }
    }

    void showAllPatients() {
        if (patientCount == 0) {
            cout << "No patients added yet." << endl;
            return;
        }

        for (int i = 0; i < patientCount; i++) {
            cout << p[i];
        }

        Patient::showPatientCount();
    }

    void showAllDoctors() {
        if (doctorCount == 0) {
            cout << "No doctors added yet." << endl;
            return;
        }

        string caution;
        cout << "Restricted Information: Please identify yourself as 'admin' or 'user' to continue: ";
        cin >> caution;

        for (int i = 0; i < doctorCount; i++) {
            cout << d[i];
            if (caution == "admin") {
                cout << "The Doctor Salary is : Rs." << d[i].getSalary() << endl;
            }
        }

        Doctor::showDoctorCount();
    }

    void scheduleAppointment() {
        if (appointmentCount < 20) {
            app[appointmentCount].scheduleAppointment();
            appointmentCount++;
        } else {
            cout << "Appointment list is full." << endl;
        }
    }

    void showAppointments() {
        if (appointmentCount == 0) {
            cout << "No appointments scheduled yet." << endl;
        } else {
            for (int i = 0; i < appointmentCount; i++) {
                cout << "\nAppointment number " << (i + 1) << " :" << endl;
                app[i].showAppointment();
            }
        }
    }

    void billingSystem() {
        string patientName;
        int days;
        int dailyCharge = 300;

        cin.ignore();
        cout << "Enter Patient Name for Billing: ";
        getline(cin, patientName);
        cout << "Enter Number of Days Stayed: ";
        cin >> days;

        double total = days * dailyCharge;
        cout << "Total Bill for " << patientName << " is = Rs. " << total << endl;
    }
};
int main() {
    Hospital p1;
    int num;

    cout << "\t\t<<<===*****_______WELCOME TO LADY READING HOSPITAL OF PESHAWAR_______*****===>>>" << endl << endl;

    do {
        cout << "\t\t\t************* MAIN MENU *************" << endl;
        cout << "\t\t\t=> Press 1 to ADD a Patient" << endl;
        cout << "\t\t\t=> Press 2 to ADD a Doctor" << endl;
        cout << "\t\t\t=> Press 3 to VIEW All Added Patients" << endl;
        cout << "\t\t\t=> Press 4 to VIEW All Added Doctors" << endl;
        cout << "\t\t\t=> Press 5 to Schedule Appointment" << endl;
        cout << "\t\t\t=> Press 6 to View Appointments" << endl;
        cout << "\t\t\t=> Press 7 for Billing system" << endl;
        cout << "\t\t\t=> Press 0 to EXIT" << endl;
        cout << "\t\t\tEnter Your Choice = ";
        cin >> num;

        switch (num) {
        case 1:
            p1.addPatient();
            break;
        case 2:
            p1.addDoctor();
            break;
        case 3:
            p1.showAllPatients();
            break;
        case 4:
            p1.showAllDoctors();
            break;
        case 5:
            p1.scheduleAppointment();
            break;
        case 6:
            p1.showAppointments();
            break;
        case 7:
            p1.billingSystem();
            break;
        case 0:
            cout << "\nThank you for using the Hospital Management System!" << endl;
            break;
        default:
            cout << "? Invalid Option. Please try again." << endl;
        }

        cout << "\n-----------------------------------------------------\n";

    } while (num != 0);

    return 0;
}

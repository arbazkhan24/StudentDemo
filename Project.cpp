#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
    Student* next;

    Student(int id, string name, float marks) {
        this->id = id;
        this->name = name;
        this->marks = marks;
        this->next = NULL;
    }
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = NULL;
    }

    // Add student
    void addStudent(int id, string name, float marks) {
        Student* newStudent = new Student(id, name, marks);

        if (head == NULL) {
            head = newStudent;
            cout << "Student added successfully!\n";
            return;
        }

        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newStudent;
        cout << "Student added successfully!\n";
    }

    // Search student by ID
    Student* searchStudent(int id) {
        Student* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

    // Update student record
    void updateStudent(int id) {
        Student* s = searchStudent(id);

        if (s == NULL) {
            cout << "Student not found!\n";
            return;
        }

        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, s->name);

        cout << "Enter new marks: ";
        cin >> s->marks;

        cout << "Student updated successfully!\n";
    }

    // Delete student
    void deleteStudent(int id) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->id == id) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully!\n";
            return;
        }

        Student* prev = NULL;
        Student* curr = head;

        while (curr != NULL && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Student not found!\n";
            return;
        }

        prev->next = curr->next;
        delete curr;

        cout << "Student deleted successfully!\n";
    }

    // Display all students
    void displayStudents() {
        if (head == NULL) {
            cout << "No records found!\n";
            return;
        }

        Student* temp = head;
        cout << "\n--- Student Records ---\n";

        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Marks: " << temp->marks << endl;
            temp = temp->next;
        }
        cout << "------------------------\n";
    }

    // ✅ Bubble Sort Helper Function (Swap Data)
    void swap(Student* a, Student* b) {
        int idTemp = a->id;
        string nameTemp = a->name;
        float marksTemp = a->marks;

        a->id = b->id;
        a->name = b->name;
        a->marks = b->marks;

        b->id = idTemp;
        b->name = nameTemp;
        b->marks = marksTemp;
    }

    // ✅ Sort by ID
    void sortByID() {
        if (head == NULL || head->next == NULL) return;

        for (Student* i = head; i->next != NULL; i = i->next) {
            for (Student* j = head; j->next != NULL; j = j->next) {
                if (j->id > j->next->id) {
                    swap(j, j->next);
                }
            }
        }
        cout << "Sorted by ID successfully!\n";
    }

    // ✅ Sort by Name
    void sortByName() {
        if (head == NULL || head->next == NULL) return;

        for (Student* i = head; i->next != NULL; i = i->next) {
            for (Student* j = head; j->next != NULL; j = j->next) {
                if (j->name > j->next->name) {
                    swap(j, j->next);
                }
            }
        }
        cout << "Sorted by Name successfully!\n";
    }

    // ✅ Sort by Marks
    void sortByMarks() {
        if (head == NULL || head->next == NULL) return;

        for (Student* i = head; i->next != NULL; i = i->next) {
            for (Student* j = head; j->next != NULL; j = j->next) {
                if (j->marks > j->next->marks) {
                    swap(j, j->next);
                }
            }
        }
        cout << "Sorted by Marks successfully!\n";
    }
};

int main() {
    StudentList list;
    int choice;

    while (true) {
        cout << "\n===== Student Record Management (Linked List) =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Sort by ID\n";
        cout << "7. Sort by Name\n";
        cout << "8. Sort by Marks\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float marks;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;

            list.addStudent(id, name, marks);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = list.searchStudent(id);
            if (s != NULL) {
                cout << "Record Found!\n";
                cout << "ID: " << s->id << "\nName: " << s->name
                     << "\nMarks: " << s->marks << endl;
            } else {
                cout << "Student not found!\n";
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            list.updateStudent(id);
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            list.deleteStudent(id);
        }

        else if (choice == 5) {
            list.displayStudents();
        }

        else if (choice == 6) {
            list.sortByID();
        }

        else if (choice == 7) {
            list.sortByName();
        }

        else if (choice == 8) {
            list.sortByMarks();
        }

        else if (choice == 9) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

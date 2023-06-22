#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    int ID;
    string Name;
    string Dept;
    int Sem;
    string Mobile;
    Student* next;
};

// Linked list class
class LinkedList {
private:
    Student* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Function to create a new student node
    Student* createStudent(int ID, string Name, string Dept, int Sem, string Mobile) {
        Student* newStudent = new Student;
        newStudent->ID = ID;
        newStudent->Name = Name;
        newStudent->Dept = Dept;
        newStudent->Sem = Sem;
        newStudent->Mobile = Mobile;
        newStudent->next = NULL;
        return newStudent;
    }

    // Function to insert a student at the front of the linked list
    void insertFront(int ID, string Name, string Dept, int Sem, string Mobile) {
        Student* newStudent = createStudent(ID, Name, Dept, Sem, Mobile);
        if (head == NULL) {
            head = newStudent;
        } else {
            newStudent->next = head;
            head = newStudent;
        }
        cout << "Student inserted at the front successfully." << endl;
    }

    // Function to insert a student at the end of the linked list
    void insertEnd(int ID, string Name, string Dept, int Sem, string Mobile) {
        Student* newStudent = createStudent(ID, Name, Dept, Sem, Mobile);
        if (head == NULL) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
        cout << "Student inserted at the end successfully." << endl;
    }

    // Function to insert a student after a given node
    void insertAfterNode(int nodeID, int ID, string Name, string Dept, int Sem, string Mobile) {
        Student* current = head;
        while (current != NULL) {
            if (current->ID == nodeID) {
                Student* newStudent = createStudent(ID, Name, Dept, Sem, Mobile);
                newStudent->next = current->next;
                current->next = newStudent;
                cout << "Student inserted after the given node successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Node with the given ID not found. Insertion failed." << endl;
    }

    // Function to delete a student from the front of the linked list
    void deleteFront() {
        if (head == NULL) {
            cout << "Linked list is empty. Deletion failed." << endl;
        } else {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted from the front successfully." << endl;
        }
    }

    // Function to delete a student from the end of the linked list
    void deleteEnd() {
        if (head == NULL) {
            cout << "Linked list is empty. Deletion failed." << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Student deleted from the end successfully." << endl;
        } else {
            Student* current = head;
            Student* prev = NULL;
            while (current->next != NULL) {
                prev = current;
                current = current->next;
            }
            delete current;
            prev->next = NULL;
            cout << "Student deleted from the end successfully." << endl;
        }
    }

    // Function to display the linked list and count the number of nodes
    void display() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
        } else {
            cout << "Student Data:" << endl;
            Student* current = head;
            int count = 0;
            while (current != NULL) {
                count++;
                cout << "ID: " << current->ID << endl;
                cout << "Name: " << current->Name << endl;
                cout << "Department: " << current->Dept << endl;
                cout << "Semester: " << current->Sem << endl;
                cout << "Mobile: " << current->Mobile << endl;
                cout << "--------------------------" << endl;
                current = current->next;
            }
            cout << "Total number of nodes: " << count << endl;
        }
    }
};

int main() {
    LinkedList list;
    int choice, ID, Sem;
    string Name, Dept, Mobile;
    int nodeID;

    while (true) {
        cout << "--------------------------" << endl;
        cout << "Singly Linked List Operations" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Insert at the front" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a node" << endl;
        cout << "4. Delete from the front" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Department: ";
                cin >> Dept;
                cout << "Enter Semester: ";
                cin >> Sem;
                cout << "Enter Mobile: ";
                cin >> Mobile;
                list.insertFront(ID, Name, Dept, Sem, Mobile);
                break;
            case 2:
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Department: ";
                cin >> Dept;
                cout << "Enter Semester: ";
                cin >> Sem;
                cout << "Enter Mobile: ";
                cin >> Mobile;
                list.insertEnd(ID, Name, Dept, Sem, Mobile);
                break;
            case 3:
                cout << "Enter the ID of the node to insert after: ";
                cin >> nodeID;
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Department: ";
                cin >> Dept;
                cout << "Enter Semester: ";
                cin >> Sem;
                cout << "Enter Mobile: ";
                cin >> Mobile;
                list.insertAfterNode(nodeID, ID, Name, Dept, Sem, Mobile);
                break;
            case 4:
                list.deleteFront();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                list.display();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

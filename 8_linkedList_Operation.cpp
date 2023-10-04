#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string USN;
    string Name;
    string Branch;
    int Sem;
    string PhNo;
    Student *next;
};

class StudentLinkedList
{
private:
    Student *head;

public:
    StudentLinkedList()
    {
        head = nullptr;
    }

    void insertFront(string usn, string name, string branch, int sem, string phNo)
    {
        Student *newStudent = new Student;
        newStudent->USN = usn;
        newStudent->Name = name;
        newStudent->Branch = branch;
        newStudent->Sem = sem;
        newStudent->PhNo = phNo;
        newStudent->next = head;
        head = newStudent;
    }

    void insertEnd(string usn, string name, string branch, int sem, string phNo)
    {
        Student *newStudent = new Student;
        newStudent->USN = usn;
        newStudent->Name = name;
        newStudent->Branch = branch;
        newStudent->Sem = sem;
        newStudent->PhNo = phNo;
        newStudent->next = nullptr;

        if (head == nullptr)
        {
            head = newStudent;
        }
        else
        {
            Student *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Student *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Student *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void displayAndCount()
    {
        Student *current = head;
        int count = 0;

        if (current == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Student List:" << endl;
        while (current != nullptr)
        {
            cout << "USN: " << current->USN << endl;
            cout << "Name: " << current->Name << endl;
            cout << "Branch: " << current->Branch << endl;
            cout << "Sem: " << current->Sem << endl;
            cout << "PhNo: " << current->PhNo << endl;
            cout << "--------------------------" << endl;
            current = current->next;
            count++;
        }
        cout << "Number of students: " << count << endl;
    }
};

int main()
{
    StudentLinkedList studentList;
    int choice;
    string usn, name, branch, phNo;
    int sem;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Front\n";
        cout << "4. Delete at End\n";
        cout << "5. Display and Count\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter USN: ";
            cin >> usn;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter Semester: ";
            cin >> sem;
            cout << "Enter Phone Number: ";
            cin >> phNo;
            studentList.insertFront(usn, name, branch, sem, phNo);
            break;

        case 2:
            cout << "Enter USN: ";
            cin >> usn;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter Semester: ";
            cin >> sem;
            cout << "Enter Phone Number: ";
            cin >> phNo;
            studentList.insertEnd(usn, name, branch, sem, phNo);
            break;

        case 3:
            studentList.deleteFront();
            break;

        case 4:
            studentList.deleteEnd();
            break;

        case 5:
            studentList.displayAndCount();
            break;

        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. " << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

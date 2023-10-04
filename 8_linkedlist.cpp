#include <iostream>
using namespace std;

struct Student
{
    string USN, Name, Branch, PhNo;
    int Sem;
    Student *next;
};

class StudentLinkedList
{
private:
    Student *head = nullptr;

public:
    void insertFront(string usn, string name, string branch, int sem, string phNo)
    {
        Student *newStudent = new Student{usn, name, branch, phNo, sem, head};
        head = newStudent;
    }

    void insertEnd(string usn, string name, string branch, int sem, string phNo)
    {
        Student *newStudent = new Student{usn, name, branch, phNo, sem, nullptr};
        if (!head)
            head = newStudent;
        else
        {
            Student *current = head;
            while (current->next)
                current = current->next;
            current->next = newStudent;
        }
    }

    void deleteFront()
    {
        if (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteEnd()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Student *current = head;
        while (current->next->next)
            current = current->next;
        delete current->next;
        current->next = nullptr;
    }

    void displayAndCount()
    {
        Student *current = head;
        int count = 0;
        cout << "\nStudent List:\n";
        while (current)
        {
            cout << "USN: " << current->USN << "\nName: " << current->Name << "\nBranch: " << current->Branch << "\nSem: " << current->Sem << "\nPhNo: " << current->PhNo << "\n--------------------------\n";
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
        cout << "\nMenu:\n1. Insert at Front\n2. Insert at End\n3. Delete at Front\n4. Delete at End\n5. Display and Count\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter USN, Name, Branch, Semester, and Phone Number: ";
            cin >> usn >> name >> branch >> sem >> phNo;
            studentList.insertFront(usn, name, branch, sem, phNo);
            break;
        case 2:
            cout << "Enter USN, Name, Branch, Semester, and Phone Number: ";
            cin >> usn >> name >> branch >> sem >> phNo;
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
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}

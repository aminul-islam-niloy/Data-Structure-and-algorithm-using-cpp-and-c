#include <iostream>
using namespace std;

const int MAX = 5;
int a[MAX];
int n = 0;

void create()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void display()
{
    if (n == 0)
    {
        cout << "No elements to display." << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insert()
{
    if (n == MAX)
    {
        cout << "Array is full" << endl;
        return;
    }

    int pos;
    do
    {
        cout << "Enter a valid position: ";
        cin >> pos;
    } while (pos < 0 || pos > n);

    cout << "Enter the value to be inserted: ";
    cin >> a[n];
    n++;

    display();
}

void deleteElement()
{
    if (n == 0)
    {
        cout << "! Array is empty" << endl;
        return;
    }

    int pos;
    cout << "Enter a valid position: ";
    cin >> pos;

    if (pos < 0 || pos >= n)
    {
        cout << "! Invalid position." << endl;
        return;
    }

    int elem = a[pos];
    cout << "Deleted element is: " << elem << endl;

    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    display();
}

int main()
{
    int choice;
    bool exitMenu = false;

    while (!exitMenu)
    {
        cout << "1. Create an array of N integers" << endl;
        cout << "2. Display array elements" << endl;
        cout << "3. Insert element at a given position" << endl;
        cout << "4. Delete element at a given position" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            exitMenu = true;
            break;
        default:
            cout << "Please enter a valid choice." << endl;
        }
    }

    return 0;
}

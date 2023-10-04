#include <iostream>
using namespace std;

void createArray(int arr[], int size) {
    cout << "Enter " << size << " integer elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray(const int arr[], int size) {
    cout << "Array Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int elem, int pos) {
    if (pos >= 0 && pos <= size) {
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = elem;
        size++;
        cout << "Element inserted successfully.\n";
    } else {
        cout << "Invalid position.\n";
    }
}

void deleteElement(int arr[], int& size, int pos) {
    if (pos >= 0 && pos < size) {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted successfully.\n";
    } else {
        cout << "Invalid position.\n";
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    createArray(arr, size);

    cout << "\n--- Array Operations Menu ---\n";
    cout << "a. Display Array\n";
    cout << "b. Insert Element\n";
    cout << "c. Delete Element\n";
    cout << "x. Exit\n";

    char choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                displayArray(arr, size);
                break;
            case 'b':
                int elem, pos;
                cout << "Enter the element to insert: ";
                cin >> elem;
                cout << "Enter the position to insert at: ";
                cin >> pos;
                insertElement(arr, size, elem, pos);
                break;
            case 'c':
                cout << "Enter the position of the element to delete: ";
                cin >> pos;
                deleteElement(arr, size, pos);
                break;
            case 'x':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'x');

    delete[] arr;

    return 0;
}

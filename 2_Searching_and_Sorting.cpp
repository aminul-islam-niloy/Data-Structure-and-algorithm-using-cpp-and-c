#include <iostream>
using namespace std;

void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Array sorted successfully using Bubble Sort." << endl;
}

int linearSearch(int arr[], int N, int item) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int N, int item) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid;
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Linear Search" << endl;
    cout << "3. Binary Search" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, N);
            break;
        case 2: {
            int item;
            cout << "Enter the item to search: ";
            cin >> item;
            int linearSearchIndex = linearSearch(arr, N, item);
            if (linearSearchIndex != -1) {
                cout << "Item found at index " << linearSearchIndex << " using Linear Search." << endl;
            } else {
                cout << "Item not found using Linear Search." << endl;
            }
            break;
        }
        case 3: {
            int item;
            cout << "Enter the item to search: ";
            cin >> item;
            bubbleSort(arr, N); 
            int binarySearchIndex = binarySearch(arr, N, item);
            if (binarySearchIndex != -1) {
                cout << "Item found at index " << binarySearchIndex << " using Binary Search." << endl;
            } else {
                cout << "Item not found using Binary Search." << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Function to create an array of N integer elements
void createArray(int arr[], int N) {
    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

// Function to sort the array using Bubble Sort algorithm
void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted successfully using Bubble Sort." << endl;
}

// Function to search for an item using Linear Search algorithm
int linearSearch(int arr[], int N, int item) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == item) {
            return i; // Item found at index i
        }
    }
    return -1; // Item not found
}

// Function to search for an item using Binary Search algorithm
int binarySearch(int arr[], int low, int high, int item) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid; // Item found at index mid
        } else if (arr[mid] < item) {
            low = mid + 1; // Discard left half
        } else {
            high = mid - 1; // Discard right half
        }
    }
    return -1; // Item not found
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];

    // Create an array of N integer elements
    createArray(arr, N);

    // Sort the array using Bubble Sort algorithm
    bubbleSort(arr, N);

    int item;
    cout << "Enter the item to search: ";
    cin >> item;

    // Search for an item using Linear Search algorithm
    int linearSearchIndex = linearSearch(arr, N, item);
    if (linearSearchIndex != -1) {
        cout << "Item found at index " << linearSearchIndex << " using Linear Search." << endl;
    } else {
        cout << "Item not found using Linear Search." << endl;
    }

    // Search for an item using Binary Search algorithm
    int binarySearchIndex = binarySearch(arr, 0, N - 1, item);
    if (binarySearchIndex != -1) {
        cout << "Item found at index " << binarySearchIndex << " using Binary Search." << endl;
    } else {
        cout << "Item not found using Binary Search." << endl;
    }

    return 0;
}

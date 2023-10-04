#include <iostream>
using namespace std;

#define MAX 5

char circularQueue[MAX];
int front = -1;
int rear = -1;

bool isQueueEmpty() {
    return (front == -1 && rear == -1);
}

bool isQueueFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(char element) {
    if (isQueueFull()) {
        cout << "Circular Queue is full. Cannot enqueue element." << endl;
        return;
    }

    rear = (rear + 1) % MAX;
    circularQueue[rear] = element;

    if (isQueueEmpty()) {
        front = rear;
    }

    cout << "Element '" << element << " enqueued successfully." << endl;
}

void dequeue() {
    if (isQueueEmpty()) {
        cout << "Circular Queue is empty. Cannot dequeue element." << endl;
        return;
    }

    cout << "Element '" << circularQueue[front] << " dequeued successfully." << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void displayQueue() {
    if (isQueueEmpty()) {
        cout << "Circular Queue is empty. Nothing to display." << endl;
        return;
    }

    int i = front;
    cout << "Circular Queue elements: ";
    do {
        cout << circularQueue[i] << " ";
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    cout << endl;
}

int main() {
    int choice;
    char element;

    do {
        cout << "\nCircular Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        cout << "Stack is full. Cannot push." << endl;
    } else {
        stack[++top] = item;
        cout << "Element " << item << " pushed onto the stack." << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty. Cannot pop." << endl;
    } else {
        cout << "Element " << stack[top--] << " popped from the stack." << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice, item;
    while (true) {
        cout << "\nMenu:";
        cout << "\n1. Push an element onto the stack";
        cout << "\n2. Pop an element from the stack";
        cout << "\n3. Display stack elements";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to push: ";
                cin >> item;
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

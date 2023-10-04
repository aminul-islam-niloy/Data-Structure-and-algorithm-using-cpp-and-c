#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};


void insertILinkedList(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr || value < head->data)
    {
        // If the list is empty or the new value is smaller than the head, insert at the beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data < value)
    {
        current = current->next;
    }

    // Insert the new node after the current node
    newNode->next = current->next;
    current->next = newNode;
}


void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    insertILinkedList(head, 2);
    insertILinkedList(head, 4);
    insertILinkedList(head, 6);
    insertILinkedList(head, 8);
    insertILinkedList(head, 10);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    int valueToInsert;
    cout << "Enter a value to insert into the sorted linked list: ";
    cin >> valueToInsert;

    insertILinkedList(head, valueToInsert);

    cout << "Updated Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}

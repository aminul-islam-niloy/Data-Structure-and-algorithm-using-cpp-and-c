#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* createNode(int data) {
    ListNode* newNode = new ListNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void splitLinkedList(ListNode* head, ListNode*& front, ListNode*& back) {
    if (!head) {
        front = back = nullptr;
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    front = head;
    back = slow->next;
    slow->next = nullptr;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(11);

    ListNode* frontHalf;
    ListNode* backHalf;

    splitLinkedList(head, frontHalf, backHalf);

    printList(frontHalf);
    printList(backHalf);

    return 0;
}

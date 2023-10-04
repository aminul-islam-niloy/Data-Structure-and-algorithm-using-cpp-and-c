#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}


void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = nullptr;
    int keys[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        root = insert(root, keys[i]);
    }

    int choice, key;
    bool found;

    do {
        cout << "\nMenu:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Search for Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Enter the element to search: ";
                cin >> key;
                found = search(root, key);
                if (found) {
                    cout << "Element " << key << " found in the BST." << endl;
                } else {
                    cout << "Element " << key << " not found in the BST." << endl;
                }
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

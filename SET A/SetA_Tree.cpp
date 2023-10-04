#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int value, bool &alreadyInserted)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->data)
    {
        // Insert into the left subtree
        root->left = insert(root->left, value, alreadyInserted);
    }
    else if (value > root->data)
    {
        // Insert into the right subtree
        root->right = insert(root->right, value, alreadyInserted);
    }
    else
    {
        // Element is already present
        alreadyInserted = true;
    }

    return root;
}

// Function to display the path to an element in the BST
void displayPathToElement(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    if (value < root->data)
    {
        displayPathToElement(root->left, value);
    }
    else if (value > root->data)
    {
        displayPathToElement(root->right, value);
    }
}

int main()
{
    TreeNode *root = nullptr;
    bool alreadyInserted = false;

    while (true)
    {
        int elementToInsert;
        cout << "Enter an element to insert into the BST: ";
        cin >> elementToInsert;

        root = insert(root, elementToInsert, alreadyInserted);

        if (alreadyInserted)
        {
            cout << "Element is already present in the BST. Path to the element: ";
            displayPathToElement(root, elementToInsert);
            cout << endl;
        }
        else
        {
            cout << "Element inserted successfully into the BST." << endl;
        }
    }

    return 0;
}

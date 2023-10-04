#include <stdio.h>
#include <stdlib.h>

struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

typedef struct BSTNode Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}

void search(Node *root, int key)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return;
    }

    while (root != NULL)
    {
        if (key == root->data)
        {
            printf("Key element is present in BST.\n");
            return;
        }
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    printf("Key element is not found in the BST.\n");
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int choice, key, val, i, n;
    Node *root = NULL;

    while (1)
    {
        printf("\n~~~~BST MENU~~~~\n");
        printf("1. Create a BST\n");
        printf("2. Search\n");
        printf("3. BST Traversals\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("Enter a value: ");
                scanf("%d", &val);
                insert(&root, val);
            }
            break;

        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            search(root, key);
            break;

        case 3:
            if (root == NULL)
            {
                printf("BST is empty.\n");
            }
            else
            {
                printf("Inorder display: ");
                inorder(root);
                printf("\nPreorder display: ");
                preorder(root);
                printf("\nPostorder display: ");
                postorder(root);
                printf("\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}

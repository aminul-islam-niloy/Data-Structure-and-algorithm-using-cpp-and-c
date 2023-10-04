#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int n);
void printList();
void insertByPos(int value, int loc, struct node *head);

int main()
{
    int n, select, value, pos;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printList();

    printf("\n Enter the position: ");
            scanf("%d", &pos);
            printf("\n Enter the data: ");
            scanf("%d", &value);
            insertByPos(value, pos, head);

}
void createList(int n)
{
    struct node *temp, *newNode;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL){
        printf("Unable to access memory.\n");
        exit(0);
    }

    printf("\n Enter the data of node 1 : ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;
    for(i=2; i<=n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL){
            printf("Unable to access memory.\n");
            exit(0);
        }
        printf(" Enter the data of node %d : ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}

void printList()
{
    struct node *temp;
    if(head == NULL){
        printf("List is Empty!\n");
        exit(0);
    }
    temp = head;
    printf("\n List: ");
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertByPos(int value, int loc, struct node *head1)
{
    struct node *temp, *newNode;
    int i;
    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Unable to allocate memory.\n");
        exit(0);
    }

    newNode->data = value;
    newNode->next = NULL;

    temp = head1;
    for(i=2; i<loc; i++){
        temp = temp->next;
        //temp->next = newNode;
        if(temp == NULL){
            break;
        }
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printList();
}

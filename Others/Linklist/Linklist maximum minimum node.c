
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node *next;
} * head;

void createList(int n);
void printList();
void maxValue();
void minValue();
int main()
{
    int n;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printList();
    maxValue();
    minValue();
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL){
        printf("Unable to access memory.\n");
        exit(0);
    }

    printf("\n Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2; i<=n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL){
            printf("Unable to access memory\n");
            exit(0);
        }

        printf(" Enter the data of node %d: ", i);
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
        printf(" %d -> ", temp->data);
        temp = temp->next;

    }
    printf("NULL");
    printf("\n");
}

void maxValue()
{
    struct node *temp;
    int max;
    if(head == NULL){
        printf("List is Empty!\n");
        exit(0);
    }

    temp = head;
    max = temp->data;
    while(temp != NULL)
        {
        if(max < temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }

    printf("\n Maximum Value : %d\n", max);
}

void minValue()
{
    struct node *temp;
    int min;
    if(head == NULL){
        printf("List is empty!\n");
        exit(0);
    }

    temp = head;
    min = temp->data;
    while(temp != NULL){
        if(min > temp->data){
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("\n Minimum Value : %d\n", min);
}

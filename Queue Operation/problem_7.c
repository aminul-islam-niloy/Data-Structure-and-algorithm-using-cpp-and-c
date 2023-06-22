#include <stdio.h>

#define MAX 5

char circularQueue[MAX];
int front = -1;
int rear = -1;

int isQueueEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isQueueFull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

void enqueue(char element)
{
    if (isQueueFull())
    {
        printf("Circular Queue is full. Cannot enqueue element.\n");
        return;
    }
    else if (isQueueEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    circularQueue[rear] = element;
    printf("Element '%c' enqueued successfully.\n", element);
}

void dequeue()
{
    if (isQueueEmpty())
    {
        printf("Circular Queue is empty. Cannot dequeue element.\n");
        return;
    }
    else if (front == rear)
    {
        printf("Element '%c' dequeued successfully.\n", circularQueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Element '%c' dequeued successfully.\n", circularQueue[front]);
        front = (front + 1) % MAX;
    }
}

void displayQueue()
{
    if (isQueueEmpty())
    {
        printf("Circular Queue is empty. Nothing to display.\n");
        return;
    }

    int i = front;
    printf("Circular Queue elements: ");
    while (i != rear)
    {
        printf("%c ", circularQueue[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", circularQueue[rear]);
}

int main()
{
    int choice;
    char element;

    do
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf(" %c", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

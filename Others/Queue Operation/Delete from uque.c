#include<stdio.h>
#define MAX 5

int queueArray[MAX], front=-1, rear = -1;
int queue[];

void enqueue()
{
    if(rear == MAX-1)
        {
        printf("\n OVERFLOW\n");
    }
    else{
        if(front == -1)
        {
            front = 0;
        }
        printf("\n Enter a number: ");
        scanf("%d", &queueArray[++rear]);
    }

}
void display()
{
    int i;
    if (front == - 1)
        printf(" Queue is empty \n");
    else
    {
        printf(" Queue is : \n");
        for (i = front; i <= rear; i++)
            {
            printf("%d ", queueArray[i]);
        }
        printf("\n");
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else if(front == rear)
        {
        printf("Deleted Element: %d\n",queue[front]);
        front = rear = -1;
    }
    else{
        printf("Deleted Element: %d\n",queue[front]);
        front = (front+1);
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    enqueue();
    display();
    return 0;
}


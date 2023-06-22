#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int stack[MAX], top = -1;
void push(int item)
{
    if(top == MAX-1)
        {
        printf("\n OVERFLOW.\n");
    }
    else{
        top = top + 1;
        stack[top] = item;
        printf("\n %d is pushed in stack.\n", item);
    }
}


int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(9);
    push(1);
    push(7);
    push(6);

   printf("\n STACK: \n");
    for(int i=top; i>=0; i--)
        {
        printf("\ %d\n", stack[i]);
    }
}

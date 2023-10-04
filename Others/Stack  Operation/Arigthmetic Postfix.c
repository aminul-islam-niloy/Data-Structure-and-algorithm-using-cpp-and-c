#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

int stack[MAX],top=-1;

void push(int n)
{
    stack[++top]=n;
}
int pop()
{
    return stack[top--];
}

void postfix(char ex[])
{
    char *e;
    int A,B,value,num;

e=ex;
while(*e != NULL)
{
    if(isdigit(*e))
   {
    num=*e -48;
    push(num);
    }
else
    {
  A= pop();
  B= pop();

    switch(*e)
    {
    case '+':
        value=A+B;
        break;

    case '-':
        value=B-A;
        break;

    case '*':
        value=A*B;
        break;

    case '/':
        value=B/A;
        break;

    case '^':
        value=pow(B,A);
        break;

    }
    push(value);
}
e++;
}
printf("\n Result: %d\n", pop());
}

int main()

{
    char ex[MAX];
    printf("Enter your postfix expression:");
    scanf("%s",&ex);

    postfix(ex);
    return 0;
}

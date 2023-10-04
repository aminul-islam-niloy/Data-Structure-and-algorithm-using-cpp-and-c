#include <iostream>
#include <cstring>

using namespace std;

int evaluatePostfix(const char *postfixExpression)
{
    int stack[1000];
    int top = -1;

    for (int i = 0; postfixExpression[i]; i++)
    {
        char c = postfixExpression[i];

        if (isalpha(c))
        {
            int value;
            cout << "Enter the value of " << c << ": ";
            cin >> value;
            stack[++top] = value;
        }
        else if (isdigit(c))
        {
            stack[++top] = c - '0';
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            int result;
            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < operand2; j++)
                {
                    result *= operand1;
                }
                break;
            }
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main()
{
    char postfixExpression[1000];
    cout << "Enter the postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}

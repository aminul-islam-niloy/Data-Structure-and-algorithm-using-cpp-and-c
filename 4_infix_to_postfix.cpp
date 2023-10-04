#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int Precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> opStack;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            opStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!opStack.empty() && opStack.top() != '(')
            {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(')
            {
                opStack.pop();
            }
        }
        else if (isOperator(ch))
        {
            while (!opStack.empty() && opStack.top() 
            != '(' && Precedence(opStack.top()) >= Precedence(ch))
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    while (!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
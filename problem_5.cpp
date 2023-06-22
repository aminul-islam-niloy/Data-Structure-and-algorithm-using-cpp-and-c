#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> operands;

    for (char ch : expression) {
        if (isdigit(ch)) {
            operands.push(ch - '0');  // Convert char to integer and push to stack
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch(ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                case '%':
                    operands.push(operand1 % operand2);
                    break;
                case '^':
                    operands.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid operator encountered!";
                    return 0;
            }
        }
    }

    return operands.top();
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int choice;
    cout << "1. Evaluate a postfix expression" << endl;
    cout << "2. Solve the Tower of Hanoi problem" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        string postfixExp;
        cout << "Enter a postfix expression with single-digit operands and operators: ";
        cin >> postfixExp;

        int result = evaluatePostfix(postfixExp);
        cout << "Result: " << result << endl;
    } else if (choice == 2) {
        int n;
        cout << "Enter the number of disks for the Tower of Hanoi problem: ";
        cin >> n;

        towerOfHanoi(n, 'A', 'B', 'C');
    } else {
        cout << "Invalid choice!";
    }

    return 0;
}

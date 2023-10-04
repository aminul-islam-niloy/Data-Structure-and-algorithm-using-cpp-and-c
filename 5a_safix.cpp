#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int SuffixExpression(const string &expression) {
    stack<int> s;
    int operand1, operand2, result;

    for (char token : expression) {
        if (isdigit(token)) {
            s.push(token - '0'); // Convert character digit to integer
        } else if (token == '+' || token == '-' || token == '*' || token == '/' 
                                || token == '%' || token == '^') {
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();

            switch (token) {
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
                    if (operand2 == 0) {
                        cout << "Division by zero is not allowed." << endl;
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = static_cast<int>(pow(operand1, operand2));
                    break;
            }

            s.push(result);
        }
    }

    if (s.size() != 1) {
        cout << "Invalid expression" << endl;
        exit(1);
    }

    return s.top();
}

int main() {
    string expression;
    
    cout << "Enter a suffix expression: ";
    cin >> expression;

    int result = SuffixExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}

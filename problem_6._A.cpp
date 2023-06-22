#include <iostream>
using namespace std;

// Function to calculate the factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;

    // Read the input from the user
    cout << "Enter a number: ";
    cin >> n;

    // Calculate the factorial
    int result = factorial(n);

    // Display the result
    cout << "The factorial of " << n << " is " << result << std::endl;

    return 0;
}

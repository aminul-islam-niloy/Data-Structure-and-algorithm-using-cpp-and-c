#include <iostream>

// Function to calculate and display the Fibonacci sequence
void displayFibonacci(int n) {
    int first = 0, second = 1;

    std::cout << "Fibonacci Sequence of " << n << " numbers: ";

    // Display the first two numbers
    std::cout << first << " " << second << " ";

    // Generate and display the rest of the sequence
    for (int i = 3; i <= n; ++i) {
        int next = first + second;
        std::cout << next << " ";

        // Update values for the next iteration
        first = second;
        second = next;
    }

    std::cout << std::endl;
}

int main() {
    int n;

    // Get user input
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Call the function to display the Fibonacci sequence
    displayFibonacci(n);

    return 0;
}

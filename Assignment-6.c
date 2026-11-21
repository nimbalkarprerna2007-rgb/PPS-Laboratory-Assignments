#include <stdio.h>

// Function declarations
unsigned long long factorialWithoutRecursion(int n);
unsigned long long factorialWithRecursion(int n);

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Validation for negative numbers
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // 1. Without Recursion (Iterative)
        unsigned long long iterativeResult = factorialWithoutRecursion(num);
        printf("Factorial of %d without recursion = %llu\n", num, iterativeResult);

        // 2. With Recursion
        unsigned long long recursiveResult = factorialWithRecursion(num);
        printf("Factorial of %d with recursion = %llu\n", num, recursiveResult);
    }

    return 0;
}

// Function to find factorial WITHOUT recursion (Iterative Approach)
unsigned long long factorialWithoutRecursion(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to find factorial WITH recursion (Recursive Approach)
unsigned long long factorialWithRecursion(int n) {
    // Base Case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive Case
    return n * factorialWithRecursion(n - 1);
}

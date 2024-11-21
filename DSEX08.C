#include <stdio.h>

// ----- Recursion -----
// method to find factorial of given number
int factorialUsingRecursion(int n)
{
    if (n == 0)
        return 1;
    // recursion call
    return n * factorialUsingRecursion(n - 1);
}

// ----- Iteration -----
// Method to find the factorial of a given number
int factorialUsingIteration(int n)
{
    int res = 1, i;
    // using iteration
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Driver method
int main()
{
    int num = 5;
    printf("Factorial of %d using Recursion is: %d\n", num, factorialUsingRecursion(5));
    printf("Factorial of %d using Iteration is: %d", num, factorialUsingIteration(5));
    return 0;
}

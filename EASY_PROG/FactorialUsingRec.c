#include <stdio.h>

int factorial (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n-1);

}

int main () {
    int fact = 0, number;

    printf("\nEnter the number you want a factorial of: ");
    scanf("%d", &number);

    fact = factorial(number);

    printf("\nFactorial is %d", fact);
}
#include <stdio.h>

int main () {
    int fact = 1, num;

    printf("\nEnter number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("\nFactorial can't be negative !!!");
    }
    else {
        for (int i = 1; i <= num; i++) {
            fact = fact * i;
        }
        printf("\nFactorial is %d", fact);
    }
}
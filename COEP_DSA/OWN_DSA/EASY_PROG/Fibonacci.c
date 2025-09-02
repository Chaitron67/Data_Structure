#include <stdio.h>

int main () {
    int a = 0 , b = 1, c , n;

    printf("\nHow many numbers of fibonacci u want : ");
    scanf("%d", &n);

    printf("\t%d",a);
    printf("\t%d",b);

    for (int i = 3; i <= n; i++) {
        c = a + b;

        printf("\t%d", c);

        a = b;
        b = c;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {
    int a[3][3];

    printf("Enter the array elements : ");

    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDisplaying array elements : ");
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }

}
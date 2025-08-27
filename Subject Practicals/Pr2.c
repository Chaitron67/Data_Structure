#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {
    int a[100], n, i, j;

    printf("Enter the size of Array : ");
    scanf("%d", &n);

    printf("\nEnter the array elements : ");
    for (i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    int ch, ele, temp;

    do {
        printf("\n\nMain Menu");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1 : // inserting 
            printf("\nEnter the element : ");
            scanf("%d", &ele);

            a[n] = ele;
            n++;

            printf("\nElement inserted !!!");
            break;

        case 2 : // deleting 
            printf("\nEnter the element to delete : ");
            scanf("%d", &ele);

            for (i = 0; i<n; i++) {
                if (a[i] == ele) {
                    j = i;
                    while (j!=n) {
                        a[j] = a[j+1];
                        j++;
                    }
                    n--;
                    break;
                }
            }

            if (i == n) {
                printf("\nElement not found !!!");
            }
            else {
                printf("\nElement found !!!");
            }

            break;

        case 3 : // display 
            printf("\nArray contains : ");
            for (i = 0; i<n; i++) {
                printf("\t%d", a[i]);
            }
            break;

        case 4 : // exit
            exit(0);

        default :
            printf("\nIncorrect Choice !!!");
            break;
    }
    } while (1);
}
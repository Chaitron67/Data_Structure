#include <stdio.h>

int main () {
    int i = 0, size;
    int a[size];

    printf("Enter the Number of the elements you want to store in an array : ");
    scanf("%d", &size);

    printf ("Enter the elements of the array : ");

    while (i<size) {
        scanf("%d ", &a[i]);
        i++;
        if (i == size) {
        	i = 0;
        	break;
		}
    }

    printf("Elements in an Array : ");

    while (i<size) {
        printf("%d ", a[i]);
        i++;
    }

    return 0;
}

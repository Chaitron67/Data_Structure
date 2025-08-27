#include <stdio.h>

void bubble_sort (int a[], int n) {
    int i, j, temp;

    for (i = 0; i<n-1; i++) {
        for (j = 0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main () {
    int arr[100], n, i;

    printf("\nEnter the size of the array : ");
    scanf("%d", &n);

    printf("\nEnter the array elements : ");
    for (i = 0; i<n; i++) {
        scanf(" %d", &arr[i]);
    }

    printf("\nBefore sorting : ");
    for (i = 0; i<n; i++) {
        printf(" %d", arr[i]);
    }

    bubble_sort(arr, n);

    printf("\nAfter sorting : ");
    for (i = 0; i<n; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}
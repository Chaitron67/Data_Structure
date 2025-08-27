#include <stdio.h>

void insertion_sort (int a[], int n) {
    int i, j, key;

    for (i = 0; i<n; i++) {
        key = a[i];
        for (j = i-1; j>=0 && a[j]>key; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = key;

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
        printf("%d", arr[i]);
    }

    insertion_sort(arr, n);

    printf("\nAfter sorting : ");
    for (i = 0; i<n; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}
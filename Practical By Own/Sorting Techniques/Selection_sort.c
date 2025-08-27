#include <stdio.h>

void selection_sort (int a[], int n) 
{
    int i, j, min_ind = 0, temp;

    for (i = 0; i<n-1; i++) {
        for (j = i+1; j<n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
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
        printf("%d", arr[i]);
    }

    selection_sort(arr, n);

    printf("\nAfter sorting : ");
    for (i = 0; i<n; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}
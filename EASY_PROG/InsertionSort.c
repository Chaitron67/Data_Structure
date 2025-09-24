#include <stdio.h>

void insertionSort () {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;

    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i-1;

        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

        printf("\npass %d: \n", i+1);
        for (int i = 0; i < n; i++) {
            printf("\t%d", arr[i]);
        }
    }
}

int main () {
    insertionSort();
}
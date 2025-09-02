#include <stdio.h>

void selectionSort () {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        int small = arr[i];
        int index = i;
        for (int j = i+1; j < n; j++) {
            if (small > arr[j]) {
                small = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = small;
        arr[index] = temp;
        
        printf("\npass %d: \n", i+1);
        for (int i = 0; i < n; i++) {
            printf("\t%d", arr[i]);
        }
    }
}

int main () {
    selectionSort();
}
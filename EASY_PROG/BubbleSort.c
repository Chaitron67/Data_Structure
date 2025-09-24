#include <stdio.h>

void bubbleSort () {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
}

int main () {
    bubbleSort();
}
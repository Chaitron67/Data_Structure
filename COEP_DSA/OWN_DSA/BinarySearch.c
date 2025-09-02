#include <stdio.h>

void binarySearch () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int end = sizeof(arr)/sizeof(arr[0])-1;

    int beg = 0, found = 0, target = 5;
    
    while (beg <= end) {
        int mid = (beg+end)/2;
        if (arr[mid] == target) {
            printf("\n%d is index", mid+1);
            found = 1;
            break;
        }
        else if (arr[mid] > beg) {
            end = mid-1;
        }
        else {
            beg = mid+1;
        }
    }

    if (found == 0) {
        printf("Element not found !!!");
    }
}

int main () {
    binarySearch();
}
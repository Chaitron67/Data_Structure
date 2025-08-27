#include <stdio.h>

void sort(int a[], int n);

int main () {
    int a[10] = {30,20,10,40,15,19,60,11,80,5};
    int val, temp, pos = -1;

    sort(a, 10);

    for (int i = 0; i<10; i++) {
        printf("\t%d", a[i]);
    }

    printf("\nEnter the value you want to search : ");
    scanf("%d", &val);

    int beg, end, mid;
    beg = 0; 
    end = 9;

    while (beg <= end) {
        mid = (beg+end)/2;
        if (a[mid]==val) {
            pos = mid;
            break;
        }
        else if (a[mid] > val) {
            end = mid-1;
        }
        else {
            beg = mid+1;
        }
    }

    if (pos != -1) {
        printf("Value found at %d index", pos);
    }
    else {
        printf("VAlue not found");
    }
}

void sort (int a[], int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-1-i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

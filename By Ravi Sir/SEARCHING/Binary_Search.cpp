#include <stdio.h>

int main() {
    int size;
    printf("Enter the number you want store in an array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("\nEnter the elements of the array (please enter in a ascending order) : ");
    for (int i = 0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nElements of the array are = ");
    for (int i = 0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    
    int beg, end, mid, position, val;
    
    position = -1;
    beg = 0;
    end = (size - 1);
    
    printf("\nEnter the element you want to search : ");
    scanf("%d", &val);
    
    for (beg = 0; beg<=end; mid = (beg+end)/2) {
        if (arr[mid] == val) {
            position = mid;
            break;
        }
        else if (arr[mid] < val) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    if (position == -1) {
        printf("Value is not present in the array !!!");
    }
    else {
        printf("Value is present at %d position and %d index.", (position+1), position);
    }
    
    
    
    return 0;
    
}

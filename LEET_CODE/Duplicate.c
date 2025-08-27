#include <stdio.h>

// Function declaration
int removeDuplicates(int* nums, int numsSize);

int main() {
    // Example input
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Initial Array : ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Call your function
    int k = removeDuplicates(nums, numsSize);

    // Print result
    printf("Unique count (k): %d\n", k);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, counter = 0;
    
    for (i = 0; i < numsSize-1; i++) {
        int j = i+1;
        while (nums[i] == nums[j]) {
            counter++;
            j++;
        }

        if ((counter+i+1) == numsSize) {
            break;
        }

        while (counter != 0) {
            nums[j-1] = nums[j];
            j--;
            counter--;
        }
    }

    return i+1;
}

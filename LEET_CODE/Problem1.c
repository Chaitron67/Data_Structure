void moveZeroes(int* nums, int numsSize) {
    int n = numsSize, numsZeros = 0;
    int answer[20];

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            numsZeros++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            answer[i] = nums[i];
        }
    }

    numsSize = n - numsZeros;

    for (int i = 0; i < numsZeros; i++) {
        answer[numsSize + i] = 0;
    }

    for (int i = 0; i < n; i++) {
        nums[i] = answer[i];
    }
}


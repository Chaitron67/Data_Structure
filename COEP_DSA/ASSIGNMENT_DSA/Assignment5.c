#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening data.txt file.\n");
        return 1;
    }

    char line[1000];
    int bubbleArr[1000];
    int selectionArr[1000];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            bubbleArr[count] = atoi(token);
            selectionArr[count] = atoi(token);
            count++;
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);

    clock_t start1 = clock();
    bubbleSort(bubbleArr, count);
    clock_t end1 = clock();

    double bubbleTime = (double)(end1 - start1) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    selectionSort(selectionArr, count);
    clock_t end2 = clock();

    double selectionTime = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %f seconds\n", bubbleTime);
    printf("Selection Sort Time: %f seconds\n", selectionTime);

    FILE *out = fopen("graph.txt", "w");

    fprintf(out, "bubble %f\n", bubbleTime);

    fprintf(out, "selection %f\n", selectionTime);

    printf("Times saved to graph.txt successfully!\n");

    return 0;
}

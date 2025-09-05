#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Bubble Sort
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

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {

    int n;

    printf("Enter how many numbers to generate: ");
    scanf("%d", &n);

    int bubbleArr[n];
    int insertionArr[n];

    // random numbers generation:
    FILE *fp = fopen("data.txt", "w");

    for (int i = 0; i < n; i++) {
        int num = rand() % 10000;
        fprintf(fp, "%d ", num);

        bubbleArr[i] = num;
        insertionArr[i] = num;
    }

    fclose(fp);
    printf("Random numbers saved to data.txt successfully!\n");

    // Bubble Sort
    clock_t bubble_start = clock();
    bubbleSort(bubbleArr, n);
    clock_t bubble_end = clock();

    double bubbleTime = (double)(bubble_end - bubble_start) / CLOCKS_PER_SEC;

    // insertion Sort
    clock_t insertion_start = clock();
    insertionSort(insertionArr, n);
    clock_t insertion_end = clock();

    double insertionTime = (double)(insertion_end - insertion_start) / CLOCKS_PER_SEC;

    FILE *out = fopen("graph.txt", "w");

    if (out == NULL) {
        printf("Error creating graph.txt file.\n");
        return 1;
    }

    fprintf(out, "Bubble %f\n", bubbleTime);
    fprintf(out, "Insertion %f\n", insertionTime);
    fclose(out);

    printf("\nBubble Sort Time: %f seconds", bubbleTime);
    printf("\nInsertion Sort Time: %f seconds", insertionTime);
    printf("\nTimes saved successfully");
    
    return 0;
}

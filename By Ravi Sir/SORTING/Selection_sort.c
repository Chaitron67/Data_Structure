#include <stdio.h>

int main() {
	
	int arr[10], i, j, temp;
	
	printf("Enter the elements of the array : ");
	for (i = 0; i<=9; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("\nBefore sorting : ");
	for (i = 0; i<=9; i++) {
		printf("%d ", arr[i]);
	}
	
	for (i = 0; i<=8; i++) {
		for (j = i+1; j<=9; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}

	}
	
	printf("\nAfter sorting : ");
	for (i = 0; i<=9; i++) {
		printf("%d ", arr[i]);
	}
	
}

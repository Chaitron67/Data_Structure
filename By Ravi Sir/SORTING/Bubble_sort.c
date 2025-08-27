#include <stdio.h>

void main () {
	
	printf("\n-------------------# WELCOME TO BUBBLE SORT PROGRAM #-------------------\n");
	int arr[100], i, n, temp, pass;
	
	printf("\n Enter how many elements do you want to store in an array : ");
	scanf("%d", &n);
	
	printf("Enter the elements of the array : ");
	
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Before sorting : ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	for (pass = 0; pass < n-1; pass++) {
		for (i = 0; i < (n-1) - pass; i++) {
			if (arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	
	printf("\nAfter sorting : ");
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	
}

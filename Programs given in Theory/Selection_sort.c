#include <stdio.h>

int i, j, k;

int smallest(int arr[], int k, int n, int pos);
int selection_sort(int arr[], int n);


int main() {

	printf("\n-------------------# WELCOME TO SELECTION SORT PROGRAM #-------------------\n");

	int arr[100], i, n;
	
	printf("\n Enter how many elements do you want to store in an array : ");
	scanf("%d", &n);

	printf("\n Enter the elements of the array : \n");
	for (i = 0; i<n; i++) {
		printf("	Element %d = ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("\n	Before sorting : \n");
	for (i = 0; i<n; i++) {
		printf("	%d ", arr[i]);
	}
	
	selection_sort(arr, n);
	
	printf("\n	After sorting : \n");
	for (i = 0; i < n; i++) {
		printf("	%d ", arr[i]);
	}
	
	return 0;
}

int smallest(int arr[], int k, int n, int pos) {
	int small = arr[k];
	pos = k;
	
	for (j = k+1; j<n; j++) {
		if (arr[j] < small) {
			small = arr[j];
			pos = j;
		}
	}
	
	return pos;
}

int selection_sort(int arr[], int n) {
	int pos, temp;
	
	for (k = 0; k < n; k++) {
		pos = smallest(arr, k, n, pos);
		temp = arr[k];
		arr[k] = arr[pos];
		arr[pos] = temp;
	}
}

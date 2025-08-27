#include <stdio.h>

void quick_sort (int arr[], int min_ind, int max_ind);

int main () {
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
	
	quick_sort (arr, 0, (n-1));
	
	printf("\n	After sorting : \n");
	for (i = 0; i < n; i++) {
		printf("	%d ", arr[i]);
	}
	
	return 0;
}


void quick_sort (int arr[], int min_ind, int max_ind) {
	int i, j, pivot_ind, temp;
	
	if (max_ind > min_ind) {
		pivot_ind = min_ind;
		i = min_ind;
		j = max_ind;
		
		while (j>i) {
			while (arr[i] <= arr[pivot_ind] && i < max_ind) {
				i++;
			}
			
			while (arr[j] > arr[pivot_ind]) {
				j--;
			}
			
			if (j > i) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
		temp = arr[pivot_ind];
		arr[pivot_ind] = arr[j];
		arr[j] = temp;
		
		quick_sort (arr, min_ind,j-1);
		quick_sort (arr, j+1, max_ind);
	}
}

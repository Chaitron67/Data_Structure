#include <stdio.h>
#define max 10

int a[max];

int divide (int a[], int min_ind, int max_ind) {
	int mid, i;
	mid = (min_ind + max_ind)/2;

	if (min_ind < max_ind) {
		divide (a, min_ind, mid);
		
		sort_and_merge (a, min_ind, max_ind);
		divide(a, mid+1, max_ind);

		sort_and_merge (a, min_ind, max_ind);
		
		sort_and_merge (a, min_ind, max_ind);
	}
}

int sort_and_merge (int a[], int st_ind, int end_ind) {
	int i, j;

	for (i = st_ind; i <= end_ind - 1; i++) {
		for (j = i+1; j <= end_ind; j++) {
			if (a[i] > a[j]) {
				int temp;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main () {

	int i, n, j, sel_ele, temp;

	printf("Enter size of an array : ");
	scanf("%d", &n);

	printf("Enter the elements of the array : ");

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("Before sorting : ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	divide(a, 0, n-1);

	printf("\nAfter sorting : ");
	for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
	}
}

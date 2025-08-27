#include <stdio.h>

int main () {

	int n, i, j, sel_ele, temp;

	printf("Enter size of an array : ");
	scanf("%d", &n);
	
	int a[n];

	printf("Enter the elements of the array : ");

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("Before sorting : ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
	for (i = 0; i<n; i++) {
		sel_ele = a[i];
		for (j = i-1; j >= 0 && sel_ele < a[j]; j--) {
			a[j+1] = a[j];
		}
		a[j+1] = sel_ele;
	}
	
	printf("\nAfter sorting : ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
}

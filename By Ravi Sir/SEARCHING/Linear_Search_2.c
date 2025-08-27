#include <stdio.h>

int main () 
{
	int size, i;
	int arr[size];
	
	printf("Enter the number of element you want to store in an array : ");
	scanf("%d", &size);
	
	printf("Enter the Elements of the array :");
	for (i = 0; i<size; i++) {
		scanf("%d", &arr[i]);
	}	
	
	printf("Elements in array : ");
	for (i = 0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	
	int val, pos = -1;
	
	printf("Which number you want to Search in an array : ");
	scanf("%d", &val);
	
	for (i = 0; i<size; i++) {
		if (arr[i]==val) {
			pos = i;
			break;
		}
	}
	
	if (pos == -1) {
		printf("Element is not available in an Array!!!");
	}
	else {
		printf("Position is %d position and %d index.", (pos+1), pos);
	}
	
	return 0;
}

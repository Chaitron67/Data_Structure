#include <stdio.h>

int istar();

void main () {
	int lines;
	printf("Enter how many lines you want to print the pyramid : ");
	scanf("%d", &lines);
	istar(lines);
}

int istar(int lines) {
	int i = 1;
	while (i<=lines) 
	{
		int j = 1;
		while (j<=i) {
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
}

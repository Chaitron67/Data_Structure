#include <stdio.h> 
#define size 100


int i, num, choice, new_ele, del_ele, temp;
int a[size];

int create () {
	
	printf("\n Enter the size of an array = ");
	scanf("%d", &num);
	printf("\n Enter the elements of the array : ");
	for (i = 0; i<num; i++) {
		printf("\n Element %d = ", i+1);
		scanf("%d", &a[i]);
	}
	
}

int insert () {
	printf("\n Please, enter the element you want to insert in an array : ");
	scanf("%d", &new_ele);
	a[num] = new_ele;
	num++;
}

int display() {
	printf("\n Elements in an Array : ");
	for (i = 0; i<num; i++) {
		printf("%d ", a[i]);
	}
}

int delete_ele () {
	printf("Enter Which element you want to delete : ");
	scanf("%d", &del_ele);
	for (i = 0; i<num; i++) {
		temp = 0;
		if (a[i] == del_ele) {
			temp = a[i+1];
			while (i<num-1) {
				a[i+1] = a[i];
				a[i] = temp;
				break;
			}
			
		}
	}
	num--; // reducing the size of the elements in array
	
	printf("\n%d is deleted from the array!!\n", del_ele);
}



int main () {
	
	printf("	- Welcome to Array Program -	");
	
	do {
		
		printf("\n	1. Create an array.\n");
        printf("	2. Insert elements in an array.\n");
        printf("	3. Display the Elements of the array.\n");
        printf("	4. Delete existing array.\n");
        printf("	5. Exit.\n");
		
		printf("\nPlease, enter your choice : ");
		scanf("%d", &choice);
		
        switch (choice) {
        	
        	case 1 : 
        		create();
        		printf("\n");
        		break;

			case 2 :
				insert();
				printf("\n");
				break;
					
			case 3 :
  				display();
  				printf("\n");
				break;
					
			case 4 :
				delete_ele();
				printf("\n");
				break;
				
			case 5 :
				printf("\n Thank You :)\n");
				break;
					
			default :
				printf("\n Incorrect choice, Please enter correct option!!!\n");
				break;
		}

	} while (choice!=5);
	
	return 0;
	
}

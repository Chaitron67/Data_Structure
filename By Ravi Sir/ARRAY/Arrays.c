#include <stdio.h>

int size 

int create ();

int main () {

    int size, i;
    int arr [size];
    int choice;
    char con;

    do {

        printf("\n1. Create an array.\n");
        printf("2. Enter elements in an array.\n");
        printf("3. Display the Elements of the array.\n");
        printf("4. Delete existing array.\n");
        printf("5. Exit.\n");

        
        printf("\n\nYour choice : ");
        scanf("%d", &choice);


        switch (choice) {
            case 1 : printf ("Please, enter the how many element do you want to store in an array : ");
                    scanf ("%d", &size);
            break;

            case 2 : printf ("Do you want to continue (Y/N) : ");
                     scanf("%d", &con);
                     if (con == 'Y' || con == 'y') {
                        printf ("Enter the elements of the array : \n");
                        for (i = 0; i<size; i++) {
                            printf ("Element %d", i+1);
                            scanf("%d", arr[i]);
                        }
                        printf("\nArray Elements have taken and stored successfully !!!");
                     }
                     else {
                        continue;
                     }
            break;

            case 3 : printf("Elements of the array are : ");
                    for (i = 0; i<size; i++) {
                        printf("%d ", arr[i]);
                    }
            break;

            case 5 : printf ("\nThank YOu !!!\n");
                    
            break;

            default : printf ("Incorrect Selection !!!");
            break;
            
        }
    }while (1);


    return 0;

}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct PolyNode
{
	int coeff;
	int expo;
	struct PolyNode *next;
};

struct PolyNode * create_poly () {
    int high;
    struct PolyNode *nn, *first, *temp;
    first = NULL;

    printf("\nEnter the highest exponent : ");
    scanf("%d", &high);

    for (int i = high; i >= 0; i--) {
        nn = (struct PolyNode *) malloc (sizeof(struct PolyNode));

        printf("Enter the coefficient of %d : ", i);
        scanf ("%d", &nn->coeff);
        nn->expo = i;
        nn->next = NULL;

        if (first == NULL) {
            first = nn;
        }
        else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }// end of for loop
    return first;
} // End of CreatePoly() function

struct PolyNode * addPoly (struct PolyNode *f1, struct PolyNode *f2) {
    struct PolyNode *nn, *first, *temp, *temp1, *temp2;
    first = NULL;
    
    if (f1->expo < f2->expo) {
        temp = f1;
        f1 = f2;
        f2 = temp;
    }

    temp1 = f1; 
    while (temp1 != NULL) {
        nn = (struct PolyNode *) malloc (sizeof(struct PolyNode));

        temp2 = f2;
        while (temp1->expo != temp2->expo && temp2 != NULL) {
            temp2 = temp2->next;
        }

        if (temp2 == NULL) {
            // NO such similar exponent
            nn->coeff = temp1->coeff;
            nn->expo = temp1->expo;
            nn->next = NULL;
        }
        else {
            // Means equal exponent found 
            nn->coeff = temp1->coeff + temp2->coeff;
            nn->expo = temp1->expo;
            nn->next = NULL;
        }

        if (first == NULL) {
            first = nn;
        }
        else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }

        temp1 = temp1->next;
    } // End of the outer while loop
    return first;
} // End of addPoly() function 

void show_poly (struct PolyNode *first) {
    struct PolyNode *temp;
    temp = first;
    while (temp != NULL) {
        
        if (temp != first) {
            printf(" + ");
        }

        if (temp->coeff < 0) {
            printf("(%dx^%d)", temp->coeff, temp->expo);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->expo);
        }

        temp = temp->next;
    }
    printf("\n");
}

int main () {
    struct PolyNode *f1, *f2, *f3;

    int ch;

    do {
        system("cls");
        printf("\n1. Add");
        printf("\n2. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1 : // add poly
                // Create first : 
                printf("\nCreating First Polynomial Equation : ");
                f1 = create_poly();
                // Create Second :
                printf("\nCreating Second Polynomial Equation : ");
                f2 = create_poly();
                getch();
                // NOW add both : 
                f3 = addPoly(f1, f2);

                // Display all : 
                system("cls");
                printf("\nPolynomial Equation 1 : ");
                show_poly(f1);
                printf("\nPolynomial Equation 2 : ");
                show_poly(f2);
                printf("\nPolynomial Equation after Addition : ");
                show_poly(f3);
                break;

            case 2 : // Exit 
                exit(0);

            default :
                printf("\nIncorrect Choice !!!");
                break;
        }
        getch();
    }while(1);
}
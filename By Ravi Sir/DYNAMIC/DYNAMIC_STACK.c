#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int ele; 
    struct Node *next;
};

struct Node *nn, *top, *temp;

void push_op () {
    nn = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the element to PUSH : ");
    scanf("%d", &nn->ele);
    
    if (top == NULL) {
        nn->next = NULL;
        top = nn;
        printf("\nStack Created and element PUSHED !!!");
    }
    else {
        nn->next = top;
        top = nn;
        printf("\n%d element is PUSHED into Stack !!!", nn->ele);
    }
}// end of push_Op() function

void pop_op () {
    if (top == NULL) {
        printf("\nSTACK UNDERFLOW !!!");
    }
    else {
        temp = top;
        top = top->next;
        printf("\n%d element is POPPED !!!", temp->ele);
        free(temp);
    }
}

void display () {
    if (top == NULL) {
        printf("\nStack is empty, Nothing to display !!!");
    }
    else {
        printf("\nSTACK CONTAINS : ");
        temp = top;
        while(temp != NULL) {
            printf("\n\t%d", temp->ele);
            temp = temp->next;
        }
    }
}

int main () {
    int ch;

    top = NULL;
    
    do {
        system("cls");
        printf("\nMAIN MENU");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1 : // push operation 
                push_op();
                break;

            case 2 : // pop operation 
                pop_op();
                break;

            case 3 : // display operation
                display();
                break;

            case 4 : // exit
                exit(0);

            default :
                printf("\nIncorrect choice !!!");
                break;
        }
        getch();
    } while(1);
}
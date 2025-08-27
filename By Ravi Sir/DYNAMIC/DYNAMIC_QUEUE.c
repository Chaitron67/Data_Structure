#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int ele;
    struct Node *next;
};

struct Node *nn, *front, *rear, *temp;

void enqueue_op () {
    nn = (struct Node *) malloc (sizeof(struct Node));

    printf("\nEnter the element : ");
    scanf("%d", &nn->ele);
    nn->next = NULL;

    if (front == NULL ) {
        front = nn;
        rear = nn;
        printf("\nQUEUE CREATED, AND ELEMENT INSERTED !!!");
    }
    else {
        nn->next = NULL;
        rear->next = nn;
        rear = nn;
        printf("\n%d Element is Enqueued !!!", nn->ele);
    }
}

void dequeue_op () {
    if (rear == NULL) {
        printf("\nQUEUE UNDERFLOW !!!");
    }
    else {
        if (front == rear) {
            temp = front;
            printf("\n%d element is DEQUEUED !!!", temp->ele);
            free(temp);
            front = NULL;
            rear = NULL;
        }
        else {
            temp = front;
            front = front->next;
            printf("\n%d element is DEQUEUED !!!", temp->ele);
            free(temp);
        }
    }
}    


void display () {
    if (rear == NULL) {
        printf("\nQUEUE IS EMPTY, NOTHING TO DISPLAY !!!");
    }
    else {
        printf("\nQUEUE CONTAINS : ");
        temp = front;
        while (temp != NULL) {
            printf("\t%d", temp->ele);
            temp = temp->next;
        }
    }
}

int main () {
    int ch;
    front = NULL;
    rear = NULL;
    
    do {
        system("cls");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // enqueue 
                enqueue_op();
                break;

            case 2 : // dequeue
                dequeue_op();
                break;

            case 3 : // display
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
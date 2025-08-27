#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int MAX;
int cqueue[100];
int front = 0, rear = -1, ele;

int enqueue () {
    if (front == (rear+1) % MAX && rear != -1) {
        printf("\nCircular queue Overflow");
    }
    else {
        printf("Enter the element to ENQUEUE : ");
        scanf("\n%d", &ele);
        rear = (rear+1) % MAX;
        cqueue[rear] = ele;
        printf("\n%d element is ENQUEUE !!!", ele);
    }
}

int dequeue () {
    if (front == 0 && rear == -1) {
        printf("\nCircular queue Underflow");
    }
    else {
        ele = cqueue[front];
        front = (front+1) % MAX;
        printf("\n%d element is DEQUEUE from the queue", ele);
        if (front == (rear+1) % MAX) {
            front = 0;
            rear = -1;
        }
    }
}

int display () {
    if (front == 0 && rear == -1) {
        printf("\nCircular queue empty, nothing to display");
    }
    else {
        printf("\nCIRCULAR QUEUE CONTAINS : ");
        int i = front;
        do
        {
            printf("%d ", cqueue[i]);
            i = (i+1) % MAX;
        } while(i != (rear+1) % MAX);
    }
}

int main () {
    int ch, size;

    printf("Enter the size of the queue : ");
    scanf("%d", &MAX);

    do {
        system("cls");
        printf("\n**********************MAIN MENU**********************");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 :
                enqueue();
                break;

            case 2 :
                dequeue();
                break;
            
            case 3 :
                display();
                break;

            case 4 :
                printf("EXIT SUCCESSFULLY !!!");
                exit (0);
            
            default :
                printf("\nIncorrect choice, please enter correct choice !!!");
        }
        getch();
    } while (1);

    return 0;

}
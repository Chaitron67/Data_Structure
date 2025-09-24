#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function prototypes (no implementation yet)
int isFull() {
    if (rear == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1 && rear == - 1 || front > rear) {
        return 1;
    }
    return 0;
}

void peek () {
    if (isEmpty()) {
        printf("\nQueue is Empty !!!");
    }
    else { 
        printf("\nFRONT: %d", queue[front]);
    }
}

void enqueue(int data) {
    if (isFull()) {
        printf("\nQueue overflow !!!");
    }
    else {
        if (isEmpty()) {
            front++;
            rear++;
        }
        else {
            rear++;
        }
        queue[rear] = data;
        printf("\nINSERTED %d ELEMENT", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow !!!");
    }
    else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        }
        else 
        {
            front++;
        }
        
        printf("\nDEQUEUED %d", data);
    }
}

void display() {
    if (isEmpty()) { 
        printf("\nQueue is Empty !!!");
    }
    else {
        for (int i = front; i <= rear; i++) {
            printf("\t%d", queue[i]);
        }
    }
}

int main() {
    int ch, data;

    do {
        printf("\n\nMain Menu (Queue using Array)\n");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Peek (Front element)");
        printf("\n4. isFull");
        printf("\n5. isEmpty");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                if (isFull()) {
                    printf("\nQueue is Full !!!");
                } else {
                    printf("\nQueue is not Full !!!");
                }
                break;

            case 5:
                if (isEmpty()) {
                    printf("\nQueue is Empty !!!");
                } else {
                    printf("\nQueue is not Empty !!!");
                }
                break;

            case 6:
                display();
                break;

            case 7:
                printf("\nExited..!");
                exit(0);

            default:
                printf("\nWrong Input!!!");
        }

        getch();
    } while (1);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100 

int stack[MAX];
int top = -1;

int isFull () {
    if (top == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int data) {
    if (isFull()) {
        printf("\nStack Overflow !!!");
    }
    else {
        top++;
        stack[top] = data;
        printf("\n%d element is Pushed !!!", data);
    }
}

int isEmpty () {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow !!!");
    }
    else {
        int ele = stack[top];
        top--;
        printf("\n%d element is Popped !!!", ele);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty !!!");
    }
    else {
        for (int i = top; i >= 0; i--) {
            printf("\t%d\n", stack[i]);
        }
    }
}

int main() {
    int ch, data;

    do {
        printf("\n\nMain Menu (Stack using Array)\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. isFull");
        printf("\n4. isEmpty");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isFull()) {
                    printf("\nSTack is full !!!");
                } 
                else {
                    printf("\nStack is not full !!!");
                }
                break;

            case 4:
                if (isEmpty()) {
                    printf("\nStack is Empty !!!");
                }
                else {
                    printf("\nStack is not Empty !!!");
                }
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nExited..!");
                exit(0);

            default:
                printf("\nWrong Input!!!");
        }

        getch();
    } while (1);

    return 0;
}

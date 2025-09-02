#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int data) {
    struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = data;

    if (isEmpty()) {
        newNode->next = NULL;
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
    
    printf("\n%d element is pushed !!!", data);
}

void pop() {
    if (isEmpty()) {
        printf("\nStack underflow !!!");
    } 
    else {
        int ele = top->data;
        top = top->next;
        printf("\n%d element is Popped !!!", ele);
    }
}

void peek() {
    if (isEmpty()) {
        printf("\nStack is empty !!!");
    }
    else {
        int ele = top->data;
        printf("\nPeek Element : %d", ele);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty !!!");
    }
    else {
        struct Node *temp;
        temp = top; 
        while (temp != NULL) {
            printf("\t%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int ch, data;

    do {
        printf("\n\nMain Menu (Stack using Linked List)\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Top element");
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
                peek();
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

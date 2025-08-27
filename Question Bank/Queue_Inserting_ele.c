#include <stdio.h>
#include <conio.h>
#define Max 100
int queue[Max];
int front = -1;
int rear = -1;
int ele;

void insert_element () {
    if (front == 0 && rear == Max-1) {
        printf("Queue Overflow");
    }
    else {
        if (front = -1 && rear == -1) {
            front = 0;
            rear = 0;
        }
        printf("Enter the element to insert : ");
        scanf("%d", &ele);
        queue[rear] = ele;
        rear ++;
        printf("\n%d element inserted.", ele);
    }
}

int main () {
    int size;
    printf("\nEnter how many element you want to insert : ");
    scanf("%d", &size);

    for (int i = 0; i<size; i++) {
        insert_element();
    }

    printf("\nQueue contains : ");
    for (int i = 0; i<size; i++) {
        printf("\t%d", queue[i]);
    }
}

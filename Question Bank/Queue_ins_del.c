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
        printf("\nEnter the element to insert : ");
        scanf("%d", &ele);
        queue[rear] = ele;
        rear ++;
        printf("\n%d element inserted.", ele);
    }
}

void delete_element () {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow ");
    }
    else {
        ele = queue[front];
        printf("\n%d element is deleted ", ele);
        front ++;
    }
}

int main () {

    insert_element();
    insert_element();
    insert_element();
    insert_element();

    delete_element();
    delete_element();

    printf("\n");
    for (int i = front; i<rear; i++) {
        printf("\t%d", queue[i]);
    }

}

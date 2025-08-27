#include <stdio.h>
#define Max 100
int stack[Max];
int top = -1;

void push () {
    if (top == Max-1) {
        printf("Stack Overflow !!!");
    }
    else {
        int ele;
        printf("\nEnter element to push : ");
        scanf("%d", &ele);
        stack[top+1] = ele;
        top++;
        printf("\n%d element Pushed !!!", ele);
    }
}

void pop () {
    if (top == -1) {
        printf("Stack Underflow");
    }
    else {
        int ele;
        ele = stack[top];
        top--;
        printf("\n%d element is popped !!!", ele);
    }
}

void display () {
    if (top == -1) {
        printf("Stack is empty");
    }
    else {
        printf("\nSTack Contains : ");
        for (int i = top; i>=0; i--) {
            printf("\n%d", stack[i]);
        }
    }
}

int main () {
    push();
    push();
    push();
    push();

    display();

    pop();
    pop();

    display();
}
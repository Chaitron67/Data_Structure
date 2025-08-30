#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int ch, ele;
struct node *temp, *temp2, *newNode, *head;

void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtSpecific(int data);

void deleteFirst();
void deleteLast();
void deleteSpecific();

void insertNode()
{
    int data;
    printf("\nEnter the element : ");
    scanf("%d", &data);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("\nInserted first node !!!");
    }
    else
    {
        printf("\n 1. Insert at beginning");
        printf("\n 2. Insert at end");
        printf("\n 3. Insert after specific element");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertAtBeginning(data);
            break;

        case 2:
            insertAtEnd(data);
            break;

        case 3:
            insertAtSpecific(data);
            break;

        default:
            printf("\nInvalid choice !!!");
            break;
        }
    }
}

void deleteNode()
{
    if (head == NULL)
    {
        printf("\n List is empty!!!");
    }
    else
    {
        printf("\n 1. Delete at beginning");
        printf("\n 2. Delete at end");
        printf("\n 3. Delete specific element");
        printf("Enter which node you want to delete : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            deleteFirst();
            break;

        case 2:
            deleteLast();
            break;

        case 3:
            deleteSpecific();
            break;

        default:
            break;
        }
    }
}

void insertAtBeginning (int data) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    printf("\n%d inserted at beginning !!!", data);
} 

void insertAtEnd(int data){
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;

    printf("\n%d inserted at end !!!", data);
}

void insertAtSpecific(int data) {
    printf("\nEnter after which element you want to insert a new node : ");
    scanf("%d", &ele);

    temp = head;
    
    while (temp != NULL && temp->data != ele) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nElement Not Found !!!");
    }
    else {
        if (temp->next == NULL) {
            insertAtEnd(data);
        }
        else {
            newNode->next = temp->next;
            newNode->prev = temp;
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;

            printf("%d inserted after %d element", data, ele);
        }
    }
}

void deleteFirst() {
    ele = head->data;
    head = head->next;
    head->prev = NULL;

    printf("Deleted %d first element", ele);
}

void deleteLast() {
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    ele = temp->data;
    temp->prev->next = NULL;
    temp->prev = NULL;

    printf("Deleted %d last element", ele);
}

void deleteSpecific() {
    printf("\nEnter which element you want to delete : ");
    scanf("%d", &ele);

    temp = head;
    while (temp != NULL && temp->data != ele) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nElement not found");
    }
    else if (temp == head) {
        deleteFirst();
    }
    else if (temp->next == NULL) {
        deleteLast();
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        printf("\nDeleted %d element", ele);
    }
}

void display()
{
    if (head == NULL) {
        printf("\nList is empty !!!");
    }
    else {
        temp = head;
        while (temp != NULL) {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    head = NULL;

    do
    {
        // system("cls"); // just for clearing the output screen

        printf("\n\nMain Menu (Doubly Linked List)\n");
        printf("\n1. Insert Node...!");
        printf("\n2. Delete Node...!");
        printf("\n3. Display...!");
        printf("\n4. Exit...!");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertNode();
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExited..!");
            exit(0);
            break;

        default:
            printf("\nWrong Input!!!");
            break;
        }
        getch();
    } while (1);

    return 0;
}
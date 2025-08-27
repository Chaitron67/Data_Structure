#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

int ch;
struct node *temp, *prev, *newNode, *head;

void insertAtBeginning()
{
    temp = head;
    newNode->next = temp;
    head = newNode;
    printf("\nInserted at beginning!!!");
}

void insertAtEnding()
{
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\nInserted at Ending!!!");
}

void insertAfterElement()
{
    temp = head;
    printf("\nEnter element after which you want to insert : ");
    int prev;
    scanf("%d", &prev);

    while (temp->data != prev && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        temp->next = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("\nInserted after %d element!!!", prev);
}

void insertNode()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;

    printf("\nEnter the element : ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        printf("\nInserted!!!");
    }
    else
    {
        printf("\nEnter where you want to insert the element : ");
        printf("\n1. Begining");
        printf("\n2. After Element");
        printf("\n3. Ending\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertAtBeginning();
            break;

        case 2:
            insertAfterElement();
            break;

        case 3:
            insertAtEnding();
            break;

        default:
            printf("\nIncorrect Choice!!!");
            break;
        }
    }
}

void deleteNode()
{
    if (head == NULL)
    {
        printf("\nCan't perform delete operation, list is empty!!!");
    }
    else
    {
        int ele;
        printf("\nEnter the element to Delete : ");
        scanf("%d", &ele);

        int flag = 0;
        temp = head;
        prev = temp;

        if (head->data == ele) {
            head = head->next;
            flag = 1;
        }

        while (temp != NULL) {
            if (temp->data == ele) {
                prev->next = temp->next;
                flag = 1;
            }
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL && flag == 0) {
            printf("\nElement is not present in the List !!!");
        }
        else {
            printf("%d Element deleted successfully !!!", ele);
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty!!!");
    }
    else
    {
        temp = head;
        printf("\nLinked List : ");
        while (temp != NULL)
        {
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
        system("cls");
        printf("\n\nMain menu\n");
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
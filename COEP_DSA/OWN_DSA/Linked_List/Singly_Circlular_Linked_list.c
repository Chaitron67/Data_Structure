#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

int ch, ele;
struct node *temp, *prev, *newNode, *head;

void insertNode()
{
    int data;
    printf("\nEnter the element : ");
    scanf("%d", &data);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
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
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
            printf("\nInserted at beginning !!!");
            break;

        case 2:
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            printf("\nInserted at end !!!");
            break;

        case 3:
            printf("\nEnter the element after which you want to insert : ");
            scanf("%d", &ele);

            temp = head;
            while (temp->data != ele && temp->next != head)
            {
                temp = temp->next;
            }

            if (temp->data != ele)
            {
                printf("\nElement not found !!!");
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
                printf("\nInserted after %d !!!", ele);
            }
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
        printf("\n LIst is empty!!!");
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
            temp = head;
            ele = temp->data;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;

            printf("\n%d element deleted !!!", ele);
            break;

        case 2:
            temp = head;
            while (temp->next != head)
            {
                prev = temp;
                temp = temp->next;
            }

            ele = temp->data;
            temp->next = NULL;
            prev->next = head;

            printf("%d ele deleted !!!", ele);
            break;

        case 3:
            printf("\nEnter the element to delete : ");
            scanf("%d", &ele);

            if (head->data == ele)
            {
                temp = head;
                ele = temp->data;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                printf("\n%d element deleted !!!", ele);
            }
            else
            {
                temp = head;
                while (temp->data != ele && temp->next != head)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp->data != ele)
                {
                    printf("\nElement %d not found !!!", ele);
                    break;
                }

                prev->next = temp->next;
                printf("%d element deleted !!!", ele);
            }
            break;

        default:
            break;
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
        printf("\nCircular Linked List : ");
        do
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    head = NULL;

    do
    {
        // system("cls"); // just for clearing the output screen

        printf("\n\nMain Menu (Singly Circular Linked List)\n");
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

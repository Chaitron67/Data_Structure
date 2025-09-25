#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *nn = NULL;
struct node *temp = NULL;
struct node *temp2 = NULL;
struct node *head = NULL;

void insertAtBeg(int data);
void insertAtEnd(int data);
void insertAfterTarget(int data, int target);
void deleteFirst();
void deleteLast();
void deleteSpecific(int ele);
void display();

void insertAtBeg(int data)
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;

    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }

    printf("\nInserted %d at beginning!", data);
}

void insertAtEnd(int data)
{
    nn = (struct node *)malloc(sizeof(struct node));

    nn->data = data;
    nn->next = NULL;

    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }

    printf("\nInserted %d at ending!", data);
}

void insertAfterTarget(int data, int target)
{
    nn = (struct node *)malloc(sizeof(struct node));

    nn->data = data;
    nn->next = NULL;

    if (head == NULL)
    {
        head = nn;
        return;
    }
    else
    {
        temp = head;

        while (temp != NULL && temp->data != target)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\nElement %d not found!", target);
        }
        else
        {
            nn->next = temp->next;
            temp->next = nn;
            printf("\nInserted %d after %d!", data, target);
        }
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("\nFirst Element Deleted!");
    }
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("\nList is empty!");
    }
    else if (head->next == NULL)
    {

        free(head);
        head = NULL;
        printf("\nLast Element Deleted (only element)!");
    }
    else
    {
        temp = head;
        temp2 = NULL;

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = NULL;
        free(temp);
        printf("\nLast Element Deleted!");

    }
}

void deleteSpecific(int ele)
{
    if (head == NULL)
    {
        printf("\nList is empty!");
    }

    if (head->data == ele)
    {
        deleteFirst();

    }

    temp = head;
    temp2 = NULL;

    while (temp != NULL && temp->data != ele)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nElement %d not found!", ele);
    }
    else
    {

        temp2->next = temp->next;
        free(temp);
        printf("\nElement %d Deleted!", ele);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        printf("\nList: ");
        temp = head;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

int main(void)
{
    int ch, ele;

    while (1)
    {

        printf("\n\nSingly Linked List Menu\n");
        printf("1. Insert At beginning\n");
        printf("2. Insert At end\n");
        printf("3. Insert After specific element\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete specific element\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter Your Choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (ch)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertAtBeg(ele);
            break;

        case 2:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertAtEnd(ele);
            break;

        case 3:
            printf("Enter Element to insert: ");
            scanf("%d", &ele);

            int target;

            printf("Enter after which element you want to insert: ");
            scanf("%d", &target);

            insertAfterTarget(ele, target);
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            printf("Enter element to delete: ");
            scanf("%d", &ele);
            deleteSpecific(ele);
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nInvalid choice!");
            break;
        }
    }
    return 0;
}
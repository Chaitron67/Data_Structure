#include <stdio.h>
#include <stdlib.h>

struct List
{
    int ele;
    struct List *next;
};

void main()
{
    struct List *first, *ns, *temp;
    first = NULL;
    char ch;

    do
    {
        ns = (struct List *)malloc(sizeof(struct List));

        printf("\tEnter Element : ");
        scanf("%d", &ns->ele);

        ns->next = NULL;

        if (first == NULL)
        {
            first = ns;
        }
        else
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = ns;
        }

        printf("\tDo yo want to add another : ");
        scanf("%s", &ch);
    } while (ch == 'y' || ch == 'Y');

    int choice, sum, first_ele, next, swap, count = 0;

    while (1)
    {
        printf("\n\nWHICH OPERATION DO YOU WANT TO PERFORM : \n\n");
        printf("1. Sum of all.\n2. Largest.\n3.Smallest.\n4. Obtain Last Node.\n5.Swap Node.\n6. Display.\n7.Exit.");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sum = 0;
            temp = first;
            while (temp != NULL)
            {
                sum += temp->ele;
                temp = temp->next;
            }
            printf("\n\nSum of the all elements in Dynamic List is %d", sum);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            temp = first;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    printf("\n\nLast Node is %d", temp->ele);
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            break;

        case 5:
            temp = first;
            while (temp != NULL)
            {
                count++;
                if (temp != first && count % 2 != 0)
                {
                    swap = temp->ele;
                    temp->ele = next;
                    next = swap;
                }
                temp = temp->next;
                next = temp->ele;
            }
            printf("\nElements are Swapped!!!\n");
            break;

        case 6:
            printf("\n\tShowing the elements of DYNAMIC LINKED LIST : \n");
            temp = first;
            while (temp != NULL)
            {
                printf("\t%d", temp->ele);
                temp = temp->next;
            }
            break;

        case 7:
            exit(0);

        default : 
            printf("Incorrect Choice, please enter the Right Choice !!!");
            break;
        }
    }
}
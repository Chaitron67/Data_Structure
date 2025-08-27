#include <stdio.h>
#include <stdlib.h>

struct List
{
    int ele;
    struct List *next;
};

int sum(struct List *first, int ele)
{
    int i, left_ele, right_ele;

    struct List *temp = first;

    if (temp->ele == ele)
    {
        printf("\n\tFirst element, can't perform addition !!!");
        exit(0);
    }

    while (temp != NULL)
    {
        if (temp->next->ele == ele)
        {
            if (temp->next == NULL)
            {
                printf("\n\tLast element, can't perform addition !!!");
                exit(0);
            }

            left_ele = temp->ele;
            right_ele = temp->next->next->ele;

            printf("\n\tSum is : %d\n\n", left_ele + right_ele);
            exit(0);
        }
        temp = temp->next;
    }

    printf("Element is not present !!!");
}

void main()
{
    struct List *first, *ns, *temp;
    first = NULL;
    int choice;

    printf("\n\tEnter how many elements do you want to insert : ");
    scanf("%d", &choice);

    int i = 1;
    while (i <= choice)
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
        i++;
    }

    printf("\n\n\tShowing the elements of Dynamic List : \n");
    temp = first;
    while (temp != NULL)
    {
        printf("\t%d", temp->ele);
        temp = temp->next;
    }
    printf("\n");

    int topass;
    printf("\n\tEnter the element to pass : ");
    scanf("%d", &topass);

    sum(first, topass);
}
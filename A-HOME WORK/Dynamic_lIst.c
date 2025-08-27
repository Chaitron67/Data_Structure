#include <stdio.h>
#include <stdlib.h>

struct List {
    int ele;
    struct List *next;
};

void main () 
{
    struct List *first, *ns, *temp;
    first = NULL;
    char ch;

    do {
        ns = (struct List *) malloc (sizeof(struct List));

        printf("\tEnter Element : ");
        scanf("%d", &ns->ele);

        ns->next = NULL;

        if (first == NULL) {
            first = ns;
        }
        else {
            temp = first;
            while (temp->next!=NULL) {
                temp = temp->next;
            }

            temp->next = ns;
        }

        printf("\tDo yo want to add another : ");
        scanf("%s", &ch);
    }while (ch == 'y' || ch == 'Y');

    printf("\n\tShowing the elements of Dynamic List : \n");
    temp = first;
    while (temp != NULL) {
        printf("\t%d", temp->ele);
        temp = temp->next;
    }

    int sum = 0;
    temp = first;
    while (temp != NULL) {
        sum += temp->ele;
        temp = temp->next;
    }

    temp = first;
    int even = 0; 
    int odd = 0;
    while (temp != NULL) {
        if (temp->ele % 2 == 0)
        {
            even = even+1;
        }
        else {
            odd = odd+1;
        }
        temp = temp->next;
    }

    printf("\n\nSum of the Dynamic LIst is %d", sum);
    printf("\nCount of the Odd is %d\n", odd);
    printf("Count of the Even is %d.", odd);
}
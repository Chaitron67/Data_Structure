#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Student {
    int sroll;
    char sgen;
    struct Student *nextS;
};

void main () 
{
    struct Student *first, *ns, *temp;
    char ch;
    first = NULL;

    do 
    {
        ns = (struct Student *) malloc (sizeof(struct Student));

        printf("Enter roll no. : ");
        scanf("%d", &ns->sroll);
        printf("Enter gender : ");
        scanf("%s", &ns->sgen);

        temp = first;
        ns -> nextS = NULL;
        if (first == NULL) {
            first = ns;
        }
        else {
            temp = first;
            while (temp->nextS != NULL) {
                temp = temp->nextS;
            }

            temp->nextS = ns;
        }

        printf("Do you want to add another student : ");
        scanf("%s", &ch);

    } while (ch == 'y' || ch == 'Y');

    temp = first;
    while (temp != NULL) {
        printf("%d is %s\n", temp->sroll, temp->sgen);
        temp = temp->nextS;
    }

    printf("\nThe END");
}
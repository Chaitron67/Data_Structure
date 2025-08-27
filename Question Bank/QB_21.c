#include <stdio.h>
#include <stdlib.h>

struct Node {
    int ele;
    struct Node *next;
};

int main () {
    struct Node *first, *temp, *nn, *temp2;

    int size;
    printf("Enter how many element do you want to insert : ");
    scanf("%d", &size);

    first = NULL;
    for (int i = 0; i<size; i++) {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter element : ");
        scanf("%d", &nn->ele);
        nn->next = NULL;
        printf("Element inserted !!!");
        temp = first;
        if (first == NULL) {
            first = nn;
        }
        else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn; 
        }
    }

    printf("\nList contains : ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->ele);
        temp = temp->next;
    }

    char ch;
    do {
        printf("Do you want to delete element : ");
        scanf("%s", &ch);
        if (ch != 'n') {
            temp2 = first;
            while (temp2->next != temp ) {
                temp2 = temp2->next;
            }
            temp2->next = NULL;
            free(temp);
        }
    }while (ch != 'n');

    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->ele);
        temp = temp->next;
    }

}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int ele;
    struct Node *next;
};

struct Node *first, *temp;


void insert_at_beg () {
    struct Node *nn;
    nn = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the element : ");
    scanf("%d", &nn->ele);

    nn->next = NULL;

    if (first == NULL) {
        first = nn;
    }
    else {
        nn->next = first;
        first = nn;
    }

}

void insert_at_last () {
    struct Node *nn;
    nn = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter element : ");
    scanf("%d", &nn->ele);

    nn->next = NULL;

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

void insert_after_node () {
    struct Node *nn;
    nn = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter element : ");
    scanf("%d", &nn->ele);

    nn->next = NULL;

    struct Node *ptr, *preptr;

    
    if (first == NULL) {
        first = nn;
    }
    else {
        int val;
        printf("Enter after which ele u want to insert : ");
        scanf("%d", &val);
        ptr = first;
        preptr = ptr;
        while (preptr->ele != val) {
            if (ptr == NULL) {
                printf("%d value not found", val);
                return;
            }

            preptr = ptr;
            ptr = ptr->next;
        }

        // here we can't insert node after first node, so we can specify a external if condition or use do while loop for it : 
        preptr->next = nn;
        nn->next = ptr;
    }
}


void delete_first () {
    struct Node *temp;

    if (first == NULL) {
        printf("Underflow");
    }
    else {
        temp = first;
        first = first->next;
        printf("\n%d element node deleted", temp->ele);
        free(temp);
    }
}

void delete_last () {
    struct Node *temp, *temp2;

    if (first == NULL) {
        printf("Underflow");
    }
    else {
        temp = first;
        temp2 = temp;
        while (temp->next != NULL) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        printf("\n%d element node deleted", temp->ele);
        free(temp);
    }
}

void delete_node () {
    struct Node *temp, *temp2;

    if (first == NULL) {
        printf("underflow");
    }
    else {
        int val;
        printf("\nEnter which element's node you want to delete :");
        scanf("%d", &val);

        temp = first;
        temp2 = temp;

        while (temp->ele != val) {
            if (temp == NULL) {
                printf("%d Value not found", val);
            }

            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        printf("\n%d element node deleted", temp->ele);
        free(temp);
    }
}

void display () {
    if (first == NULL) {
        printf("\nList is empty !!!");
    }
    else {
        printf("\nList contains : ");
        temp = first;
        while (temp != NULL) {
            printf(" %d", temp->ele);
            temp = temp->next;
        }
    }
}

int main () {
    first = NULL;

    insert_at_beg();
    insert_at_beg();

    display();

    insert_at_last();
    insert_at_last();

    display();

    insert_after_node();
    insert_after_node();

    display();

    delete_first();
    display();
  
    delete_last();
    display();

    delete_node();
    display();
    delete_node();
    display();

    return 0;
}
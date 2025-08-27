#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>

struct Node {
    int ele;
    struct Node *prev, *next;
};

struct Node *temp, *nn, *first, *last;
int ch, sel_ele;

void insert_Node () {
    if (first == NULL) {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter the element : ");
        scanf("%d", &nn->ele);
        first = nn;
        last = nn;
        nn->prev = first;
        nn->next = last;
        printf("\nList Created and Node element is inserted !!!");
    }
    else {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter the element : ");
        scanf("%d", &nn->ele);
        nn->prev = NULL;
        nn->next = NULL;

        printf("\nSelect where you want to insert the node : ");
        printf("\n1. First Node");
        printf("\n2. Last Node");
        printf("\n3. After Selected Node");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // insert at first 
                nn->prev = last;
                nn->next = first->next;
                first->prev = nn;
                first = nn;
                last->next = first;
                printf("\n%d Element node is inserted at first position.", nn->ele);
                break;

            case 2 : // insert at last
                last->next = nn;
                nn->prev = last;
                nn->next = first;
                last = nn;
                first->prev = last;
                printf("\n%d Element node is inserted at Last position.", nn->ele);
                break;

            case 3 : // insert after selected node 
                printf("\nEnter the element after you want to insert the new node : ");
                scanf("%d", &sel_ele);
                if (first->ele == sel_ele) {
                    nn->prev = first;
                    nn->next = first->next;
                    first->next = nn;
                    printf("\n%d Element is inserted after first Node.", nn->ele);
                    return;
                }
                temp = first;
                do {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                } while (temp != first);
                // here temp points to selected node 

                if (temp == first) {
                    printf("\nElement is not present in the list !!!");
                    return;
                }
                else if (temp == last) {
                    last->next = nn;
                    nn->prev = last;
                    nn->next = first;
                    last = nn;
                    first->prev = last;
                    printf("\n%d Element node is inserted after Last Node.", nn->ele);
                }
                else {
                    nn->prev = temp;
                    nn->next = temp->next;
                    (temp->next)->prev = nn;
                    temp->next = nn;
                    printf("\n%d Element is inserted after selected node.", nn->ele);
                }
                break;
        }
    }
} // end of the insert_node() function

void delete_Node () {
    if (first == NULL) {
        printf("\nList Underflow !!!");
    }
    else if (first = last) {
        temp = first;
        first = NULL;
        last = NULL;
        printf("\n%d Element Node is deleted.", temp->ele);
        free(temp);
    }
    else {
        printf("\nWhich node you want to Delete");
        printf("\n1. First Node");
        printf("\n2. Last Node");
        printf("\n3. Selected Node");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // delete first 
                temp = first;
                first = first->next;
                first->prev = last;
                last->next = first;
                printf("\n%d Element first node is deleted.", temp->ele);
                free(temp);
                break;

            case 2 : // delete last
                temp = last;
                last = last->prev;
                last->next = first;
                first->prev = last;
                printf("\n%d Element last node is deleted", temp->ele);
                free(temp);
                break;

            case 3 : // delete selected 
                printf("\nEnter the Node element you want to Delete : ");
                scanf("%d", &sel_ele);

                if (first->ele == sel_ele) {
                    temp = first;
                    first = first->next;
                    first->prev = last;
                    last->next = first;
                    printf("\n%d Element First Node is deleted.", temp->ele);
                    free(temp);
                    return;
                }
                else if (last->ele == sel_ele) {
                    temp = last;
                    last = last->prev;
                    last->next = first;
                    first->prev = last;
                    printf("\n%d Element Last Node is deleted.", temp->ele);
                    free(temp);
                    return;
                }

                temp = first;
                do {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                } while (temp != first);
                // At the end temp points either to first or to selected element node

                if (temp == first) {
                    printf("\nSelected element is node is not present !!!");
                    return;
                }
                else {
                    (temp->next)->prev = temp->prev;
                    (temp->prev)->next = temp->next;
                    printf("\n%d Element Selected Node is deleted.", temp->ele);
                    free(temp); 
                }
                break;

                default :
                    printf("\nIncorrect Choice !!!");
                    break;
        }
    }
}

void display() {
    if (first == NULL) {
        printf("\nList empty, Nothing to display !!!");
    }
    else {
        temp = first;
        do {
            printf("\t%d", temp->ele);
            temp = temp->next;
        } while (temp != first);
    }
} // end of display() function

int main () {
    first = NULL;
    last = NULL;

    do {
        
        system("cls");
        printf("\nMAIN MENU");
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf ("\nEnter the choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // Insert operation 
                insert_Node();
                break;

            case 2 : // Delete operation
                delete_Node();
                break;

            case 3 : // Display Operation
                display();
                break;

            case 4 : 
                printf("\nExited Successfully !!!");
                exit(0);
            
            default :
                printf("\nIncorrect choice !!!");
        }
        getch();
    }while (1);

    return 0;
}
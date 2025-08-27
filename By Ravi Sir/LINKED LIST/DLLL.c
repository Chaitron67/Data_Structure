#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>

struct Node {
    int ele;
    struct Node *prev, *next;
};

struct Node *temp, *nn, *first;
int ch, sel_ele;

void insert_Node () {
    if (first == NULL) {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter the element to insert : ");
        scanf("%d", &nn->ele);
        nn->prev = NULL;
        nn->next = NULL;
        printf("List Created !!!");
        first = nn;
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

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // at first node
                nn->next = first;
                first->prev = nn;
                first = nn;
                printf("\nNode inserted at first position !!!");
                break;
            
            case 2 : // at last node
                temp = first;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                // Temp points to last element

                nn->prev = temp;
                temp->next = nn;
                printf("\nNode inserted at Last position !!!");
                break;

            case 3 : // at selected position
                printf("\nEnter the element after you want to insert the new node : ");
                scanf("%d", &sel_ele);

                temp = first;
                while (temp != NULL) {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                }
                // Temp points to the selected element

                if (temp == NULL) {
                    printf("\nElement not present in the List");
                }
                else if (temp == first) {
                    nn->prev = first;
                    nn->next = first->next;
                    first->next = nn;
                    (first->next)->prev = nn;
                    printf("\nNode inserted after the first node.");
                }
                else if (temp->next == NULL) {
                    nn->next = NULL;
                    nn->prev = temp;
                    temp->next = nn;
                    printf("\nNode inserted after the last node.");
                }
                else {
                    nn -> prev = temp;
                    nn -> next = temp->next;
                    (temp->next)->prev = nn;
                    temp->next = nn;
                    printf("\nNode inserted after selected element.");
                }
                break;
        }
    }
} // end of the insert_node() function

void delete_Node () {
    if (first == NULL) {
        printf("\nLinked list underflow");
    }
    else {
        if (first->next == NULL && first->prev == NULL) {
            temp = first;
            first = NULL;
            printf("\n%d element node is deleted.", temp->ele);
            free(temp);
            return;
        }
        printf("\nWhich node you want to Delete");
        printf("\n1. First Node");
        printf("\n2. Last Node");
        printf("\n3. Selected Node");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
           case 1 : // delete first node
                temp = first;
                (first->next)->prev = NULL;
                first = first->next;
                printf("\n%d element at First Node is Deleted !!!", temp->ele);
                free(temp);
                break;
                // case 1 ends
            
            case 2 : // delete last node 
                temp = first;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                // temp points to the last element

                (temp->prev)->next = NULL;
                printf("\n%d element Node is Deleted !!!", temp->ele);
                free(temp);
                break;
                // case 2 ends

            case 3 : // delete selected node
                printf("\nEnter the Node element you want to Delete : ");
                scanf("%d", &sel_ele);
                temp = first;
                while (temp != NULL) {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                }
                // temp points to the selected node element or last node
                if (temp == NULL) {
                    printf("\nSelected element is node is not present !!!");
                }
                else if (first->ele == sel_ele) {
                    temp = first;
                    (first->next)->prev = NULL;
                    first = first->next;
                    printf("\n%d element Node at First Node is Deleted !!!", temp->ele);
                    free(temp);
                }
                else if (temp->next == NULL) {
                    (temp->prev)->next = NULL;
                    printf("\n%d element Node at Last Node is Deleted !!!", temp->ele);
                    free(temp);
                }
                else {
                    (temp->next)->prev = temp->prev;
                    (temp->prev)->next = temp->next;
                    printf("\n%d element Node is Deleted !!!");
                    free(temp);
                }
                break;
                // case 3 ends
        }
    }
}

void display() {
    if (first == NULL) {
        printf("\nList Underflow !!!");
    }
    else {
        printf("\nLIST CONTAINS : ");
        temp = first;
        while (temp != NULL) {
            printf("\t%d", temp->ele);
            temp = temp->next;
        }
    }
} // end of display() function

int main () {
    
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
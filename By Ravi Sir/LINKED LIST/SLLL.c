#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>

struct Node {
    int ele;
    struct Node *next;
};
int ch, sel_ele;
struct Node *temp, *temp2, *nn, *first;

void insert_Node () {
    if (first == NULL) {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter the element to insert : ");
        scanf("%d", &nn->ele);
        nn->next = NULL;
        first = nn;
        printf("List Created and %d element is inserted !!!", nn->ele);
    } 
    else {
        nn = (struct Node *) malloc (sizeof(struct Node));
        printf("\nEnter the element : ");
        scanf("%d", &nn->ele);
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
                 first = nn;
                 printf("\n%d Element node is inserted.", nn->ele);
                 break;
            
            case 2 : // at last node 
                temp = first;
                while (temp->next != NULL) {
                    temp = temp->next;
                } // at last temp points to last element 

                temp->next = nn;
                printf("\n%d Element node is inserted.", nn->ele);
                break;

            case 3 : // inserted at selected
                printf("\nEnter after which Element you want to insert : ");
                scanf("%d", &sel_ele);

                temp = first;
                while (temp != NULL) {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Element not present !!!");
                    return;
                }
                else if (first->ele == sel_ele) {
                    first->next = nn;
                    first = nn;
                    printf("\n%d Element node inserted after the first node.", nn->ele);
                }
                else if (temp->next = NULL) {
                    temp->next = nn;
                    nn->next = NULL;
                    printf("%d Element node inserted after the last node", nn->ele);
                }
                else {
                    nn->next = (temp->next);
                    temp->next = nn;
                    printf("\n%d Element node inserted after the selected node", nn->ele);
                    return;
                }
        }
    }
}

void delete_node () {
    if (first == NULL) {
        printf("\nLinked list underflow !!!");
    }
    else {
        printf("\nWhich node you want to delete : ");
        printf("\n1. First node");
        printf("\n2. Last node");
        printf("\n3. Selected node");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // delete first node 
                temp = first;
                first = first->next;
                printf("\n%d element first node is deleted", temp->ele);
                free(temp);
                break;

            case 2 : // delete last node 
                temp = first;
                while (temp->next != NULL) {
                    temp = temp->next;
                }

                temp2 = first;
                while (temp2->next != temp) {
                    temp2 = temp2->next;
                }

                temp2->next = NULL;
                printf("\n%d element node is deleted", temp->ele);
                free(temp);
                break;

            case 3 : // delete selected node 
                printf("\nEnter the element of node you want to delete : ");
                scanf("%d", &sel_ele);

                if (first->ele == sel_ele) {
                    temp = first;
                    first = first->next;
                    printf("\n%d element node is deleted", temp->ele);
                    free(temp);
                    return;
                }


                temp = first;
                while(temp != NULL) {
                    if (temp->ele == sel_ele) {
                        break;
                    }
                    temp = temp->next;
                }

                temp2 = first;
                while (temp2->next != temp && temp != NULL) {
                    temp2 = temp2->next;
                }

                if (temp == NULL) {
                    printf("\nElement is not present !!!");
                }
                else if (temp->next == NULL) {
                    temp2->next == NULL;
                    printf("\n%d element node is deleted.", temp->ele);
                    free(temp);
                }
                else {
                    temp2->next = temp->next;
                    printf("\n%d element node is deleted", temp->ele);
                    free (temp);
                }
                break;
        }
    }
}

void display () {
    if (first == NULL) {
        printf("\nList is empty nothing to display !!!");
    }
    else {
        printf("\nList contains : ");
        temp = first;
        while (temp != NULL) {
            printf("\t%d", temp->ele);
            temp = temp->next;
        }
    }
}

int main () {
    first == NULL;

    do {
        system("cls");
        printf("\nMAIN MENU");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // insert node 
                insert_Node();
                break;

            case 2 : // delete node
                delete_node();
                break;

            case 3 : // display list
                display();
                break;

            case 4 : // exit 
                printf("\nProgram Exited !!!");
                exit(0);

            default : 
                printf("Incorrect Choice !!!");
        }
        getch();
    }while (1);
}
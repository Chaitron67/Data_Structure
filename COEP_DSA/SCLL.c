#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *nn, *temp, *temp2, *head;

void insertAtBeg(int data) {
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
    } else {
        nn->next = head;
        head = nn;
    }

    printf("\nInserted %d at begining !!!", data);
}

void insertAtEnd (int data) {
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = nn;

    }

    printf("\nInserted %d at ending !!!", data);
}

void insertAfterTarget (int data, int target) {
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
    } else {
        if (head->data == target) {
            insertAtBeg(data);
            return;
        }
        else {
            temp = head;
            while (temp != NULL && temp->data!= target) {
                temp = temp->next;
            } 

            if (temp == NULL) {
                printf("\nElement not found !!!");
            }
            else if (temp->next == target) {
                insertAtEnd(data);
            }
            else {
                nn->next = temp->next;
                temp->next = nn;
            }
        }
    }

    printf("\nInserted %d after %d !!!", data, target);
}

void deleteFirst () {
    if (head == NULL) {
        printf("\nList is empty !!!");
    }
    else {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element Deleted !!!");
    }
}

void deleteLast () {
    if (head == NULL) {
        printf("\nList is empty !!!");
    }
    else {
        temp = head;
        temp2 = head;
        while (temp->next != NULL) {
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = NULL;
        free(temp);
        printf("\nElement Deleted !!!");
    }
}

void deleteSpecific (int ele) {
    if (head == NULL) {
        printf("\nList is empty !!!");
    }
    else {

        if (head->data == ele) {
            deleteFirst();
        }

        temp = head;
        temp2 = head;
        while (temp!= NULL && temp->data!= ele) {
            temp2 = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nElement Not found !!!");
        }
        else if (temp->next == NULL) {
            deleteLast();
        }
        else {
            temp2->next = temp;
            free(temp);
            printf("\nElement Deleted !!!");    
        }
    }
}

void display () {
    if (head == NULL) {
        printf("\nList is empty !!!");
    }
    else {
        temp = head;
        while (temp != NULL) {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

int main {
    int ch, ele;
    head = NULL;

    while (1) {
            case 2 
            case 2 
        printf("\nSingly Linked List\n");
        printf("\n1. Insert At beg");
        printf("\n2. Insert At end");
        printf("\n3. Insert After specific ele");
        printf("\n4. Delete first");
        printf("\n5. Delete last");
        printf("\n6. Delete specific");
        printf("\n7. Display");
        printf("\n8 Exit")
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : 
                printf("\nEnter Element: ");
                scanf("%d", &ele);
                insertAtBeg(ele);
            break;

            case 2 : 
                printf("\nEnter Element: ");
                scanf("%d", &ele);
            break;

            case 3 : 
                printf("\nEnter Element: ");
                scanf("%d", &ele);

                int target;

                printf("\nEnter after which ele you want to insert: ");
                scanf("%d", &target);

                insertAfterTarget(ele, target);
            break;

            case 4 : 
                deleteFirst();
            break;

            case 5 : 
                deleteLast();
            break;

            case 6 : 
                printf("\nEnter element: ");
                scanf("%d", &ele);
                deleteSpecific(ele);
            break;

            case 7: 
                display();
            break;

            case 8 : 
                
            break;

            default :
                printf("\nInvalid choice");
            break;
        }
    }
}
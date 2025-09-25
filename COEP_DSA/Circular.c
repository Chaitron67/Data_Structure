#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *nn = NULL;
struct node *temp = NULL;
struct node *temp2 = NULL;
struct node *head = NULL; 

void insertAtBeg(int data);
void insertAtEnd(int data);
void insertAfterTarget(int data, int target);
void deleteFirst();
void deleteLast();
void deleteSpecific(int ele);
void display();

void insertAtBeg(int data) {
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
        nn->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        
        nn->next = head;
        head = nn;
        temp->next = head;
    }

    printf("\nInserted %d at beginning!", data);
}

void insertAtEnd (int data) {
    nn = (struct node *)malloc(sizeof(struct node));

    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
        nn->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = head;
    }

    printf("\nInserted %d at ending!", data);
}

void insertAfterTarget (int data, int target) {
    nn = (struct node *)malloc(sizeof(struct node));

    nn->data = data;
    nn->next = NULL;

    if (head == NULL) {
        head = nn;
        nn->next = head;
        return;
    }

    if (head->data == target) {
        insertAtEnd(data);
        return;
    }

    temp = head;
    do {
        temp = temp->next;
    } while (temp != head && temp->data != target);

    if (temp == head) {
        printf("\nElement %d not found!", target);
    }
    else if (temp->next == head) {
        insertAtEnd(data);
    } else {
        nn->next = temp->next;
        temp->next = nn;
        printf("\nInserted %d after %d!", data, target);
    }
    
}

void deleteFirst () {
    if (head == NULL) {
        printf("\nList is empty!");
    }
    else if (head->next == head) {
        head = NULL;
        printf("\nElement Deleted !");
    }
    else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        head = head->next;
        temp->next = head;

        printf("\nFirst Element Deleted!");
    }
}

void deleteLast () {
    if (head == NULL) {
        printf("\nList is empty!");
    }
    else if (head->next == head) {
        head = NULL;
        printf("\nLast Element Deleted (only element)!");
    }
    else {
        temp = head; 
        temp2 = head; 
        
        while (temp->next != head) {
            temp2 = temp;
            temp = temp->next;
        }
        
        temp2->next = head;
        free(temp);
        printf("\nLast Element Deleted!");
    }
}

void deleteSpecific (int ele) {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    if (head->data == ele) {
        deleteFirst();
        return;
    }

    temp = head;
    temp2 = NULL; 

    do {
        temp2 = temp;
        temp = temp->next;
    } while (temp != head && temp->data != ele);

    if (temp == head) {
        printf("\nElement %d not found!", ele);
    }
    else if (temp->next == head) {
        deleteLast();
        return;
    }
    else {
        temp2->next = temp->next;
        free(temp);
        printf("\nElement %d Deleted!", ele);
    }
}

void display () {
    if (head == NULL) {
        printf("\nList is empty!");
    }
    else {
        printf("\nList: ");
        temp = head;
        do {
            printf("\t%d", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main (void) { 
    int ch, ele;

    while (1) {

        printf("\n\nCicular Lined List menu\n");
        printf("1. Insert At beginning\n");
        printf("2. Insert At end\n");
        printf("3. Insert After specific element\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete specific element\n");
        printf("7. Display\n");
        printf("\n\nExtra Operations\n");
        printf("8. Count\n");
        printf("9. Reverse\n");
        printf("10. Exit\n"); 
        printf("Enter Your Choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (ch) {
            case 1 : 
                printf("Enter Element: ");
                scanf("%d", &ele);
                insertAtBeg(ele);
            break;

            case 2 : 
                printf("Enter Element: ");
                scanf("%d", &ele);
                insertAtEnd(ele); 
            break;

            case 3 : 
                printf("Enter Element to insert: ");
                scanf("%d", &ele);

                int target;

                printf("Enter after which element you want to insert: ");
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
                printf("Enter element to delete: "); 
                scanf("%d", &ele);
                deleteSpecific(ele);
            break;

            case 7: 
                display();
            break;

            case 8 : 
                exit(0);
            break;

            default :
                printf("\nInvalid choice!");
            break;
        }
    }
    return 0;

}
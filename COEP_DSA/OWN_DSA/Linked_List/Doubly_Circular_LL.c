#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Structure for Doubly Circular Linked List Node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterElement(int data, int target);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int ele);
void displayForward();
void displayBackward();

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node *temp = head->prev; // last node
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("\nInserted %d at Beginning!", data);
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node *temp = head->prev; // last node
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
    }
    printf("\nInserted %d at End!", data);
}

void insertAfterElement(int data, int target) {
    if (head == NULL) {
        printf("\nList is empty, inserting first node!");
        insertAtBeginning(data);
        return;
    }

    struct Node *temp = head;
    do {
        if (temp->data == target) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            printf("\nInserted %d after %d!", data, target);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("\nElement %d not found!", target);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    if (head->next == head) { // only one node
        printf("\nDeleted %d (last node)!", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *temp = head;
        int val = head->data;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
        printf("\nDeleted %d from Beginning!", val);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    if (head->next == head) { // only one node
        printf("\nDeleted %d (last node)!", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        int val = last->data;

        last->prev->next = head;
        head->prev = last->prev;
        free(last);

        printf("\nDeleted %d from End!", val);
    }
}

void deleteAtPosition(int ele) {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    struct Node *temp = head;
    do {
        if (temp->data == ele) {
            if (temp == head) {
                deleteAtBeginning();
            } else if (temp == head->prev) {
                deleteAtEnd();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                printf("\nDeleted %d!", temp->data);
                free(temp);
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("\nElement %d not found!", ele);
}

void displayForward() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    printf("\nList (Forward): ");
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void displayBackward() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    printf("\nList (Backward): ");
    struct Node *temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
}

int main() {
    int ch, data, pos;

    do {
        printf("\n\nMain Menu (Doubly Circular Linked List)\n");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert After Element");
        printf("\n4. Delete at Beginning");
        printf("\n5. Delete at End");
        printf("\n6. Delete Specific Element");
        printf("\n7. Display Forward");
        printf("\n8. Display Backward");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter element after which to insert: ");
                scanf("%d", &pos);
                insertAfterElement(data, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                printf("\nExited..!");
                exit(0);

            default:
                printf("\nWrong Input!!!");
        }

        getch();
    } while (1);

    return 0;
}

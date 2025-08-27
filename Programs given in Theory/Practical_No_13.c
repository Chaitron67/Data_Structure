#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int ele;
    struct node *next;
};

int main()
{
    struct node *ns, *first, *temp;
    int ele, ch = 1, ch2;
    first = NULL;

    int element;
    struct node *ele_p = (struct node *)malloc(sizeof(struct node));
    struct node *post_p = (struct node *)malloc(sizeof(struct node));

    do
    {
        system("cls");
        printf("\n\nDo you want to insert the element again : ");
        printf("\n1. Create new node");
        printf("\n2. Delete Node");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // To insert new node
            ns = (struct node *)malloc(sizeof(struct node));
            printf("\nNew node is created successfuly !!!");
            printf("\n\nEnter the element do you want to insert : ");
            scanf("%d", &ele);
            ns->ele = ele;
            printf("\n%d Element is inserted into the node !!!", ele);
            ns->next = NULL;
            if (first == NULL)
            {
                first = ns;
            }
            else
            {
                temp = first;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ns;
            }
            break;

        case 2: // Delete node
            system("cls");
            printf("\n**********DELETE OPERATIONS MENU**********");
            printf("\n1. BEGINING NODE");
            printf("\n2. ENDING NODE");
            printf("\n3. DELETE NODE IN BETWEEN");
            printf("\nEnter your choice : ");
            scanf("%d", &ch2);
            switch (ch2)
            {
            case 1: // begining node
                if (first == NULL)
                {
                    printf("\nCan't perfom delete operation, linked list empty !!!");
                }
                else
                {
                    element = first->ele;
                    ele_p = first;
                    first = first->next;
                    free(ele_p);
                    printf("\n%d Begining Element is deleted", element);
                }
                break;

            case 2: // ending node
                if (first == NULL)
                {
                    printf("\nCan't perfom delete operation, linked list empty !!!");
                }
                else
                {
                    temp = first;
                    while (temp != NULL)
                    {
                        if (first->next == NULL)
                        {
                            element = first->ele;
                            ele_p = first;
                            free(ele_p);
                            first = NULL;
                            break;
                        }
                        else if (temp->next->next == NULL)
                        {
                            element = temp->next->ele;
                            ele_p = temp->next;
                            free(ele_p);
                            temp->next = NULL;
                            break;
                        }
                        temp = temp->next;
                    }
                    printf("\n%d End Elements Node is Deleted.", element);
                }
                break;

            case 3: // in between
                if (first == NULL)
                {
                    printf("\nCan't perfom delete operation, linked list empty !!!");
                }
                else
                {
                    printf("\nEnter the element you want to delete : ");
                    scanf("%d", &element);
                    temp == first;
                    while (temp != NULL)
                    {
                        if (element == first->ele)
                        {
                            printf("\nCan't delete the first element.");
                            break;
                        }
                        else if (temp->next == NULL && element == temp->ele)
                        {
                            printf("\nCan't delete the last element.");
                            break;
                        }

                        if (temp->next->ele == element)
                        {
                            ele_p = temp->next;
                            element = temp->next->ele;

                            temp->next = temp->next->next;

                            free(ele_p);
                            printf("%d Element Node is Deleted.", element);
                            break;
                        }
                        temp = temp->next;
                    }
                    printf("Element is not present");
                }
                break;
            }
            break;

        case 3: // Display
            if (first == NULL)
            {
                printf("\nLinked list is empty, nothing to display !!!");
            }
            else
            {
                temp = first;
                printf("\n\nLinked list contains : ");
                while (temp != NULL)
                {
                    printf(" %d", temp->ele);
                    temp = temp->next;
                }
            }
            break;

        case 4: // Exit
            exit(0);

        default:
            printf("\nIncorrect choice...");
            break;
        }

        getch();
    } while (1);

    return 0;
}
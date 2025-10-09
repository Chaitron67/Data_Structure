#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *head, *root, *temp, *nn;

void insertElement(struct node *root, int ele)
{
    nn = (struct node *)malloc(sizeof(struct node));
    if (root == NULL)
    {
        root = nn;
        root->data = ele;
        root->left = NULL;
        root->right = NULL;
        head = nn;
    }
    else
    {
        if (root->data > ele)
        {
            if (root->left == NULL)
            {
                root->left = nn;
                nn->data = ele;
                nn->left = NULL;
                nn->right = NULL;
            }
            else
            {
                insertElement(root->left, ele);
            }
        }
        else if (root->data < ele)
        {
            if (root->right == NULL)
            {
                root->right = nn;
                nn->left = NULL;
                nn->right = NULL;
                nn->data = ele;
            }
            else
            {
                insertElement(root->right, ele);
            }
        }
    }
    printf("\n%d element inserted into tree !!!", ele);
}

void inorder(struct node *root)
{
    if (head == NULL)
    {
        printf("\nTree is empty !!!");
    }
    else
    {
        if (root)
        {
            inorder(root->left);
            printf("\t%d", root->data);
            inorder(root->right);
        }
    }
}

void preorder(struct node *root)
{
    if (head == NULL)
    {
        printf("\nTree is empty !!!");
    }
    else
    {
        if (root)
        {
            printf("\t%d", root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }
}

void postorder(struct node *root)
{
    if (head == NULL)
    {
        printf("\nTree is empty !!!");
    }
    else
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            printf("\t%d", root->data);
        }
    }
}

void deleteElement (struct node *root, int ele) {
    if (h)
}

int main(void)
{
    head = NULL;
    int ch, ele;

    while (1)
    {

        printf("\nBinary Search Tree\n");
        printf("\n1. Insert element");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        prinft("\n5. Delete element");
        printf("\n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertElement(head, ele);
            break;

        case 2:
            inorder(head);
            break;

        case 3:
            preorder(head);
            break;

        case 4:
            postorder(head);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nInvalid choice!");
            break;
        }
    }
    return 0;
}

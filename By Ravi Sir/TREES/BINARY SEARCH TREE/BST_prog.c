#include <stdio.h>
#include <stdlib.h>

struct BTNode {
    struct BTNode *lchild;
    int ele;
    struct BTNode *rchild;
};

void place_node (struct BTNode *root , struct BTNode *nn) {
    if (nn->ele < root->ele) {
        if (root->lchild == NULL) {
            root->lchild = nn;
        }
        else {
            place_node(root->lchild, nn);
        }
    }
    else {
        if (root->rchild == NULL) {
            root->rchild = nn;
        }
        else {
            place_node(root->rchild, nn);
        }
    }
}

void preorder_traversal (struct BTNode *root) {
    if (root != NULL) {
        printf(" %d", root->ele);
        preorder_traversal(root->lchild);
        preorder_traversal(root->rchild);
    }
}

void inorder_traversal (struct BTNode *root) {
    if (root != NULL) {
        inorder_traversal(root->lchild);
        printf(" %d", root->ele);
        inorder_traversal(root->rchild);
    }
}

void postorder_traversal (struct BTNode *root) {
    if (root != NULL) {
        postorder_traversal(root->lchild);
        postorder_traversal(root->rchild);
        printf(" %d", root->ele);
    }
}

void print_root (struct BTNode *root) {
    if (root != NULL) {
        printf("Root Node  : %d ", root->ele);
    }
}

void print_leafNode (struct BTNode *root) {
    if (root != NULL) {
        print_leafNode(root->lchild);
        // logic will be here : 
        if (root->lchild == NULL && root->rchild == NULL) {
            printf(" %d", root->ele);
        }
        print_leafNode(root->rchild);
    }
}

// function to print nodes having exact two child : 
void print_two_child (struct BTNode *root) {
    if (root != NULL) {
        print_two_child(root->lchild);
        if (root->lchild != NULL && root->rchild != NULL) {
            printf(" %d", root->ele);
        }
        print_two_child(root->rchild);
    }
}

// function to print nodes having only one child :
void print_only_oneChild (struct BTNode *root) {
    if (root != NULL) {
        print_only_oneChild(root->lchild);
        if ((root->lchild == NULL && root->rchild != NULL) || (root->rchild == NULL&& root->lchild != NULL)) {
            printf(" %d", root->ele);
        }
        print_only_oneChild(root->rchild);
    }
}

// function to print left child only :
void print_leftChild (struct BTNode *root) {
    if (root != NULL) {
        print_leftChild(root->lchild);
        printf("%d", root->ele);
    }
}

// function to print right child only :
void print_rightChild (struct BTNode *root) {
    if (root != NULL) {
        print_rightChild(root->rchild);
        printf("%d", root->ele);
    }
}

// function to print sum of all node element : 
static int sum = 0;
void print_sum (struct BTNode *root) {
    if (root != NULL) {
        print_sum (root->lchild);
        sum = sum + (root->ele);
        print_sum (root->rchild);
    }
}

int main () {
    int a[100], size;
    struct BTNode *root, *nn;
    root = NULL;

    printf("\nEnter the size : ");
    scanf("%d", &size);

    printf("Tree Created : ");

    printf("Enter the elements : ");
    for (int i = 0; i<size; i++) {
        printf("\nElement %d : ", i+1);
        scanf("%d", &a[i]);    
    }

    for (int i = 0; i<size; i++) {
        nn = (struct BTNode *) malloc (sizeof(struct BTNode));

        nn->ele = a[i];
        nn->lchild = NULL;
        nn->rchild = NULL;

        if (root == NULL) {
            root = nn;
        } 
        else {
            place_node (root, nn); 
        }
    }
    printf("\nAll elements inserted !!!");

    print_root(root);
    printf("\nPreorder Traversal : ");
    preorder_traversal(root);
    
    printf("\nInorder Traversal : ");
    inorder_traversal(root);

    printf("\nPostorder Traversal : ");
    postorder_traversal(root);

    printf("\nTotal Leaf Nodes are : ");
    print_leafNode(root);

    printf("\nParent with Two childs : ");
    print_two_child(root);

    printf("\nParent with only one child : ");
    print_only_oneChild(root);

    printf("\nOnly left childs : ");
    print_leftChild(root);

    printf("\nOnly right childs : ");
    print_rightChild(root);

    print_sum(root);
    printf("\nSum of all Node elements : %d", sum);
    
    return 0;
}
#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void display (struct Element *sparseMatrix, int nonZeros) {
    printf("\n");
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i < nonZeros; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
    printf("\n");
}

void main () {
    int rows, cols, nonZerosA, nonZerosB; 

    printf("\nEnter the order of matrix of both A & B : ");
    printf("\nRows : ");
    scanf("%d", &rows);
    printf("Columns : ");
    scanf("%d", &cols);

    int matA[rows][cols];
    int matB[rows][cols];

    // Matrix A : 
    printf("\nEnter How many Non zero elements in Matrix A : ");
    scanf("%d", &nonZerosA);

    struct Element sparseMatrixA[nonZerosA + 1];
  
    printf("\nEnter Non Zeros : ");
    for (int i = 0; i < nonZerosA; i++) {
        printf("\nElement %d -->", i + 1);
        printf("\nRow : ");
        scanf("%d", &sparseMatrixA[i].row);
        
        printf("Column : ");
        scanf("%d", &sparseMatrixA[i].col);

        printf("\nValue : ");
        scanf("%d", &sparseMatrixA[i].value);
    }

    // Matrix B : 
    printf("\nEnter How many Non zero elements in Matrix B : ");
    scanf("%d", &nonZerosB);

    struct Element sparseMatrixB[nonZerosB + 1];
  
    printf("\nEnter Non Zeros : ");
    for (int i = 0; i < nonZerosB; i++) {
        printf("\nElement %d -->", i + 1);
        printf("\nRow : ");
        scanf("%d", &sparseMatrixB[i].row);
        
        printf("Column : ");
        scanf("%d", &sparseMatrixB[i].col);

        printf("\nValue : ");
        scanf("%d", &sparseMatrixB[i].value);
    }

    printf("\nSparse Matrix A : ");
    display(sparseMatrixA, nonZerosA);

    printf("\nSparse Matrix B : ");
    display(sparseMatrixB, nonZerosB);


    //assign zeros :
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matA[i][j] = 0;
            matB[i][j] = 0;
        }
    }

    for (int i = 0; i < nonZerosA; i++) {
        matA[sparseMatrixA[i].row][sparseMatrixA[i].col] = sparseMatrixA[i].value;
    }

    for (int i = 0; i < nonZerosB; i++) {
        matB[sparseMatrixB[i].row][sparseMatrixB[i].col] = sparseMatrixB[i].value;
    }

    printf("\n");
    printf("\nMatrix A : \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\t%d", matA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nMatrix B : \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\t%d", matB[i][j]);
        }
        printf("\n");
    }
}
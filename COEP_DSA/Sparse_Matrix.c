#include <stdio.h>

int main()
{
    // rows cols value
    // 0    1       5
    // 1    2       6
    // 2    4       2

    int rows, cols, nonZeros;

    printf("\nEnter the order of matrix 1 : ");
    printf("\nRows : ");
    scanf("%d", &rows);
    printf("Columns : ");
    scanf("%d", &cols);

    // initialization : s
    int arr1[rows][cols];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1[i][j] = 0;
        }
    }

    printf("\nEnter how many non zero elements are there in matrix 2 : ");
    scanf("%d", &nonZeros);
    int row, col;

    for (int i = 0; i < nonZeros; i++)
    {
            printf("\nElement %d : ", i+1);
            printf("\nAt Row : ");
            scanf("%d", &row);
            printf("\nAt Column : ");
            scanf("%d", &col);
            printf("\nEnter value : ");
            scanf("%d", &arr1[row][col]);
            nonZeros;
    }

    printf("\nEnter the order of matrix 2 : ");
    printf("\nRows : ");
    scanf("%d", &rows);
    printf("Columns : ");
    scanf("%d", &cols);

    // initialization : s
    int arr2[rows][cols];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr2[i][j] = 0;
        }
    }

    printf("\nEnter how many non zero elements are there in Matrix 2: ");
    scanf("%d", &nonZeros);

    for (int i = 0; i < nonZeros; i++)
    {
            printf("\nElement %d : ", i+1);
            printf("\nAt Row : ");
            scanf("%d", &row);
            printf("\nAt Column : ");
            scanf("%d", &col);
            printf("\nEnter value : ");
            scanf("%d", &arr2[row][col]);
            nonZeros;
    }
 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("\nSum of Matrix 1 & 2 : \n");
    int sparseSum[3][3];
    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sparseSum[i][j] = arr1[i][j] + arr2[i][j];
            printf("\t%d", sparseSum[i][j]);
        }
        printf("\n");
    }

    int sparseTrans[rows][cols];
    printf("\nTranspose of matrix : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sparseTrans[i][j] = sparseSum[j][i];
            printf("\t%d", sparseTrans[i][j]);
        }
        printf("\n");
    }
}

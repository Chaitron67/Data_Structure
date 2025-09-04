#include <stdio.h>

void sparseAddition(int arr1[3][3], int arr2[3][3], int rows, int cols) {
    int sparseSum[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sparseSum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nAddition is : ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", sparseSum[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // rows cols value
    // 0    1       5
    // 1    2       6
    // 2    4       2

    int arr1[3][3] = {
        {0,0,1},
        {1,2,0},
        {0,-1,2},
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int arr2[3][3] = {
        {0,1,1},
        {1,0,0},
        {0,-1,2},
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    sparseAddition(arr1, arr2, 3, 3);
}

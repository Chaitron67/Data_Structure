#include <stdio.h>

typedef struct
{
    int rows;
    int cols;
    int values;
} Triplet;

void createSparseTriplet(Triplet arr[], int rows, int cols, int nonZeros)
{
    arr[0].rows = rows;
    arr[0].cols = cols;
    arr[0].values = nonZeros;

    for (int i = 1; i <= nonZeros; i++)
    {
        printf("\nNon Zero %d: ", i);
        printf("\nEnter in format (Row Col Value): ");
        scanf("%d %d %d", &arr[i].rows, &arr[i].cols, &arr[i].values);
    }
}

void sortTriplets(Triplet arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((arr[i].rows > arr[j].rows) ||
                (arr[i].rows == arr[j].rows && arr[i].cols > arr[j].cols))
            {
                Triplet temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printSparseTriplet(Triplet arr[])
{
    printf("\nSparse Matrix in Triplet Representation:\n");
    printf("\tRow\tCol\tValue\n");
    for (int i = 0; i <= arr[0].values; i++)
    {
        printf("\t%d\t%d\t%d\n", arr[i].rows, arr[i].cols, arr[i].values);
    }
}

void printSparseMatrix(Triplet arr[])
{
    printf("\nFull Sparse Matrix:\n");
    int k = 1;
    for (int i = 0; i < arr[0].rows; i++)
    {
        for (int j = 0; j < arr[0].cols; j++)
        {
            if (k <= arr[0].values && i == arr[k].rows && j == arr[k].cols)
            {
                printf("\t%d", arr[k].values);
                k++;
            }
            else
            {
                printf("\t0");
            }
        }
        printf("\n");
    }
}

void additionOfSparse(Triplet arr1[], Triplet arr2[], Triplet sumArr[])
{
    sumArr[0].rows = arr1[0].rows;
    sumArr[0].cols = arr1[0].cols;

    if (arr1[0].rows != arr2[0].rows || arr1[0].cols != arr2[0].cols)
    {
        printf("\nCan't perform Addition! Matrices must have same dimensions.\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= arr1[0].values && j <= arr2[0].values)
    {
        if (arr1[i].rows < arr2[j].rows ||
            (arr1[i].rows == arr2[j].rows && arr1[i].cols < arr2[j].cols))
        {
            sumArr[k++] = arr1[i++];
        }
        else if (arr2[j].rows < arr1[i].rows ||
                 (arr2[j].rows == arr1[i].rows && arr2[j].cols < arr1[i].cols))
        {
            sumArr[k++] = arr2[j++];
        }
        else
        {
            // Same position → add values
            sumArr[k].rows = arr1[i].rows;
            sumArr[k].cols = arr1[i].cols;
            sumArr[k].values = arr1[i].values + arr2[j].values;
            i++;
            j++;
            k++;
        }
    }

    while (i <= arr1[0].values)
    {
        sumArr[k++] = arr1[i++];
    }
    while (j <= arr2[0].values)
    {
        sumArr[k++] = arr2[j++];
    }

    sumArr[0].values = k - 1;
}

void sparseTranspose(Triplet arr[]) {
    int k = 0, temp;

    // Swap rows and cols for metadata too
    temp = arr[0].rows;
    arr[0].rows = arr[0].cols;
    arr[0].cols = temp;

    k = 1;
    while (k <= arr[0].values) {
        temp = arr[k].rows;
        arr[k].rows = arr[k].cols;
        arr[k].cols = temp;
        k++;
    }

    sortTriplets(arr, arr[0].values);
}


int main()
{
    int rows, cols, nonZeros;

    // Sparse Matrix A
    printf("\nEnter the order of Matrix A: ");
    printf("\nRows : ");
    scanf("%d", &rows);
    printf("Columns : ");
    scanf("%d", &cols);

    printf("\nEnter how many non zero elements in Matrix A: ");
    scanf("%d", &nonZeros);

    Triplet arr1[nonZeros + 1];
    createSparseTriplet(arr1, rows, cols, nonZeros);
    sortTriplets(arr1, nonZeros);

    printf("\nEnter the order of Matrix B: ");
    printf("\nRows : ");
    scanf("%d", &rows);
    printf("Columns : ");
    scanf("%d", &cols);

    printf("\nEnter how many non zero elements in Matrix B: ");
    scanf("%d", &nonZeros);

    Triplet arr2[nonZeros + 1];
    createSparseTriplet(arr2, rows, cols, nonZeros);
    sortTriplets(arr2, nonZeros);

    Triplet sumArr[arr1[0].values + arr2[0].values + 1];
    additionOfSparse(arr1, arr2, sumArr);

    printSparseTriplet(sumArr);
    printSparseMatrix(sumArr);

    sparseTranspose(sumArr);

    printf("\nTranspose is: \n");
    printSparseTriplet(sumArr);
    printSparseMatrix(sumArr);

    return 0;
}

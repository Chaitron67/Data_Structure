#include <stdio.h>

void removeDuplicates()
{
    int size;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);

    float arr[size];
    printf("\nEnter the %d elements: ", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }

    float uniqueArray[size];

    int flag = 0;
    int uniqueCount = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < uniqueCount; j++)
        {
            if (arr[i] == uniqueArray[j])
            {
                flag = 1;
            }
        }
        if (flag != 1)
        {
            uniqueArray[uniqueCount] = arr[i];
            uniqueCount++;
        }
        flag = 0;
    }

    printf("\nUnique Elements:\n");
    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%.2f\t", uniqueArray[i]);
    }
}

void main()
{
    removeDuplicates();
}
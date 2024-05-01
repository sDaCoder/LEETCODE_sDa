#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int *addElement(int *array, int n, int elem)
{
    int *newArray = (int *)malloc((n + 1) * sizeof(int));
    newArray[0] = elem;
    for (int i = 0; i < n; i++)
    {
        newArray[i + 1] = array[i];
    }
    free(array);
    return newArray;
}

int *addToArrayForm(int *num, int numSize, int k, int *returnSize)
{
    int n = k;

    int i = numSize - 1;
    while (i >= 0 || n > 0)
    {
        int sum = ((i >= 0) ? num[i] : 0) + (n % 10);
        n /= 10;

        if (i >= 0)
        {
            num[i] = sum % 10;
        }
        else
        {
            num = addElement(num, numSize, sum % 10);
            numSize++;
        }

        if (sum >= 10)
        {
            n++;
        }

        i--;
    }

    *returnSize = numSize;
    return num;
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    system("cls");
    int num[] = {1, 2, 6, 3, 0, 7, 1, 7, 1, 9, 7, 5, 6, 6, 4, 4, 0, 0, 6, 3};
    int k = 516, retSize;
    int size = sizeof(num) / sizeof(int);
    int *result = addToArrayForm(num, size, k, &retSize);
    printArr(result, retSize);
    free(result);
}

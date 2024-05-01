#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    *returnSize = temperaturesSize;
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int index, count;

    for (int i = 0; i < (temperaturesSize - 1); i++)
    {
        index = i;
        count = 0;
        for (int j = i+1; j < temperaturesSize; j++)
        {
            if (temperatures[j] > temperatures[index])
            {
                result[index] = (count + 1);
                break;
            }
            else count++;
        }
    }
    return result;
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
    int temperatures[] = {30,40,50,60};
    int size = sizeof(temperatures) / sizeof(int);
    int returnSize;

    // printArr(temperatures, size);
    int* result = dailyTemperatures(temperatures, size, &returnSize);
    printArr(result, returnSize);
    free(result);
}
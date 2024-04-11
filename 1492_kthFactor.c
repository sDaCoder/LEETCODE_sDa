#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int num_factors(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            count++;
        }
    }
    return count;
}

int* factor(int n)
{
    int* arr = (int*)malloc(num_factors(n)*sizeof(int));
    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            arr[index] = i;
            index++;
        }
    }
    return arr;
}

int kthFactor(int n, int k)
{
    int* arr = factor(n);
    if (k <= num_factors(n))
    {
        return arr[k - 1];
    }
    else return -1;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    system("cls");
    int n = 7, k = 2;
    // printArr(factor(n), num_factors(n));
    // printf("\n%d", factor(n)[k-1]);
    // printf("\n%d", num_factors(n));
    printf("%d", kthFactor(n ,k));
}
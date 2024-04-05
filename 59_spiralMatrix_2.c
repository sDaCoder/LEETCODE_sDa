#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    int a = 1, size = n * n;
    int top = 0, left = 0, bottom = (n - 1), right = (n - 1);

    while (a <= size)
    {
        for (int i = left; i <= right && a <= size; i++)
        {
            arr[top][i] = a;
            a++;
        }
        top++;

        for (int i = top; i <= bottom && a <= size; i++)
        {
            arr[i][right] = a;
            a++;
        }
        right--;

        for (int i = right; i >= left && a <= size; i--)
        {
            arr[bottom][i] = a;
            a++;
        }
        bottom--;

        for (int i = bottom; i >= top && a <= size; i--)
        {
            arr[i][left] = a;
            a++;
        }
        left++;
    }
    return arr;
}

void print2D(int **arr, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    system("cls");
    int n = 4;
    int size = n * n;
    int *ptr = &n;
    int **arr = generateMatrix(n, &(size), &(ptr));
    print2D(arr, n);
}
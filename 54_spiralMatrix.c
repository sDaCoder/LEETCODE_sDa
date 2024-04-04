#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *spiralOrder(int matrix[][4], int matrixSize, int *matrixColSize, int *returnSize)
{
    *returnSize = matrixSize*(*matrixColSize);
    int cols = *matrixColSize;
    int rows = matrixSize;
    int size = rows*cols;

    int *spiral = (int *)malloc(size * sizeof(int));
    int index = 0;

    int top = 0, left = 0, right = (cols - 1), bottom = (rows - 1);

    while (index < size)
    {
        for (int i = left; i <= right && index < size; i++)
        {
            spiral[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom && index < size; i++)
        {
            spiral[index++] = matrix[i][right];
        }
        right--;

        for (int i = right; i >= left && index < size; i--)
        {
            spiral[index++] = matrix[bottom][i];
        }
        bottom--;

        for (int i = bottom; i >= top && index < size; i--)
        {
            spiral[index++] = matrix[i][left];
        }
        left++;

    }
    return spiral;
}

void main()
{
    system("cls");
    // matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int cols = 4;
    int rows = 3;
    int size = rows*cols;
    int* result = spiralOrder(matrix, rows, &cols, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", result[i]);
    }
}
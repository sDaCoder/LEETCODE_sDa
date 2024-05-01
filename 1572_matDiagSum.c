#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int diagonalSum(int mat[][4], int matSize, int* matColSize) {
    int rows = matSize;
    int cols = *matColSize;
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i==j)
            {
                sum += mat[i][j];
            }
            else if ((i+j) == (matSize - 1))
            {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

void main(){
    system("cls");
    int matrix[][4] = {{1 ,1, 1, 1}, {1 ,1, 1, 1}, {1 ,1, 1, 1}, {1 ,1, 1, 1}};    
    int cols = 4;
    printf("%d", diagonalSum(matrix, 4, &cols));
}
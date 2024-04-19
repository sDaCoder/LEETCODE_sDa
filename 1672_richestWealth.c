#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int maximumWealth(int accounts[][3], int accountsSize, int* accountsColSize) {
    int wealth = 0;
    for (int i = 0; i < accountsSize; i++)
    {
        int wealth1 = 0;
        for (int j = 0; j < *accountsColSize; j++)
        {
            wealth1 += accounts[i][j];
            if (wealth1 > wealth)
            {
                wealth = wealth1;
            }
        }
    }
    return wealth;
}

void print2D(int arr[][3], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    system("cls");
    int accounts[][3] = {{1, 2, 3}, {3, 2, 1}};   
    int rows = 2, cols = 3;
    // print2D(accounts, rows, cols);
    printf("%d", maximumWealth(accounts, rows, &cols));
}
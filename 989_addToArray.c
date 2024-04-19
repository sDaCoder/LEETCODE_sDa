#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int digit(long int n)
{
    if (n>=0 && n<=9)
    {
        return 1;
    }
    else
    {
        return (1 + digit(n/10));
    }
    
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    // long int sum = 0;
    // for (int i = 0; i < numSize; i++)
    // {
    //     sum = sum*10 + num[i];
    // }
    // long int result = sum+k;
    // int digits = digit(result);
    // *returnSize = digits;

    // int* resultArr = (int*)malloc(digits*sizeof(int));
    // int rem;
    // for (int i = (digits - 1); i >= 0; i--)
    // {
    //     rem = result%10;
    //     resultArr[i] = rem;
    //     result /= 10;
    // }
    // return resultArr;
    int sum = 0, carry = 0;
    
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    // system("cls");
    int num[] = {0};
    int k = 10000;
    int size = sizeof(num)/sizeof(int);
    // printf("%d", addToArrayForm(num, size, k, &size));
    int* result = addToArrayForm(num, size, k, &size);
    printArr(result, size);
}
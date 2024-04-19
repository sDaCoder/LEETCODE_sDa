#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize*sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int index = i;
        for (int j = 0; j < numsSize; j++)
        {
            if ((nums[j] < nums[i])&&(i!=j))
            {
                count++;
            }
        }
        result[i] = count;
        count = 0;
    }
    return result;
}

void main(){
    system("cls");
    int arr[] = {7,7,7,7};
    int size = sizeof(arr)/sizeof(int);
    int* result = smallerNumbersThanCurrent(arr, size, &size);
    printArr(result, size);

}
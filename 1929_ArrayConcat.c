#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArr(int* arr, int size)
{
    printf("The elements of the array are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

//! Note: The returned array must be malloced, assume caller calls free().
int* getConcatenation(int* nums, int numsSize)
{
    int returnSize = 2 * numsSize;
    int* ans = (int*) calloc(returnSize, sizeof(int));
    for (int n = 0; n < 2; n++)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if (n == 0)
            {
                ans[i] = nums[i];
            }
            else ans[i + numsSize] = nums[i];
        }
    }
    return ans;   
}
    

void main(){
    system("cls");
    int nums[] = {1, 2, 1};
    int count = sizeof(nums)/sizeof(int);
    // printf("%d", count);
    // printArr(nums, count);
    int* ans = getConcatenation(nums, count);
    printArr(ans, 2*count);
}
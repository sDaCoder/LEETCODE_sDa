#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int* result = (int*)malloc(2*sizeof(int));
    for (int i = 0; i < numsSize - 1; i++)
    {
        int index = i;
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[index] + nums[j] == target)
            {
                result[0] = index;
                result[1] = j;
                return result;
            }
        }
    }
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
    int nums[] = {3,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 6, returnSize = 2;
    int* result = twoSum(nums, numsSize, target, &returnSize);
    printArr(result, returnSize);
}
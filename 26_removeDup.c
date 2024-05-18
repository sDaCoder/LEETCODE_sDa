#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int* del(int* arr, int* size, int index)
{
    if (index >= *(size))
    {
        return arr;
    }
    
    int* arr1 = (int*)calloc(*(size) - 1, sizeof(int));
    int j = 0;

    for (int i = 0; i < *(size); i++)
    {
        if (i == index)
        {
            continue;
        }
        else
        {
            arr1[j] = arr[i];
            j++;
        }
    }
    *(size) = *(size) - 1;
    free(arr);
    return arr1;
}

int removeDuplicates(int* nums, int numsSize) {
    int index, count = 0;
    
    for (int i = 0; i < numsSize-1; i++)
    {
        index = i;
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[index] == nums[j])
            {
                nums = del(nums, &numsSize, j);
                count++;
            }
            else break;
        }
    }
    return (numsSize - count);
}

int main(){
    system("cls");

    int arr[] = {1, 1, 2};
    int numsSize = sizeof(arr)/sizeof(int);

    int* nums = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = arr[i];
    }
    
    printf("%d\n", removeDuplicates(nums, numsSize));
    // printArr(nums, numsSize);
    free(nums);
    return 0;
}
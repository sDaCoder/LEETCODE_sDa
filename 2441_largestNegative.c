#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int findMaxK(int *nums, int numsSize)
{
    int index, result = -1;
    for (int i = 0; i < (numsSize-1); i++)
    {
        index = i;
        for (int j = i+1; j < numsSize; j++)
        {
            if ((index != j)&&(nums[index] == -(nums[j]))&&(result < abs(nums[index])))
            {
                result = abs(nums[index]);
            }
        }
    }
    return result;
}

void main()
{
    system("cls");
    int nums[] = {-1,10,6,7,-7,1};
    int numsSize = sizeof(nums) / sizeof(int);
    printf("%d", findMaxK(nums, numsSize));
}
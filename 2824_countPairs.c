#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int countPairs(int *nums, int numsSize, int target)
{
    int index, count = 0;
    for (int i = 0; i < (numsSize - 1); i++)
    {
        index = i;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] < target)
            {
                count++;
            }
        }
    }
    return count;
}

void main()
{
    system("cls");
    int nums[] = {-6, 2, 5, -2, -7, -1, 3};
    int target = -2;
    int size = sizeof(nums) / sizeof(int);
    printf("%d", countPairs(nums, size, target));
}
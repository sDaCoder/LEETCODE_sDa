#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

long long countFairPairs(int* nums, int numsSize, int lower, int upper){
    int count = 0;
    for (int i = 0; i < (numsSize - 1); i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if ((nums[i]+nums[j]<=upper)&&(nums[i]+nums[j]>=lower))
            {
                count++;
            }
        }
    }
    return count;
}

void main(){
    system("cls");
    int nums[] = {1,7,9,2,5};
    int lower = 11;
    int upper = 11;
    int size = sizeof(nums) / sizeof(int);
    printf("%ld", countFairPairs(nums, size, lower, upper));   
}
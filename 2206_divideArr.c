#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool divideArray(int* nums, int numsSize) {
    int arr[501] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
    }
    
    for (int j = 0; j <= 500; j++)
    {
        if(arr[j] % 2 != 0) return false;
    }
    return true;
    
}

int main(){
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf("%d\n", divideArray(nums, numsSize));
    return 0;
}
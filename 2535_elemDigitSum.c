#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int digits_sum(int n)
{
    int sum = 0, rem, num = n;
    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        sum += rem;
    }
    return sum;
}

int differenceOfSum(int* nums, int numsSize) {
    int elemSum = 0, digSum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        elemSum += nums[i];
        digSum += digits_sum(nums[i]);
    }
    return abs(elemSum - digSum);
}

void main(){
    system("cls");
    int nums[] = {1,15,6,3};
    int size = sizeof(nums)/sizeof(int);
    printf("%d", differenceOfSum(nums, size));   
}
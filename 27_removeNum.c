#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
        {
            count++;
        }
    }
    return (numsSize - count);
}

void main(){
    system("cls");
    int arr[] = {3,2,2,3};
    int size = sizeof(arr)/sizeof(int);
    int val = 3;
    printf("%d", removeElement(arr, size, val));   
}
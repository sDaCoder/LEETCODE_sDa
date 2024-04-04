#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int * runSum(int* arr, int size, int* returnSize)
{
    int sum = 0;
    int j = 0;
    int* array = (int*) calloc(size, sizeof(int));
    
    *returnSize = size;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        array[j] = sum;
        j++;
    }
    return array;
}

void main(){
    system("cls");
    
    int nums[] = {10, 20, 30, 40, 50};
    int sum[1000];

    for (int i = 0; i < 5; i++)
    {
        // printf("%d  ", nums[i]);
        sum[i] = runSum(nums, 5, sum)[i];
        printf("%d  ", sum[i]);
    }
    

}
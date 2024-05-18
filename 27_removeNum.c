#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int* del(int* arr, int* size, int index)
{
    int* res = (int*)calloc(*(size) - 1, sizeof(int));
    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (i != index)
        {
            res[j] = arr[i];
            j++;
        }
    }
    *(size) = *(size) - 1;
    free(arr);
    return res;
}

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    while (i < numsSize)
    {
        if (nums[i] == val)
        {
            nums = del(nums, &numsSize, i);
        }
        else i++;
    }
    return numsSize;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    system("cls");
    int* arr = (int*)malloc(4*sizeof(int));
    int size = 4;

    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 3;

    int val = 3;
    printArr(arr, size);
    // arr = del(arr, &size, 2);
    
    int rSize = removeElement(arr, size, val);
    printf("%d\n", sizeof(arr)/sizeof(int));   
    printf("%d\n", rSize);   
    printArr(arr, rSize);
    free(arr);
}
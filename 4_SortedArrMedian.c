#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int* merge(int* arr1, int size1, int* arr2, int size2)
{
    int index = 0;
    int* result = (int*)malloc(sizeof(int)*(size1 + size2));

    for (int i = 0; i < (size1); i++)
    {
        result[index] = arr1[i];
        index++;
    }
    
    for (int i = 0; i < size2; i++)
    {
        result[index] = arr2[i];
        index++;
    }
    return result;
    
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int* arr = merge(nums1, nums1Size, nums2, nums2Size);
    int size = (nums1Size + nums2Size);
    int mid = size/2;

    if (size%2 == 0)
    {
        return (arr[mid] + arr[mid-1])/2;
    }
    else
    {
        return arr[mid];
    }
    
    
}

void main()
{
    system("cls");
    int arr1[] = {1, 2};
    int size1 = sizeof(arr1)/sizeof(int);
    int arr2[] = {3, 4};
    int size2 = sizeof(arr2)/sizeof(int);
    // printArr(merge(arr1, size1, arr2, size2), size1 + size2);
    printf("%f", findMedianSortedArrays(arr1, size1, arr2, size2));
}
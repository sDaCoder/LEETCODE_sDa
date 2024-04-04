#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int hcf;
    int min = (a < b)? a : b;

    for (int i = 1; i <= min; i++)
    {
        if ((a%i == 0) && (b%i == 0))
        {
            hcf = i;
        }
    }
    return hcf;
}

int gcd_Euclid(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd_Euclid(b, a % b);
    }
}

void bubbSort_Adaptive(int arr[], int size)
{
    int temp;
    int isSorted = 0;

    for (int i = 0; i < size-1; i++)
    {
        isSorted = 1;

        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }

        if (isSorted == 1)
        {
            return;
        }
    }
}

int findGCD(int* nums, int numsSize){
    bubbSort_Adaptive(nums, numsSize);
    return gcd(nums[0], nums[numsSize-1]);
}

void main(){
    system("cls");
    int nums[] = {45,52,16,90,100};
    int numsSize = 5;
    // printf("%d\n", gcd(65, 26));
    printf("%d\n", findGCD(nums, numsSize));
}
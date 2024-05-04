#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void merge(int *arr, int start, int mid, int end)
{
    int *tArr = (int *)malloc((end - start + 1) * sizeof(int));
    int left = start, right = mid + 1, index = 0;
    while ((left <= mid) && (right <= end))
    {
        if (arr[left] <= arr[right])
        {
            tArr[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            tArr[index] = arr[right];
            index++;
            right++;
        }
    }
    while (left <= mid)
    {
        tArr[index] = arr[left];
        index++;
        left++;
    }

    while (right <= end)
    {
        tArr[index] = arr[right];
        index++;
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = tArr[i - start];
    }
    free(tArr);
}

void mSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mSort(arr, start, mid);
        mSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    int high = (peopleSize - 1), low = 0, rem, boats = 0;
    mSort(people, low, high);   

    while (low <= high)
    {
        rem = limit - people[high];
        high--;

        if (people[low] <= rem)
        {
            low++;
        }
        boats++;
    }
    return boats;    
}

void main()
{
    system("cls");
    int people[] = {3, 5, 3, 4};
    int peopleSize = sizeof(people) / sizeof(int);
    int limit = 5;
    printf("%d", numRescueBoats(people, peopleSize, limit));
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mini(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int maxArea(int* height, int heightSize)
{
    int max_area = 0, left = 0, right = heightSize - 1;
    while (left < right)
    {
        int h = mini(height[left], height[right]);
        int w = right - left;
        int area = h * w;
        if (area > max_area)
        {
            max_area = area;
        }
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_area;
}


void main()
{
    system("cls");
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(int);
    printf("%d", maxArea(height, heightSize));
}
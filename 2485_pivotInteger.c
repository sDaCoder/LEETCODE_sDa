#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int sum(int l, int h)
{
    int sum = 0;
    for(int i = l; i <= h; i++)
    {
        sum += i;
    }
    return sum;
}

int pivotInteger(int n) {
    for (int i = 1; i <= n; i++)
    {
        if (sum(1, i) == sum(i, n))
        {
            return i;
        }
    }
    return -1;
}

void main(){
    system("cls");
    int n = 4;
    printf("%d", pivotInteger(n));
}
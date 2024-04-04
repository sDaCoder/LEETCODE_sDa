#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int smallestEvenMultiple(int n)
{
    int max = (n > 2)?n:2;

    while (1)
    {
        if ((max%n == 0)&&(max%2 == 0))
        {
            return max;
        }
        max++;    
    }
}
     

void main(){
    system("cls");
    printf("%d\n", smallestEvenMultiple(6));
}
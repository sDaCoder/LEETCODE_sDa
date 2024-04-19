#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int countOperations(int num1, int num2) 
{
    int i;
    for (i = 0; (num1!=0 && num2!=0) ; i++)
    {
        if (num1>=num2)
        {
            num1 = num1 - num2;
        }
        else
        {
            num2 = num2 - num1;
        }
    }
    return i;
}

void main(){
    system("cls");
    int num1 = 10, num2 = 10;
    printf("%d", countOperations(num1, num2));
}
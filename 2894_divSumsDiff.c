#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int differenceOfSums(int n, int m) {
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i%m == 0)
        {
            num2 += i;
        }
        else
        {
            num1 += i;
        }
    }
    return (num1 - num2);
}

void main(){
    system("cls");
    int n = 10, m = 3;
    printf("%d", differenceOfSums(n, m));   
}
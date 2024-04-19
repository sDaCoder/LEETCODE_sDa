#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int sumOfMultiples(int n){
    int sum = 0;
    for (int i = 3; i <= n; i++)
    {
        if ((i%3==0)||(i%5==0)||(i%7==0))
        {
            sum += i;
        }
    }
    return sum;
}

void main(){
    system("cls");
    int n = 7;
    printf("%d", sumOfMultiples(n));
}
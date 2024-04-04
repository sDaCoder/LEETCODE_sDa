#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int digits(int n)
{
    int count = 0;
    int temp = n;
    while (temp > 0)
    {
        temp = temp/10;
        count++;
    }
    return count;
}

long int conCatenate(long int n)
{
    long int temp = n;
    temp = temp*(pow(10, digits(2*n))) + 2*n;
    temp = temp*(pow(10, digits(3*n))) + 3*n;
    return temp;
}

void main(){
    system("cls");
    long int x = 192;
    printf("The conCatenation of %ld is %ld", x, conCatenate(x));
}
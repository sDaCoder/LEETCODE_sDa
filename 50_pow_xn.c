#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double myPow(double x, int n) {
    long long p = n;
    if (p == 0)
    {
        return 1;
    }
    else if (p == 1)
    {
        return x;
    }
    else
    {
        return x*pow(x, p-1);
    }   
}

void main(){
    system("cls");
    double x = 1.00000;
    int n = -2147483648;
    printf("%lf", myPow(x, n));   
}
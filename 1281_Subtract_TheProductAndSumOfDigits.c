#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int product(int n)
{
    int pro = 1, rem;
    while(n > 0)
    {
        rem = n % 10;
        pro = pro * rem;
        n = n / 10;
    }
    return pro;
}

int sum(int n)
{
    int rem, sum = 0;
    while(n > 0)
    {
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }
    return sum;
}

int subtractProductAndSum(int n){
    return (product(n) - sum(n));
}

void main(){
    system("cls");
    int x = 4421;
    printf("The Product of Digits of %d is %d\n", x, product(x));
    printf("The Sum of Digits of %d is %d\n", x, sum(x));
    printf("The Required difference is %d\n", subtractProductAndSum(x));
}
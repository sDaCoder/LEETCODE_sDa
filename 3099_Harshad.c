#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int digits_sum(int n)
{
    int rem, sum = 0, num = n;
    while (num != 0)
    {
        rem = num%10;
        sum += rem;
        num = num/10;
    }
    return sum;
}

int sumOfTheDigitsOfHarshadNumber(int x)
{
    int d = digits_sum(x);
    if (x%d == 0)
    {
        return d;
    }
    else return -1;
}

void main()
{
    system("cls");
    int x = 18;
    // printf("%d", digits_sum(x));
    printf("%d", sumOfTheDigitsOfHarshadNumber(x));
}
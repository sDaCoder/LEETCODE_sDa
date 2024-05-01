#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void reverse(char* str)
{
    int start, end;
    char temp;
    for (start = 0, end = strlen(str) - 1; start < end; start++, end--)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

bool isStrictlyPalindromic(int n)
{
    if (n <= 5)
    {
        return 0;
    }
    long int D, base, rem, sum;
    int isPalindrome = 1;
    char str[1000], rev[1000];
    for (int i = 2; i < n - 2; i++)
    {
        D = n;
        sum = 0;
        base = 1;
        while (D != 0)
        {
            rem = D % i;
            D = D / i;
            sum += rem * base;
            base = base * 10;
        }
        sprintf(str, "%ld", sum);
        strcpy(rev, str);
        reverse(rev);
        if (strcmp(str, rev) != 0)
        {
            isPalindrome = 0;
            break;
        }
    }
    return isPalindrome;
}

void main()
{
    system("cls");
    int n = 4;
    // char str[100];
    // sprintf(str, "%d", n);
    printf("%d", isStrictlyPalindromic(n));
}
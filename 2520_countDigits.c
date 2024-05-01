#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int countDigits(int num) {
    int n = num, count = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        n = n / 10;
        if (num%rem == 0)
        {
            count++;
        }
    }
    return count;
}

void main(){
    system("cls");
    int n = 1248;
    printf("%d", countDigits(n));   
}
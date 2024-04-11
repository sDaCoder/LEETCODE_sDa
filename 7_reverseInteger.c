#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x){
    int num = x, rem;
    long rev = 0;
    
    while (num != 0)
    {
        rem = num%10;
        rev = rev*10 + rem;
        if ((rev >= INT_MAX) || (rev <= INT_MIN))
        {
            return 0;
        }
        num = num/10;
    }
    return (int)rev;
}

void main(){
    system("cls");
    int x = 123;
    printf("%d", reverse(x));
}
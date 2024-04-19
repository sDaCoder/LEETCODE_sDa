#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int numberOfSteps(int num) {
    int i;
    for (i = 0; num!=0; i++)
    {
        if (num%2 == 0)
        {
            num = num/2;
        }
        else
        {
            num--;
        }
    }
    return i;
}

void main(){
    system("cls");
    int n = 123;
    printf("%d", numberOfSteps(n));
}
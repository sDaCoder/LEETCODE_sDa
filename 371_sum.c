#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int getSum(int a, int b) {
    a += b;
    return a;
}

void main(){
    system("cls");
    int a = -999, b = 0;
    printf("%d", getSum(a, b));   
}
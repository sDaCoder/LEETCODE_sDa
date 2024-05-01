#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int tribonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    else {
        return (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
    }
}

int tribonacci_it(int n)
{
    int t0 = 0;
    int t1 = 1;
    int t2 = 1;
    int t_1;

    if (n == 0)
    {
        return t0;
    }
    
    for (int i = 1; i < n-1; i++)
    {
        t_1 = t0;
        t0 = t1;
        t1 = t2;
        t2 = t_1 + t0 + t1;
    }
    return t2;
}

void main(){
    system("cls");
    printf("%ld", tribonacci(36));  
    // 1132436852 
}
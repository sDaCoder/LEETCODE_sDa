#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check(int n)
{
    if (n == 0 || n == 1)
    {
        return -1; //! 1 is neither prime nor composite
    }
    
    else
    {
        int isPrime = 1;
        for (int i = 2; i*i <= n; i++)
        {
            // printf("Checking for %d\n", i);
            if (n%i == 0)
            {
                isPrime = 0;
            }
        }
        if (isPrime == 1)
        {
            return 1;
        }
        else return 0;
    }
}

void main(){
    system("cls");
    // printf("%d\n", check(4));
    for (int i = 1; i <= 200; i++)
    {
        
        for (int j = 0; j < 20; j++)
        {
            if (i == 10*j)
            {
                printf("\n");
            }
            
        }
        
        if (check(i) == 1)
        {
            printf("%d\t", i);
        }
        
    }
    
}
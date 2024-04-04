#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int digits(int n)
{
    int count = 0;
    int temp = n;
    while (temp > 0)
    {
        temp = temp/10;
        count++;
    }
    return count;
}

void traverse(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

int reverse(int n)
{    
    int rem, rev = 0, i = 0;
    while (n > 0)
    {
        rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
    }
    return rev;
}

int main(){
    system("cls");
    
    int x = 479;
    printf("Digits of %d is %d\n", x, digits(x));
    printf("The Reverse of %d is %d\n", x, reverse(x));
    // reverse(x);
    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == 10*j)
            {
                printf("\n");
            }
            
        }
        
        if (reverse(i) == i)
        {
            printf("%d\t", i);
        }
        
    }
    
    
    return 0;
}
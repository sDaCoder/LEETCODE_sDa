#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ch_size(char* operation)
{
    int chars = 0;
    for (int i = 0; operation[i] != '\0' ; i++)
    {
        chars++;
    }
    return chars;
}

int sign(char* operation)
{
    if (operation[0] == '+' || operation[1] == '+')
    {
        return 1;
    }
    else if (operation[0] == '-' || operation[1] == '-')
    {
        return -1;
    }
    else
    {
        // You can decide what to return here when neither '+' nor '-' is found.
        // For example, you might want to return 0.
        return 0;
    }
}

int finalValueAfterOperations(char ** operations, int operationsSize)
{
    int x = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        x = x + sign(operations[i]);
    }
    return x;
}

void main(){
    system("cls");
    // char *operations[] = {"++X", "++X", "X++"};
    // char *operations[] = {"X++", "++X", "--X", "X--"};
    char *operations[] = {"--X", "X++", "X++"};
    int operationsSize = 3;
    int x = 0;

    // for (int i = 0; i < operationsSize; i++)
    // {
        // printf("%d\n", sign(operations[i]));
        // printf("The size of %c is %d\n", *(operations[i]), ch_size(operations[i]));
    //     x = x + sign(operations[i]);
    // }
    printf("%d", finalValueAfterOperations(operations, operationsSize));
}
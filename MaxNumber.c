#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int size; 
    int top;
    int* arr;
}stack;

int isEmpty(stack* s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else return 0;
}

int isFull(stack* s)
{
    if (s->top == s->size-1)
    {
        return 1;
    }
    else return 0;
}

void push(stack* s, int val)
{
    if (isFull(s))
    {
        printf("Stack Overflow! Cant add %d to the stack\n\n", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        // printf("Pushing Element: %d\n", val);
    }
    
}

int pop(stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow! Cant remove any element from the stack\n");
        return 0;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
    
}

int stackTop(stack* s)
{
    return s->arr[s->top];
}

int stackBottom(stack* s)
{
    return s->arr[0];
}

void traverse(stack* s)
{
    printf("The elements of the stack are: \n");
    for (int i = 0; i < s->top+1; i++)
    {
        printf("%d  ", s->arr[i]);
    }
    
}

int Max(int* arr, int size)
{
    stack* s = (stack* ) malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (int*) calloc(s->size, sizeof(int));

    push(s, arr[0]);
    for (int i = 1; i < size; i++)
    {
        if (stackTop(s) < arr[i])
        {
            pop(s);
            push(s, arr[i]);
        }
        
    }
    return pop(s);
}

int main(){
    system("cls");
    int arr[] = {7, 7, 11, 9, 15, 2, 25};  
    // stack s;
    // s.top = -1;
    // s.size = 8;
    // s.arr = (int*) calloc(s.size, sizeof(int));  

    printf("The element having Maximum Value from the array is %d\n", Max(arr, 7));
    
    return 0;
}
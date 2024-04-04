#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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

void traverse(bool* arr, int size)
{
    printf("The elements of the array are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

bool* result(int* arr, int size, int extra)
{
    bool a;
    bool* array = (bool*) calloc(size, sizeof(bool)); 
    
    for (int i = 0; i < size; i++)
    {
        arr[i] += extra;
        if (Max(arr, size) == arr[i])
        {
            a = true;
        }
        else
        {
            a = false;
        } 
        
        arr[i] -= extra;
        array[i] = a;
    }
    return array;
}

void main()
{
    system("cls");
    int arr[] = {12, 2, 12};
    int n = 3;
    int extra = 10;
    printf("The maximum element of the array is: %d\n", Max(arr, n));

    
    traverse(result(arr, n , extra), n);
    // ! We will return 1 if after adding the extra, arr[i] becomes the maximum value of the array
}
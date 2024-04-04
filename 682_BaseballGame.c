#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

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
        // printf("Stack Underflow! Cant remove any element from the stack\n");
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

int is_int(char* str)
{
    if (str[0] == '+' || str[0] == 'C' || str[0] == 'D')
    {
        return 0;
    }
    else return 1;
}

int stack_sum(stack* s)
{
    int elements = s->top+1;
    int sum = 0;
    for (int i = 0; i < elements; i++)
    {
        sum = sum + s->arr[i];
    }
    return sum;
}

int calPoints(char** operations, int operationsSize){
    stack* s = (stack* ) malloc(sizeof(stack));
    s->top = -1;
    s->size = operationsSize;
    s->arr = (int*) calloc(s->size, sizeof(int));
    
    for (int i = 0; i < operationsSize; i++)
    {
        if (is_int(operations[i]))
        {
            push(s, atoi(operations[i]));
        }
        else if (strcmp(operations[i], "D") == 0)
        {
            push(s, 2*stackTop(s));
        }
        else if(strcmp(operations[i], "+") == 0)
        {
            int prev_sum = stackTop(s) + s->arr[s->top - 1];
            push(s, prev_sum);
        }
        else if(strcmp(operations[i], "C") == 0)
        {
            pop(s);
        }
        
    }
    traverse(s);
    return stack_sum(s);
}
 
void main(){
    system("cls");
    int num;
    char* ops[] = {"5","2","C","D","+"};
    // char* ops[] = {"5","-2","4","C","D","9","+","+"};
    // char* ops[] = {"1", "C"};
    int count = sizeof(ops)/sizeof(char*);
    
    printf("\nThe sum of the elements of the array is: %d", calPoints(ops, count));
}
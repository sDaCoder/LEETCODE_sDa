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

int words(char* sentence)
{
    int spaces = 0;
    for (int i = 0; sentence[i]!='\0' ; i++)
    {
        if (sentence[i] == ' ')
        {
            spaces++;
        }
    }
    return (spaces+1);
}

int mostWordsFound(char** sentences, int sentencesSize)
{
    stack* s = (stack* ) malloc(sizeof(stack));
    s->top = -1;
    s->size = sentencesSize;
    s->arr = (int*) calloc(s->size, sizeof(int));

    push(s, words(sentences[0]));
    for (int i = 1; i < sentencesSize; i++)
    {
        if (stackTop(s) < words(sentences[i]))
        {
            pop(s);
            push(s, words(sentences[i]));
        }
    }
    return pop(s);
}

void main(){
    system("cls");
    char* sentences[] = {"Alice and Bob love leetcode", "I think so too and the fact is evident", "This is great thanks very much", "I am the most efficient programmer of the World after I got a training session from our Favourite Harry Bhai", "The best Physics teacher of India is Alakh Pandey who brought the dreams of millions of the engineering aspirants of India into reality"};

    for (int i = 0; i < 5; i++)
    {
        printf("The sentence '%s' has %d words.\n\n", sentences[i], words(sentences[i]));
    }

    printf("The maximum number of words from the given sentences is %d\n", mostWordsFound(sentences, 5));
    
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack* next;
}st;

int isEmpty(st** s)
{
    if (*s == NULL)
    {
        return 1;
    }
    else return 0;
}

int isFull(st** s)
{
    st* ptr = (st*) malloc(sizeof(st));
    if (ptr == NULL)
    {
        return 1;
    }
    else return 0;
}

st* push(st** top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow! Cant add any new element into the array\n\n");
    }
    st* ptr = (st*) malloc(sizeof(st));
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
    return *top;
}

int pop(st** top)
{
    int x = 0;
    if(isEmpty(top))
    {
        printf("Stack Underflow! Cant pop any element from the stack\n\n");
    }
    else
    {
        st* s = *top;
        *top = (*top)->next;
        x = s->data;
        free(s);
    }
    return x;
}

int stackTop(st** top)
{
    return (*top)->data;
}

int words(char sentence[])
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

int mostWordsFound(char* sentences[], int sentencesSize)
{
    st* top = NULL;

    top = push(&top, words(sentences[0]));
    for (int i = 1; i < sentencesSize; i++)
    {
        if (stackTop(&top) < words(sentences[i]))
        {
            pop(&top);
            top = push(&top, words(sentences[i]));
        }
    }
    return pop(&top);   
    
}

int main(){
    system("cls");
    char* sentences[] = {"Alice and Bob love leetcode", "I think so too and the fact is evident", "This is great thanks very much", "I am the most efficient programmer of the World after I got a training session from our Favourite Harry Bhai", "The best Physics teacher of India is Alakh Pandey who brought the dreams of millions of the engineering aspirants of India into reality"};

    for (int i = 0; i < 5; i++)
    {
        printf("The sentence '%s' has %d words.\n\n", sentences[i], words(sentences[i]));
    }

    printf("The maximum number of words from the given sentences is %d\n", mostWordsFound(sentences, 5));
    
    return 0;
}
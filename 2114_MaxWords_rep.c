#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
    int index = 0;
    for (int i = 1; i < sentencesSize; i++)
    {
        if (words(sentences[i]) > words(sentences[index]))
        {
            index = i;
        }
    }
    return words(sentences[index]);
}

void main(){
    system("cls");
    char* sentences[] = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    printf("%d", mostWordsFound(sentences, 5));    
}
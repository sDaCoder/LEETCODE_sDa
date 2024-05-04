#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int returnIndex(char* word, char ch)
{
    int i = 0;
    for (i = 0; (word[i]!='\0'); i++)
    {
        if(word[i]==ch)
        {
            return (i);
        }
    }
    return -1;
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reversePrefix(char* word, char ch) {
    int low = 0, high = returnIndex(word, ch);

    while (low < high)
    {
        swap(&(word[low]), &(word[high]));
        low++;
        high--;        
    }
    return word;
}

void main(){
    system("cls");
    char word[] = "abcdefd";
    char ch = 'd';
    printf("%d", returnIndex(word, ch));
    // printf("%s", reversePrefix(word, ch));
}
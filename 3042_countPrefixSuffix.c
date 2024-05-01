#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int isPrefixAndSuffix(char* str1, char* str2)
{
    int low = 0;
    int high = (strlen(str1)>strlen(str2))?strlen(str1):strlen(str2);
    for(;low < high; low++, high--)
    {
        
    }
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    
}

void main(){
    system("cls");
    char* words[] = {"a","aba","ababa","aa"};
    int size = 4;
    printf("%d", countPrefixSuffixPairs(words, size));
}
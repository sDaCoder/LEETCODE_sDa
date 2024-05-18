#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int findMax(int* arr, int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[index])
        {
            index = i;
        }
    }
    return index;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    char** rank = (char**)malloc(scoreSize * sizeof(char*));

    int i = 0, maxInd;

    while (i < scoreSize)
    {
        maxInd = findMax(score, scoreSize);
        score[maxInd] = -1;

        if (i == 0)
        {
            rank[maxInd] = strdup("Gold Medal");
            // strcpy(rank[maxInd], "Gold Medal");
        }

        else if (i == 1)
        {
            rank[maxInd] = strdup("Silver Medal");
        }

        else if (i == 2)
        {
            rank[maxInd] = strdup("Bronze Medal");
        }

        else
        {
            rank[maxInd] = (char*)malloc(20 * sizeof(char)); // allocate memory
            sprintf(rank[maxInd], "%d", i+1);
        }
        i++;        
    }
    return rank;
    // return rank;
}

void main(){
    system("cls");
    int score[] = {10,3,8,9,4};
    int scoreSize = sizeof(score)/sizeof(int);
    int returnSize;
    char** result = findRelativeRanks(score, scoreSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        puts(result[i]);
    }
    
}
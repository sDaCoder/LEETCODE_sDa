#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int scoreOfString(char* s) {
    int score = 0;
    for (int i = 0; i < strlen(s) - 1; i++)
    {
        score += abs((int)(s[i]) - (int)(s[i+1]));
    }
    return score;
}

void main(){
    system("cls");
    char* s = "zaz";   
    printf("%d", scoreOfString(s));
}
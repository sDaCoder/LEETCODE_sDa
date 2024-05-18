#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

char* toLowerCase(char* s) {
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (int)s[i] + 32;
        }
    }
    return s;
}

void main(){
    system("cls");
    char s[] = "LOVELY";
    printf("%s", toLowerCase(s));    
}
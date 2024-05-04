#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int compareVersion(char* version1, char* version2) {
    
    char* rev1;
    char* rev2;
    char *saveptr1, *saveptr2;
    int x, y;

    rev1 = strtok_r(version1, ".", &saveptr1);
    rev2 = strtok_r(version2, ".", &saveptr2);

    while ((rev1 != NULL)||(rev2 != NULL)) {

        x = (rev1 != NULL)? atoi(rev1) : 0;
        y = (rev2 != NULL)? atoi(rev2) : 0;

        if (x > y)
        {
            return 1;
        }
        else if (x < y)
        {
            return -1;
        }

        rev1 = strtok_r(NULL, ".", &saveptr1);   
        rev2 = strtok_r(NULL, ".", &saveptr2);
    }
    return 0;
}

void main(){
    system("cls");

    char v1[] = "0.1";  
    char v2[] = "1.1";
    
    
    printf("%d", compareVersion(v1, v2));
    
}
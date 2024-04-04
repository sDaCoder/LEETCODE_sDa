#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArr(int* arr, int size)
{
    printf("The elements of the array is: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int* str_to_int_arr(char** arr, int size)
{
    int* int_arr = (int*) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int_arr[i] = atoi(arr[i]);
    }
    return (int_arr);
}

int atMostNGivenDigitSet(char ** digits, int digitsSize, int n)
{

}

void main(){
    system("cls");
    // printf("Hello world\n");
    char* digits[] = {"1", "3", "5", "7"};
    int n = 100;
    int size = sizeof(digits)/sizeof(char*);
    int* new_digits = str_to_int_arr(digits, size);
    printArr(new_digits, size);
    printf("%d bytes\n", sizeof(new_digits[1]));
}
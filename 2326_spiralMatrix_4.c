#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void traverse(struct ListNode *head)
{
    // struct ListNode *ptr = head;
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;    
    }   
}

void append(int data, struct ListNode **head)
{
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = data;
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct ListNode* p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}

int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize, int **returnColumnSizes)
{
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int **arr = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        // Initialize all elements to -1
        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;
        }
    }

    int size = m * n;
    int top = 0, left = 0, bottom = m - 1, right = n - 1;
    struct ListNode *ptr = head;
    int count = 0; // Counter for the number of elements filled in

    while (ptr != NULL && count < size) {
        // Fill the top row
        for (int i = left; ptr != NULL && i <= right; i++) {
            arr[top][i] = ptr->val;
            ptr = ptr->next;
            count++;
        }
        top++;

        // Fill the right column
        for (int i = top; ptr != NULL && i <= bottom; i++) {
            arr[i][right] = ptr->val;
            ptr = ptr->next;
            count++;
        }
        right--;

        // Fill the bottom row
        for (int i = right; ptr != NULL && i >= left; i--) {
            arr[bottom][i] = ptr->val;
            ptr = ptr->next;
            count++;
        }
        bottom--;

        // Fill the left column
        for (int i = bottom; ptr != NULL && i >= top; i--) {
            arr[i][left] = ptr->val;
            ptr = ptr->next;
            count++;
        }
        left++;
    }

    return arr;
}

void print2D(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    system("cls");
    struct ListNode *head = NULL;
    int datas[] = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    int size = sizeof(datas)/sizeof(int);

    for (int i = 0; i < size; i++)
    {
        append(datas[i], &head);
    }
    // traverse(head);
    int m = 3, n = 5;
    int size_mat = m*n;
    int* ptr = &n;
    int** arr = spiralMatrix(m, n, head, &size_mat, &ptr);
    print2D(arr, m, n);
}
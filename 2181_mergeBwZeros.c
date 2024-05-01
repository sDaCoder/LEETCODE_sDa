#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void traverse(struct ListNode *head)
{
    struct ListNode *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void append(int data, struct ListNode **head, struct ListNode **tail)
{
    struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->val = data;
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
    }
    else
    {
        (*tail)->next = ptr;
        *tail = ptr;
    }
}

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* ptr = head;
    int sum = 0;

    while (ptr->next != NULL)
    {
        sum += ptr->val;
        ptr = ptr->next;
        if (ptr->val == 0)
        {
            append(sum, &result, &tail);
            sum = 0;
        }
    }
    return result;
}

void main()
{
    system("cls");
    int arr[] = {0,1,0,3,0,2,2,0};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head, &tail);
    }
    traverse(mergeNodes(head));
}
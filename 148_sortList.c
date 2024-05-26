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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* i;
    struct ListNode* index;
    struct ListNode* j;

    for(i = head; i->next != NULL; i = i->next)
    {
        index = i;
        for(j = i->next; j != NULL; j = j->next)
        {
            if (index->val > j->val)
            {
                index = j;
            }
        }
        swap(&(index->val), &(i->val));
    }
    return head;
}

void main(){
    system("cls");
    int arr[] = {4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head, &tail);
    }    
    traverse(sortList(head));
}
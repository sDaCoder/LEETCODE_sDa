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
    struct ListNode* i = head;
    struct ListNode* index;
    struct ListNode* j = head->next;

    while (i->next != NULL)
    {
        index = i;
        while (j != NULL)
        {
            if (index->val > j->val)
            {
                index = j;
            }
            j = j->next;
        }
        swap(&(index->val), &(i->val));
        i = i->next;
    }
    return head;
}

void main(){
    system("cls");
    int arr[] = {4, 2, 1, 3};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head, &tail);
    }    
    traverse(sortList(head));
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void traverse(struct ListNode* head)
{
    struct ListNode* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;    
    }
}

void append(int data, struct ListNode** head)
{
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = data;
    ptr->next = NULL;

    if(*head == NULL)
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

void main(){
    system("cls");
    struct ListNode* head = NULL;
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head);
    }
    traverse(head);
}
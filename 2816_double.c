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

struct ListNode* doubleIt(struct ListNode* head){
    
    if (head == NULL)
    {
        return head;
    }
    
    struct ListNode *h1 = NULL, *t1 = NULL;
    if (head->next == NULL)
    {
        int x = (head->val)*2;
        if (x > 9)
        {
            append(x/10, &h1, &t1);
            append(x%10, &h1, &t1);
            return h1;
        }
        else
        {
            head->val = x;
            return head;
        }
    }
    
    
    struct ListNode *curr = head, *next_node;
    int a, ca = 0, b, cb = 0;

    while(curr->next != NULL)
    {
        next_node = curr->next;
        a = (curr->val)*2;
        ca = a/10;
        a = a%10;
        
        b = (next_node->val)*2;
        cb = b/10;
        b = b%10;
        
        if (curr == head && ca > 0)
        {
            append(ca, &h1, &t1);
            append((a+cb), &h1, &t1);
        }
        
        else
        {
            append((a+cb), &h1, &t1);
        }
        curr = curr->next;
    }
    append(b, &h1, &t1);
    return h1;
}

void main(){
    system("cls");

    int arr[] = {0};
    int size = sizeof(arr) / sizeof(int);
    
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head, &tail);
    }

    traverse(doubleIt(head));
    
}
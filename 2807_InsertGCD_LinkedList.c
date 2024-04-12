#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

int GCD(int a, int b)
{
    int gcd;
    if (a < b)
    {
        for (int i = 1; i <= b; i++)
        {
            if ((a%i == 0) && (b%i == 0))
            {
                gcd = i;
            }
            
        }
        return gcd;
    }
    else
    {
        for (int i = 1; i <= a; i++)
        {
            if ((a%i == 0) && (b%i == 0))
            {
                gcd = i;
            }
            
        }
        return gcd;
    }
    
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head)
{
    struct ListNode* result = NULL;
    struct ListNode* ptr = head;

    while (ptr->next != NULL)
    {
        int a = ptr->val;
        int b = (ptr->next)->val;
        int gcd = GCD(a, b);
        append(a, &result);
        append(gcd, &result);
        // append(b, &result);
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        append(ptr->val, &result);
    }
    return result;
}

void main()
{
    system("cls");
    int arr[] = {18, 6, 10, 3};
    int size = sizeof(arr)/sizeof(int);

    struct ListNode* head = NULL;

    for (int i = 0; i < size; i++)
    {
        append(arr[i], &head);
    }
    struct ListNode* result = insertGreatestCommonDivisors(head);
    traverse(result);
    // printf("%d", GCD(32, 64));
}
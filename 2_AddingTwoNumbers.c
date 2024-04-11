#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

void append(int data, struct ListNode **head)
{
    struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->val = data;
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct ListNode *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}

// long int structToNum(struct ListNode *head)
// {
//     long int num = 0, sum = 0, power = 0;
//     struct ListNode *ptr = head;
//     while (ptr != NULL)
//     {
//         num = ptr->val * ((pow(10, power)));
//         power++;
//         ptr = ptr->next;
//         sum += num;
//     }
//     return sum;
// }

// struct ListNode *numToStruct(long int n)
// {
//     int num = n, rem;
//     struct ListNode *head = NULL;
//     if (n == 0)
//     {
//         append(0, &head);
//     }
//     else
//     {
//         while (num != 0)
//         {
//             rem = num % 10;
//             append(rem, &head);
//             num = num / 10;
//         }
//     }
//     return head;
// }

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int carry = 0, sum = 0;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* result = NULL;
    while (p!=NULL || q!=NULL)
    {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;

        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;

        sum = x + y + carry;
        carry = sum/10;
        append(sum%10, &result);

    }
    if (carry > 0)
    {
        append(carry, &result);
    }
    return result;
}

void main()
{
    system("cls");
    int arr1[] = {9};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int size2 = sizeof(arr2) / sizeof(int);

    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;

    for (int i = 0; i < size1; i++)
    {
        append(arr1[i], &l1);
    }
    // traverse(l1);

    for (int i = 0; i < size2; i++)
    {
        append(arr2[i], &l2);
    }
    // traverse(l2);

    long int n1 = structToNum(l1);
    long int n2 = structToNum(l2);
    // printf("%ld\n", n1);
    // printf("%ld\n", n2);
    traverse(addTwoNumbers(l1, l2));
}
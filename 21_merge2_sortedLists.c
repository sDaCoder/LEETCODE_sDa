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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* ptr1 = list1;
    struct ListNode* ptr2 = list2;
    struct ListNode* result = NULL;
    
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->val <= ptr2->val)
        {
            append(ptr1->val, &result);
            ptr1 = ptr1->next;
        }
        else
        {
            append(ptr2->val, &result);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        append(ptr1->val, &result);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        append(ptr2->val, &result);
        ptr2 = ptr2->next;
    }
    return result;
}

void main(){
    system("cls");

    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;
    
    int arr1[] = {1,2,4,5};
    int size1 = sizeof(arr1)/sizeof(int);

    int arr2[] = {1,3,4};
    int size2 = sizeof(arr2)/sizeof(int);

    for (int i = 0; i < size1; i++)
    {
        append(arr1[i], &head1);
    }
    // traverse(head1);

    for (int i = 0; i < size2; i++)
    {
        append(arr2[i], &head2);
    }
    // traverse(head2);
    traverse(mergeTwoLists(head1, head2));
}
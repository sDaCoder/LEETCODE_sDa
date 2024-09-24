#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <stdlib.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    void printList(ListNode *head)
    {
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void insertNode(ListNode **head, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (*head == nullptr)
        {
            *head = newNode;
            return;
        }

        ListNode *ptr = *head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;    
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head){
        // ListNode *newHead = nullptr, *ptr = head;
        // while (ptr != nullptr)
        // {
        //     insertNode(&newHead, ptr->val);
        //     ptr = ptr->next;
        // }
        // newHead = reverse(newHead);

        // bool flag = true;
        // ListNode *ptr1 = head, *ptr2 = newHead;
        // while (ptr1 != nullptr && ptr2 != nullptr)
        // {
        //     if(ptr1->val != ptr2->val)
        //     {
        //         return false;
        //     }
        //     ptr1 = ptr1->next;
        //     ptr2 = ptr2->next;
        // }
        // return true;

        if(head == nullptr || head->next == nullptr) return true;

        ListNode *slow = head, *fast = head;
        while (fast != nullptr || fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *second = reverse(slow), *first = head;
        while (second != nullptr)
        {
            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;
        }
        return true;
    }
};

int main()
{
    system("cls");

    Solution S;
    ListNode *head = nullptr;
    vector<int> nums = {1, 2, 2, 1};

    for (int i = 0; i < nums.size(); i++)
    {
        S.insertNode(&head, nums[i]);
    }
    S.printList(head);
    // ListNode *newHead = S.reverse(head);
    // S.printList(newHead);
    cout << S.isPalindrome(head) << endl;
    return 0;
}
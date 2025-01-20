#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

public:
    void append(int val, ListNode **head, ListNode **tail)
    {
        ListNode *ptr = new ListNode(val);

        if (*head == nullptr)
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

    ListNode *removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *res = new ListNode(INT_MIN, head);
        ListNode *dummy = res;

        for (uint i = 0; i < n; i++)
        {
            head = head->next;
        }
        
        while (head != nullptr)
        {
            head = head->next;
            dummy = dummy->next;
        }
        
        ListNode *ptr = dummy->next;
        dummy->next = dummy->next->next;
        ptr->next = nullptr;
        delete(ptr);

        return res->next;
    }
};

void printList(ListNode *head)
{
    if(!head) return;
    if (head->next == nullptr)
    {
        cout << head->val << endl;
        return;
    }
    
    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    vector<int> nodes = {1 ,2};
    int n = 2;

    Solution S;
    ListNode *h = nullptr;
    ListNode *t = nullptr;

    for(auto i : nodes) S.append(i, &h, &t);

    ListNode *newList = S.removeNthFromEnd(h, n);
    printList(newList);
    // cout << newList->val << endl;
    // cout << S.removeNthFromEnd(h, n) << endl;

    return 0;
}
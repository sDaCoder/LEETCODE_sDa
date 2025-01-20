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

    ListNode *deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;

        ListNode *ptr = head, *ptr2 = head->next;

        while (ptr2->next && ptr2->next->next)
        {
            ptr = ptr->next;
            ptr2 = ptr2->next->next;
        }
        
        ptr->next = ptr->next->next;
        return head;
    }
};

void printList(ListNode *head)
{
    if(!head) return;
    if (!head->next)
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
    vector<int> nodes = {2, 1};

    Solution S;
    ListNode *h = nullptr;
    ListNode *t = nullptr;

    for(auto i : nodes) S.append(i, &h, &t);

    // cout << S.deleteMiddle(h) << endl;
    printList(S.deleteMiddle(h));

    return 0;
}
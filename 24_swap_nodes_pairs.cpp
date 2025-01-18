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

    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *h = nullptr, *t = nullptr, *ptr = head;

        while (ptr != nullptr)
        {
            ptr->next ? append(ptr->next->val, &h, &t) : append(ptr->val, &h, &t);
            if(ptr->next) append(ptr->val, &h, &t);
            ptr->next == nullptr ? ptr = nullptr : ptr = ptr->next->next;
        }
        return h;
    }
};

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

int main(){
    // cout<<"It's SDA"<<endl;
    vector<int> nodes = {1,2,3};

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    Solution S;

    for(auto i : nodes) S.append(i, &head, &tail);
    printList(head);
    ListNode *newList = S.swapPairs(head);
    printList(newList);

    return 0;
}

// clang++ -std=c++11
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

    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *ptr = head;
        vector<int> elements;

        while (ptr != nullptr)
        {
            elements.push_back(ptr->val);
            ptr = ptr->next;    
        }
        
        swap(elements[k - 1], elements[elements.size() - k]);

        ListNode *h = nullptr, *t = nullptr;
        for(auto i : elements) append(i, &h, &t);
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

    vector<int> nodes = {7,9,6,6,7,8,3,0,9,5};
    int k = 5;

    Solution S;
    ListNode *h = nullptr;
    ListNode *t = nullptr;

    for(auto i : nodes) S.append(i, &h, &t);

    ListNode *newList = S.swapNodes(h, k);
    printList(newList);

    return 0;
}
// clang++ -std=c++11
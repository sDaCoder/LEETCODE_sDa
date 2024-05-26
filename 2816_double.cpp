#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
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

        ListNode* doubleIt(ListNode* head) {
            
            if(head == nullptr) return head;

            ListNode *h1 = nullptr, *t1 = nullptr;
            if(head->next == nullptr)
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

            ListNode *curr = head, *next_node;
            int a, ca = 0, b, cb = 0;

            while(curr->next != nullptr)
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

int main(){
    system("cls");
    vector<int> arr = {9, 9, 9};
    Solution S;
    ListNode *head = nullptr, *tail = nullptr;
    for(auto i: arr) S.append(i, &head, &tail);
    traverse(S.doubleIt(head));
    return 0;
}
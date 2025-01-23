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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Creation{
public:
    TreeNode *buildTree(vector<int> &values)
    {
        if (values.size() == 0 || values[0] == -1)
            return nullptr;

        TreeNode *root = new TreeNode(values[0]);
        queue<TreeNode *> Q;
        Q.push(root);
        int i = 1;

        while (i < values.size() && !Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();

            if (i < values.size() && values[i] != -1)
            {
                temp->left = new TreeNode(values[i]);
                Q.push(temp->left);
            }
            i++;

            if (i < values.size() && values[i] != -1)
            {
                temp->right = new TreeNode(values[i]);
                Q.push(temp->right);
            }
            i++;
        }
        return root;
    }

    void preOrder(TreeNode *root)
    {
        if (!root) return;

        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void preOrder(Node *root)
    {
        if(!root) return;

        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
};


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution : public Creation
{
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int qsize = Q.size();

            for (int i = 0; i < qsize; i++)
            {
                Node *temp = Q.front();
                Q.pop();

                if(Q.empty())
                {
                    temp->next = nullptr;
                }
                else temp->next = Q.front();

                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
        }
        return root;
    }
};


int main(){
    vector<int> nodes = {1,2,3,4,5,6,7};
    Solution S;

    TreeNode *root = S.buildTree(nodes);
    S.preOrder(root);
    cout << endl;

    
    return 0;
}
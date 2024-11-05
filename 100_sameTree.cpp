#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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

TreeNode *buildTree(vector<int> &nodes)
{
    if (nodes.size() == 0 || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> Q;
    Q.push(root);
    int i = 1;

    while (i < nodes.size() && !Q.empty())
    {
        TreeNode *temp = Q.front();
        Q.pop();

        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->left = new TreeNode(nodes[i]);
            Q.push(temp->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->right = new TreeNode(nodes[i]);
            Q.push(temp->right);
        }
        i++;
    }
    return root;
}

void preOrder(TreeNode *root)
{
    if(!root) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        if(p->val != q->val) return false;

        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main()
{
    system("cls");
    vector<int> n1 = {1, 2};
    vector<int> n2 = {1, -1, 2};

    TreeNode *r1 = buildTree(n1);
    TreeNode *r2 = buildTree(n2);

    preOrder(r1);
    cout << endl;

    preOrder(r2);
    cout << endl;

    Solution S;
    cout << S.isSameTree(r1, r2) << endl;

    return 0;
}
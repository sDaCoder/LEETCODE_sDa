// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
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

TreeNode *buildTree(const vector<int> &values)
{
    if (values.empty() || values[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        // Insert left child
        if (i < values.size() && values[i] != -1)
        {
            // Check if it's not null
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++; // Move to the next element in the array

        // Insert right child
        if (i < values.size() && values[i] != -1)
        {
            // Check if it's not null
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++; // Move to the next element in the array
    }
    return root;
}

class Solution
{
public:
    void preOrder(TreeNode *root, vector<int> &ans)
    {
        if (!root) return;

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};

int main()
{
    system("cls");

    TreeNode *root = nullptr;

    vector<int> nodes = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    root = buildTree(nodes);

    Solution S;
    vector<int> pre = S.preorderTraversal(root);
    for (int i = 0; i < pre.size(); i++) cout << pre[i] << " ";

    cout << endl;

    return 0;
}
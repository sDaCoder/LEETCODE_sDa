// https://leetcode.com/problems/root-equals-sum-of-children/description/
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<stdlib.h>
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

TreeNode *buildTree(vector<int> &values)
{
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    bool checkTree(TreeNode* root) 
    {
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        return (root->val == left->val + right->val);      
    }
};

int main(){
    system("cls");
    
    TreeNode *root = nullptr;
    vector<int> nodes = {5, 3, 1};

    root = buildTree(nodes);
    
    Solution S;
    cout << S.checkTree(root);
    
    return 0;
}
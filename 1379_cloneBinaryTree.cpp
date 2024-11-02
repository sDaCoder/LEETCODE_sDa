// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

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

TreeNode *buildTree(vector<int>& nodes)
{
    if(nodes.size() == 0 || nodes[0] == -1) return nullptr;

    TreeNode *newNode = new TreeNode(nodes[0]);
    queue<TreeNode*> Q;
    Q.push(newNode);

    int i = 0;

    while(!Q.empty() && i < nodes.size())   
    {
        TreeNode *temp = Q.front();
        Q.pop();

        if(i < nodes.size() && nodes[i] != -1)
        {
            temp->left = new TreeNode(nodes[i]);
            Q.push(temp->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1)
        {
            temp->right = new TreeNode(nodes[i]);
            Q.push(temp->right);
        }
        i++;
    }
    return newNode;
}

class Solution {

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(!original || !cloned || !target) return nullptr;

        if(cloned->val == target->val) return cloned;
        cloned = getTargetCopy(original, cloned->left, target);
        cloned = getTargetCopy(original, cloned->right, target);
    }
};

int main()
{
    system("cls");

    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;

    vector<int> nodes = {7, 4, 3, -1, -1, 6, 19};

    root1 = buildTree(nodes);    
    root2 = buildTree(nodes);    

    TreeNode *target = root1->right;
    Solution S;

    cout << S.getTargetCopy(root1, root2, target)->val << endl;

    return 0;
}
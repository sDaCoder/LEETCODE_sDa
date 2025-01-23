// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
        if (!root)
            return;

        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

};

class Solution : public Creation
{
public:
    
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;

        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 1;

        while(!Q.empty())
        {
            int qsize = Q.size();

            for (int i = 0; i < qsize; i++)
            {
                TreeNode *temp = Q.front();
                Q.pop();

                if(!temp->left && !temp->right) return depth;

                if(temp->left) Q.push(temp->left);    
                if(temp->right) Q.push(temp->right);    
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    Solution S;

    TreeNode *root = S.buildTree(nodes);
    S.preOrder(root);
    cout << endl;

    cout << S.minDepth(root) << endl;
    return 0;
}
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

TreeNode *buildtree(vector<int> &values)
{
    if(values.size() == 0 || values[0] == -1) return nullptr;

    TreeNode *newNode = new TreeNode(values[0]);
    queue<TreeNode *> Q;
    Q.push(newNode);
    int i = 1;

    while(i < values.size() && !Q.empty())
    {
        TreeNode *temp = Q.front();
        Q.pop();

        if(i < values.size() && values[i] != -1)
        {
            temp->left = new TreeNode(values[i]);
            Q.push(temp->left);
        }
        i++;

        if(i < values.size() && values[i] != -1)
        {
            temp->right = new TreeNode(values[i]);
            Q.push(temp->right);
        }
        i++;
    }
    return newNode;
}

void preOrder(TreeNode *root)
{
    if(!root) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution {
    void leftLeaf(TreeNode *root, int& findSum)
    {
        if(!root) return;

        TreeNode *left = root->left;
        if(root->left && (!left->left && !left->right)) findSum += left->val;
        leftLeaf(root->left, findSum);
        leftLeaf(root->right, findSum);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int findSum = 0;
        leftLeaf(root, findSum);
        return findSum;      
    }
};

int main(){
    system("cls");
    
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    TreeNode *root = buildtree(nodes);
    preOrder(root);
    cout << endl;
    
    Solution S;
    cout << S.sumOfLeftLeaves(root) << endl;
    
    return 0;
}
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

    void grandSum(TreeNode *root, int& findSum)
    {
        if(!root) return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        if(root->val % 2 == 0)
        {
            if(left)
            {
                if(left->left) findSum += left->left->val;
                if(left->right) findSum += left->right->val;
            }

            if(right)
            {
                if(right->left) findSum += right->left->val;
                if(right->right) findSum += right->right->val;
            }
        }
        
        grandSum(root->left, findSum);
        grandSum(root->right, findSum);
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        int findSum = 0;
        grandSum(root, findSum);
        return findSum;
    }
};

int main(){
    system("cls");
    
    vector<int> nodes = {6,7,8,2,7,1,3,9,-1,1,4,-1,-1,-1,5};
    TreeNode *root = buildtree(nodes);
    preOrder(root);
    cout << endl;
    
    Solution S;
    cout << S.sumEvenGrandparent(root) << endl;
    
    return 0;
}
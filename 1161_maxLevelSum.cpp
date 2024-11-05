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

class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        
    }
};

int main(){
    system("cls");
    vector<int> nodes = {1,7,0,7,-8,-1,-1};
    TreeNode *root = buildTree(nodes);


       
    return 0;
}
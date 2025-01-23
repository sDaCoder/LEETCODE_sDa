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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void totalNodes(TreeNode *root, int& count)
    {
        if(root == nullptr) return;

        count++;
        totalNodes(root->left, count);
        totalNodes(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        totalNodes(root, count);
        return count;
    }
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
    if(root == nullptr) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> nodes = {1};
    TreeNode *root = buildtree(nodes);
    preOrder(root);
    cout << endl;

    Solution S;
    cout << S.countNodes(root) << endl;
    
    return 0;
}
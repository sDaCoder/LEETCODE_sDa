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
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int n = Q.size();
            int maxi = INT_MIN;

            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = Q.front();
                Q.pop();

                maxi = max(maxi, temp->val);

                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

int main(){
    system("cls");
    vector<int> nodes = {1,3,2,5,3,-1,9};
    TreeNode *root = buildtree(nodes);
    preOrder(root);
    cout << endl;

    Solution S;
    vector<int> ans = S.largestValues(root);
    for(auto i: ans) cout << i << " ";
    
    return 0;
}
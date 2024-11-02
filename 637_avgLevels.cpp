#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
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
    if (!root)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution
{
    vector<int> largestLevelNode(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty())
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
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        queue<TreeNode *> Q;
        Q.push(root);

        while(!Q.empty())
        {
            int n = Q.size();
            double sum = 0;

            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = Q.front();
                Q.pop();

                sum += temp->val;

                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
            ans.push_back(round(sum/n * pow(10, 5)) / pow(10, 5));
        }
        return ans;
    }
};

int main()
{
    system("cls");
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};

    TreeNode *root = buildTree(nodes);
    preOrder(root);
    cout << endl;

    Solution S;
    vector<double> ans = S.averageOfLevels(root);

    for(auto i = ans.begin(); i != ans.end(); i++) cout << *i << " ";
    // for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    return 0;
}
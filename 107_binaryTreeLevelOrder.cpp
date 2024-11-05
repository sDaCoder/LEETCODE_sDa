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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int n = Q.size();
            vector<int> levels;

            for(int i = 0; i < n; i++)    
            {
                TreeNode *temp = Q.front();
                Q.pop();

                levels.push_back(temp->val);

                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
            ans.push_back(levels);
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};

int main(){
    system("cls");
    
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};

    TreeNode *root = buildTree(nodes);
    preOrder(root);
    cout << endl;

    Solution S;
    vector<vector<int>> ans = S.levelOrderBottom(root);
    
    for (const auto& level : ans) 
    {
        for (int val : level) 
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
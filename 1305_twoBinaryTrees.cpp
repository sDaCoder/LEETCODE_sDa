#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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
    if (values.size() == 0 || values[0] == -1)
        return nullptr;

    TreeNode *newNode = new TreeNode(values[0]);
    queue<TreeNode *> Q;
    Q.push(newNode);
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
    return newNode;
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
public:
    void allElements(TreeNode *r1, vector<int> &ans)
    {
        if (!r1) return;

        ans.push_back(r1->val);
        allElements(r1->left, ans);
        allElements(r1->right, ans);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;
        allElements(root1, ans);
        allElements(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    system("cls");
    vector<int> n1 = {2, 1, 4};
    vector<int> n2 = {1, 0, 3};

    TreeNode *r1 = buildtree(n1);
    TreeNode *r2 = buildtree(n2);

    Solution S;
    vector<int> ans = S.getAllElements(r1, r2);

    for(auto i : ans) cout << i << " ";

    return 0;
}
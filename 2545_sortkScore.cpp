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

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int> nums;
        for(int i = 0; i < score.size(); i++)
        {
            nums.push_back(score[i][k]);
        }
        sort(nums.rbegin(), nums.rend());
        // return nums;

        for(int i = 0; i < nums.size(); i++)
        {
            score[i][k] = nums[i];
        }
        // delete(nums);
        return score;
    }
};

int main(){
    // vector<vector<int>> score = {{10,6,11,1},{7,5,9,2},{4,8,3,15}};
    vector<vector<int>> score = {{3, 4}, {5, 6}};
    int k = 0;

    Solution S;
    // for(auto i : S.sortTheStudents(score, k)) cout << i << " ";

    for(auto i : S.sortTheStudents(score, k))
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
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
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i = 0, j = numbers.size() - 1, s;
        vector<int> ans;

        while (i < j)
        {
            s = numbers[i] + numbers[j];

            if(s < target) i++;
            else if(s > target) j--;
            else{
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

int main()
{
    vector<int> nums = {2,3,4};
    int target = 6;

    Solution S;
    vector<int> ans = S.twoSum(nums, target);

    for(auto i = ans.begin(); i != ans.end(); i++) cout << *i << " ";
    cout << endl;
    return 0;
}
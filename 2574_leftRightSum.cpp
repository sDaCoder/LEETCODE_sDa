#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {

        int sumArr(vector<int>& nums)
        {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
            }
            return sum;
        }
    
    public:

        vector<int> leftRightDifference(vector<int>& nums)
        {
            vector<int> ans(nums.size());
            int leftS = 0;
            int rightS = sumArr(nums) - nums[0];
            ans[0] = abs(leftS - rightS);

            for(int i = 1; i < nums.size(); i++)
            {
                leftS += nums[i - 1];
                rightS -= nums[i];
                ans[i] = abs(leftS - rightS);
            }
            
            return ans;
        }
};

int main(){
    system("cls");
    vector<int> nums = {1};
    
    Solution s;
    for(auto i : s.leftRightDifference(nums)) cout<<i<<" ";
    // cout<<"It's SDA"<<endl;
    return 0;
}
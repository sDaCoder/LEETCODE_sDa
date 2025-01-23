#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
using namespace std;

int maximumStrongPairXor(vector<int>& nums) {
    int a, b, xorVal = INT_MIN;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < nums.size(); j++)
        {
            a = nums[index];
            b = nums[j];
            if(abs(a - b) <= min(a, b))
            {
                xorVal = max(xorVal, a ^ b);
            }
        }
    }
    return xorVal;
}

int main(){
    vector<int> nums = {5,6,25,30};
    cout << maximumStrongPairXor(nums) << endl;
    return 0;
}
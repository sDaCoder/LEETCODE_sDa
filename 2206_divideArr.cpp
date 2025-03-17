#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<unordered_map>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums)
        {
            mp[num]++;
        }

        for(auto i: mp)
        {
            if(i.second % 2 != 0) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution S;
    cout << S.divideArray(nums) << endl;
    return 0;
}
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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> ans;
    for(int num : nums1)
    {
        if(find(nums2.begin(), nums2.end(), num) != nums2.end())
        {
            if(find(ans.begin(), ans.end(), num) == ans.end())
            {
                ans.push_back(num);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    for(auto i : intersection(nums1, nums2)) cout << i << " ";
    return 0;
}
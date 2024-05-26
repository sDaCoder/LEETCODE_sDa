#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2, -1);
            int start = 0, end = nums.size() - 1, mid;

            while(start <= end)
            {
                mid = (start + end)/2;

                if (nums[mid] == target)
                {
                    result[0] = mid;
                    end = mid - 1;
                }
                
                else if (nums[mid] < target)
                {
                    start = mid + 1;
                }

                else
                {
                    end = mid - 1;
                }
            }
            
            start = 0, end = nums.size() - 1, mid;

            while(start <= end)
            {
                mid = (start + end)/2;

                if (nums[mid] == target)
                {
                    result[1] = mid;
                    start = mid + 1;
                }
                
                else if (nums[mid] < target)
                {
                    start = mid + 1;
                }

                else
                {
                    end = mid - 1;
                }
            }

            
            return result;
        }
};

int main(){
    system("cls");
    // cout<<"It's SDA"<<endl;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 10;

    Solution s;
    for(auto i: s.searchRange(nums, target)) cout<<i<<" ";
    return 0;
}
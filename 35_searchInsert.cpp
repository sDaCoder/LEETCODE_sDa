#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = (nums.size() - 1), mid;      
        int result;

        while (start <= end)
        {
            mid = (start + end)/2;

            if (nums[mid] == target)
            {
                return mid;
            }

            else if (nums[mid] < target)
            {
                start = (mid + 1);
            }
            
            else end = (mid - 1);
            
        }
        if (nums[mid] < target)
        {
            return (mid + 1);
        }
        return mid;
    }
};

int main(){
    system("cls");
    
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    
    Solution s;
    cout<<s.searchInsert(nums, target);
        
    return 0;
}
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

vector<int> sortedSquares(vector<int>& nums) 
{
    vector<int> res(nums.size());
    int i = 0, j = nums.size() - 1, k = nums.size() - 1;

    while(i <= j)
    {
        if(abs(nums[i]) < abs(nums[j]))
        {
            res[k] = nums[j] * nums[j];
            j--;
        }
        else
        {
            res[k] = nums[i] * nums[i];
            i++;
        }
        k--;
    }
    return res;
}

int main(){
    vector<int> nums = {-7,-3,2,3,11};
    vector<int> res = sortedSquares(nums);
    for(auto var : res)
    {
        cout << var << " ";
    }

    return 0;
}
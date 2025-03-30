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

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<bool> visited(nums.size() + 1, false);
    vector<int> ans;
    for(int num: nums)
    {
        if(!visited[num])
        {
            visited[num] = true;
        }
    }

    for(int i = 1; i < visited.size(); i++)
    {
        if(!visited[i]) ans.push_back(i);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,1};
    vector<int> res = findDisappearedNumbers(nums);
    for(int num : res)
    {
        cout << num << " ";
    }
    return 0;
}
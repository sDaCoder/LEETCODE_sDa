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

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, bool> visited;
    vector<int> res;
    for(int num: nums)
    {
        if(visited[num] == true)
        {
            res.push_back(num);
        }
        else visited[num] = true;
    }
    return res;
}

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = findDuplicates(nums);
    for(int num : res)
    {
        cout << num << " ";
    }
    return 0;
}
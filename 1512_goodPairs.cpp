#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
#include<unordered_map>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {

    unordered_map<int, int> goodMP;
    int count = 0, n;
    for (int i = 0; i < nums.size(); i++)
    {
        goodMP[nums[i]]++;
    }

    for(auto i : goodMP)
    {
        n = i.second;
        count += (int)(n * (n - 1) / 2);
    }
    return count;
}

int main(){
    vector<int> nums = {1,1,1,1};
    cout << numIdenticalPairs(nums) << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;



int main(){
    // cout<<"It's SDA"<<endl;
    vector<int> nums = {1,1,2,2,2,3};

    map<int, int>freq;
    map<int, int>freq1;
    vector<int> ans;
    for(int num: nums)
    {
        freq[num]++;
    }

    for(auto i : freq) freq1[i.second] = i.first;
    for(auto i : freq1)
    {
        for (int j = 0; j < i.first; j++)
        {
            ans.push_back(i.second);
        }
    }

    // for(int i : ans) cout << i << " ";

    for(auto i : freq1) cout << i.first << " : " << i.second << endl;
    return 0;
}
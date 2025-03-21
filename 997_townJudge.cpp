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

int findJudge(int n, vector<vector<int>>& trust) {
    vector<vector<int>> adjl(n + 1);
    unordered_map<int, vector<int>> mp;
    int judge = -1;

    for(vector<int> rel: trust)
    {
        adjl[rel[0]].push_back(rel[1]);
    }
    for(int i = 1; i < adjl.size(); i++)
    {
        if(adjl[i].size() > 0)
        {
            mp[i] = adjl[i];
        }
        else judge = i;
    }
    if(judge == -1) return judge;

    for(auto values: mp)
    {
        sort(values.second.begin(), values.second.end());
        if(!binary_search(values.second.begin(), values.second.end(), judge))
            return -1;
    }

    return judge;
}

int main(){
    vector<vector<int>> trust = {
        {1, 2},
    };
    int n = 2;
    cout << findJudge(n, trust) << endl;
    return 0;
}
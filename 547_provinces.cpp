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

class Solution {
    void DFSTraverseStack(int node, vector<bool>& visited, vector<vector<int>> ADJ)
    {
        visited[node] = true;
        stack<int> S;
        S.push(node);
    
        while (!S.empty())
        {
            int v = S.top();
            S.pop();
    
            reverse(ADJ[v].begin(), ADJ[v].end());
            
            for(int i: ADJ[v])
            {
                if(!visited[i])   
                {
                    visited[i] = true;
                    S.push(i); 
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> ADJL(V);
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[i].size(); j++)
            {
                if(isConnected[i][j] && i != j) ADJL[i].push_back(j);
            }
        }

        vector<bool> visited(V, false);
        int count = 0;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                count++; DFSTraverseStack(i, visited, ADJL);
            }
        }
        return count;
    }
};
int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution S;
    cout << S.findCircleNum(isConnected) << endl;
    return 0;
}
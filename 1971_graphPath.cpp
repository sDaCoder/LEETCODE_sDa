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
    void DFSTraverse(int node, vector<bool>& visited, vector<vector<int>> ADJ)
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> ADJList(n);
        for(vector<int> i: edges)
        {
            ADJList[i[0]].push_back(i[1]);
            ADJList[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n, false);
        DFSTraverse(source, visited, ADJList);
        return visited[destination];
    }
};

void createADJList(int n, vector<vector<int>> edges, vector<vector<int>>& ADJList)
{
    for(vector<int> i: edges)
    {
        ADJList[i[0]].push_back(i[1]);
        ADJList[i[1]].push_back(i[0]);
    }
}
int main(){
    int n = 6;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};

    vector<vector<int>> ADJList(n);
    createADJList(n, edges, ADJList);

    for(int i = 0; i < ADJList.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < ADJList[i].size(); j++)
        {
            cout << ADJList[i][j] << " ";
        }
        cout << endl;
    }

    Solution S;
    bool res = S.validPath(n, edges, 0, 1);
    cout << res << endl;

    return 0;
}
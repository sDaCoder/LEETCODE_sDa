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
    bool checkBFS(int start, vector<vector<int>>& graph, vector<int>& color) {
        color[start] = 0;
        queue<int> Q;
        Q.push(start);

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            for (int it : graph[node]) {
                // If the adj nodes are not colored
                if (color[it] == -1) {
                    color[it] = !color[node];
                    Q.push(it);
                }

                // It was colored before
                // and the color is same
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkDFS(int node, int col, vector<int>& color, vector<vector<int>>& graph)
    {
        color[node] = col;

        for(int it: graph[node])
        {
            if(color[it] == -1)
            {
                // If any of the DFS calls returns false, it is not Bipartite
                if(!checkDFS(it, !col, color, graph)) return false;
            }

            // 
            else if(color[it] == col)
            {
                return false;
            }
        }
        return true;
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // if (!checkBFS(i, graph, color)) {
                if(!checkDFS(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    // cout<<"It's SDA"<<endl;
    vector<vector<int>> graph = {
        {}
    };
    return 0;
}
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
    void BFSTraverse(pair<int, int> node, vector<vector<bool>>& visited, vector<vector<char>> grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> Q;
        Q.push(node);
        int m, n;

        while (!Q.empty())
        {
            pair<int, int> P = Q.front();
            Q.pop();
            m = P.first;
            n = P.second;
            visited[m][n] = true;

            if(m-1 >= 0 && grid[m-1][n] == '1' && !visited[m-1][n])
            {
                Q.push({m-1, n});
            }
            if(m+1 < rows && grid[m+1][n] == '1' && !visited[m+1][n])
            {
                Q.push({m+1, n});
            }
            if(n-1 >= 0 && grid[m][n-1] == '1' && !visited[m][n-1])
            {
                Q.push({m, n-1});
            }
            if(n+1 < cols && grid[m][n+1] == '1' && !visited[m][n+1])
            {
                Q.push({m, n+1});
            }
        }
        
    }
    
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFSTraverse(pair<int, int> node, vector<vector<bool>>& visited, vector<vector<char>>& grid)
    {
        int m = node.first;
        int n = node.second;
        visited[node.first][node.second] = true;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(auto dir: directions)
        {
            int deli = dir[0];
            int delj = dir[1];
            if(
                m + deli >= 0 && 
                m + deli < rows &&
                n + delj >= 0 &&
                n + delj < cols &&
                grid[m + deli][n + delj] == '1' &&
                !visited[m + deli][n + delj]
            ) 
            DFSTraverse({m + deli, n + delj}, visited, grid);
        }

        // if(m-1 >= 0 && grid[m-1][n] == '1' && !visited[m-1][n])
        // {
        //     DFSTraverse({m - 1, n}, visited, grid);
        // }
        // if(m+1 < rows && grid[m+1][n] == '1' && !visited[m+1][n])
        // {
        //     DFSTraverse({m + 1, n}, visited, grid);
        // }
        // if(n-1 >= 0 && grid[m][n-1] == '1' && !visited[m][n-1])
        // {
        //     DFSTraverse({m, n - 1}, visited, grid);
        // }
        // if(n+1 < cols && grid[m][n+1] == '1' && !visited[m][n+1])
        // {
        //     DFSTraverse({m, n + 1}, visited, grid);
        // }
    }

    void DFSStack(pair<int, int> node, vector<vector<bool>>& visited, vector<vector<char>>& grid)
    {
        int m = node.first;
        int n = node.second;
        visited[node.first][node.second] = true;
        stack<pair<int, int>> S;
        S.push(node);
        int rows = grid.size();
        int cols = grid[0].size();

        while (!S.empty())
        {
            pair<int, int> P = S.top();
            S.pop();

            for(vector<int> dir: directions)
            {
                int deli = dir[0];
                int delj = dir[1];
                if(
                    m + deli >= 0 && m + deli < rows &&
                    n + delj >= 0 && n + delj < cols &&
                    grid[m + deli][n + delj] == '1' &&
                    !visited[m + deli][n + delj]
                )
                {
                    visited[m + deli][n + delj] = true;
                    S.push({m + deli, n + delj});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        pair<int, int> node;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    node = {i, j};
                    DFSStack(node, visited, grid);
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution S;
    int res = S.numIslands(grid);
    cout << res << endl;
    return 0;
}
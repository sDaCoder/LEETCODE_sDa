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
    int rows, cols;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void DFSStack(pair<int, int> cell, int& fish, vector<vector<bool>>& visited, vector<vector<int>>& grid)
    {
        visited[cell.first][cell.second] = true;
        // fish += grid[cell.first][cell.second];
        stack<pair<int, int>> S;
        S.push({cell.first, cell.second});

        while (!S.empty())
        {
            int x = S.top().first, y = S.top().second;
            S.pop();
            fish += grid[x][y];

            for(auto dir: directions)
            {
                int dx = dir[0], dy = dir[1];
                int nx = x + dx, ny = y + dy;
                if (
                    nx >= 0 && nx < rows &&
                    ny >= 0 && ny < cols &&
                    grid[nx][ny] > 0 && !visited[nx][ny]
                ) {
                    visited[nx][ny] = true;
                    S.push({nx, ny});
                }
            }
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int fish = 0, maxFish = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] > 0)
                {
                    DFSStack({i, j}, fish, visited, grid);
                    maxFish = max(maxFish, fish);
                    fish = 0;
                }
            }
        }
        return maxFish;
    }
};

int main(){
    vector<vector<int>> grid = {
        {0,2,1,0},
        {4,0,0,3},
        {1,0,0,4},
        {0,3,2,0},
    };
    Solution S;
    cout << S.findMaxFish(grid) << endl;
    return 0;
}
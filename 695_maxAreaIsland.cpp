#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

class Solution
{
    int rows, cols;
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFSTraverse(pair<int, int> node, int& area, vector<vector<bool>>& visited, vector<vector<int>> &grid)
    {
        visited[node.first][node.second] = true;
        area = 1;
        stack<pair<int, int>> S;
        S.push(node);

        while(!S.empty())
        {
            int x = S.top().first;
            int y = S.top().second;
            S.pop();

            for(auto dir: directions)
            {
                int dx = dir[0];
                int dy = dir[1];

                if(
                    x + dx >= 0 && x + dx < this->rows &&
                    y + dy >= 0 && y + dy < this->cols &&
                    grid[x + dx][y + dy] == 1 && !visited[x + dx][y + dy]
                )
                {
                    visited[x + dx][y + dy] = true;
                    S.push({x + dx, y + dy});
                    area++;
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        this->rows = grid.size();
        this->cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int area = 0, A = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    DFSTraverse({i, j}, A, visited, grid);
                    area = max(area, A);
                    A = 0;
                }
            }
        }
        return area;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    Solution S;
    cout << S.maxAreaOfIsland(grid) << endl;
    return 0;
}
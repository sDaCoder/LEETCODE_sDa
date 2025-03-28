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
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void DFSTraverse(pair<int, int> node, int &P, vector<vector<bool>> &visited, vector<vector<int>> &grid)
    {
        visited[node.first][node.second] = true;
        stack<pair<int, int>> S;
        S.push(node);

        while (!S.empty())
        {
            int x = S.top().first;
            int y = S.top().second;
            S.pop();
            

            for (auto dir : directions)
            {
                int dx = dir[0];
                int dy = dir[1];

                if (
                    x + dx < 0 || x + dx >= this->rows ||
                    y + dy < 0 || y + dy >= this->cols ||
                    grid[x + dx][y + dy] == 0
                ) P++;
                else if(!visited[x + dx][y + dy])
                {
                    visited[x + dx][y + dy] = true;
                    S.push({x + dx, y + dy});
                }
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        // this->rows = grid.size();
        // this->cols = grid[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // int perimeter = 0, P = 0;

        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < cols; j++)
        //     {
        //         if (grid[i][j] == 1 && !visited[i][j])
        //         {
        //             DFSTraverse({i, j}, P, visited, grid);
        //             perimeter = max(perimeter, P);
        //             P = 0;
        //         }
        //     }
        // }
        // return perimeter;

        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }

};

int main()
{
    // vector<vector<int>> grid = {
    //     {0, 1, 0, 0},
    //     {1, 1, 1, 0},
    //     {0, 1, 0, 0},
    //     {1, 1, 0, 0},
    // };
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
    };
    Solution S;
    cout << S.islandPerimeter(grid) << endl;
    return 0;
}
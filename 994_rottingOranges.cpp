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

vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    // {{r, c}, t}
    queue<pair <pair<int, int>, int>> Q;

    // Setting the values of the visited matrix
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 2) 
            {
                visited[i][j] = 2;
                Q.push({{i, j}, 0});
            }
        }
    }
    int req_time = 0;
    // Traversal through BFS
    while(!Q.empty())
    {
        int r = Q.front().first.first;
        int c = Q.front().first.second;
        int t = Q.front().second;
        Q.pop();
        req_time = max(req_time, t);

        for(vector<int> dir: directions)
        {
            int dx = dir[0];
            int dy = dir[1];
            if(
                r + dx >= 0 && r + dx < rows &&
                c + dy >= 0 && c + dy < cols &&
                grid[r + dx][c + dy] == 1 &&
                !visited[r + dx][c + dy]
            ){
                visited[r + dx][c + dy] = 2;
                Q.push({{r + dx, c + dy}, t + 1});
            }
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j]) return -1;
        }
    }
    return req_time;
}

int main(){
    vector<vector<int>> oranges = {
        {0, 1},
    };
    cout << orangesRotting(oranges) << endl;
    return 0;
}
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
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols, color, initColor;

    void DFSTraverse(pair<int, int> node, vector<vector<int>>& visited, vector<vector<int>>& image)
    {
        visited[node.first][node.second] = color;
        
        int x = node.first;
        int y = node.second;
        for(auto dir : directions)
        {
            int dx = dir[0];
            int dy = dir[1];
            if(
                x + dx >= 0 && x + dx < this->rows &&
                y + dy >= 0 && y + dy < this->cols &&
                image[x + dx][y + dy] == this->initColor &&
                visited[x + dx][y + dy] == this->initColor
            ) DFSTraverse({x + dx, y + dy}, visited, image);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->rows = image.size();      
        this->cols = image[0].size();
        this->initColor = image[sr][sc];
        this->color = color;
        vector<vector<int>> visited = image;

        if(color == initColor) return image;

        DFSTraverse({sr, sc}, visited, image);        
        return visited;
    }
};

int main(){
    // vector<vector<int>> image = {
    //     {1,1,1},
    //     {1,1,0},
    //     {1,0,1}
    // };
    vector<vector<int>>image = {
        {0, 0, 0},
        {0, 0, 0}
    };
    int sr = 0, sc = 0; 
    int color = 0;

    Solution S;
    vector<vector<int>> result = S.floodFill(image, sr, sc, color);
    for(vector<int> row : result)
    {
        for(int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
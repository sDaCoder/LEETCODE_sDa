#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include<unordered_map>
using namespace std;

class Solution
{
    unordered_map<int, int> mp;
public:
    vector<int> generate(int numRows)
    {
        vector<int> prevRow = {1};
        vector<int> newRow;
        for(int i = 1; i < numRows + 1; i++)
        {
            newRow.resize(i + 1, 1);
            for(int j = 0; j < i; j++)
            {
                newRow[j] = prevRow[j - 1] + prevRow[j];
            }
            prevRow = newRow;
        }
        return newRow;
    }
};

int main()
{
    int r = 3;
    Solution S;
    vector<int> row = S.generate(r);
    for(int el: row) cout << el << " ";
    return 0;
}
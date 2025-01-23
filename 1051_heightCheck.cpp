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

int heightChecker(vector<int>& heights) {
    vector<int> sortedHeights = heights;
    sort(sortedHeights.begin(), sortedHeights.end());

    // return sortedHeights;

    int unmatched = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        if(heights[i] != sortedHeights[i]) unmatched++;
    }
    return unmatched;
}

int main(){
    vector<int> heights = {1,1,4,2,1,3};
    // for(auto i : heightChecker(heights)) cout << i << " ";
    cout << heightChecker(heights) << endl;
    return 0;
}
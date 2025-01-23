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



int main(){
    vector<int> nums = {2, 3, 5, 4, 5, 3, 4};
    int unique = 0;
    for(int num: nums)
    {
        unique = unique ^ num;
    }
    cout << unique << endl;
    return 0;
}
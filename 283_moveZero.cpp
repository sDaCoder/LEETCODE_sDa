#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0, j;
    for (i = 0; i < nums.size(); i++)
    {
        
    }
    
}

int main()
{
    system("cls");
    // cout << "It's SDA" << endl;
    vector<int> nums = {0, 0, 1};
    moveZeroes(nums);
    for (auto i : nums) cout << i << " ";
    return 0;
}
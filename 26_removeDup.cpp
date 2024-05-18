#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        j = i + 1;
        while (j < nums.size())
        {
            if (nums[j] == nums[i])
            {
                nums.erase(nums.begin() + j);
            }
            else
            {
                break;
            }
        }
    }
    return nums.size();
}

int main()
{
    system("cls");
    // cout<<"It's SDA"<<endl;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 6, 6};
    int size = sizeof(nums) / sizeof(int);
    int result = removeDuplicates(nums);

    // for(auto i = nums.begin(); i != nums.end(); i++) cout<<*i<<" ";
    for (auto i : nums) cout << i << " ";
    // for(auto i = nums.rbegin(); i != nums.rend(); i++) cout<<*i<<" ";

    return 0;
}
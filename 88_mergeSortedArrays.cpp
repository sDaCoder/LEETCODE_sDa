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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res(m + n);
    int i = 0, j = 0, k = 0;

    if(n == 0)
    {
        for (int i = 0; i < nums1.size() - m; i++)
        {
            nums1.pop_back();
        }
        return;
    }
    
    if(m == 0)
    {
        for (int i = 0; i < nums2.size() - n; i++)
        {
            nums2.pop_back();
        }    
        nums1 = nums2;
        return;
    }

    while (i < m && j < n)
    {
        if(nums1[i] < nums2[j])
        {
            res[k] = nums1[i];
            i++;
        }
        else
        {
            res[k] = nums2[j];
            j++;
        }
        k++;
    }

    while(i < m)
    {
        res[k] = nums1[i];
        i++;
        k++;
    }

    while(j < n)
    {
        res[k] = nums2[j];
        j++;
        k++;
    }
    nums1 = res;
}

int main(){
    // vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums1 = {4,0,0,0,0,0};
    int m = 1;

    vector<int> nums2 = {1,2,3,5,6};
    int n = 5;

    merge(nums1, m, nums2, n);
    for(auto var : nums1)
    {
        cout << var << " ";
    }
    return 0;
}
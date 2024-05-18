#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution
{
    public:
        vector<string> findRelativeRanks(vector<int>& score) {
            vector<string> rank(score.size());

            int i = 0, maxInd;

            while (i < score.size())
            {
                maxInd = distance(score.begin(), max_element(score.begin(), score.end()));
                score[maxInd] = -1;

                if (i == 0)
                {
                    rank[maxInd] = "Gold Medal";
                }

                else if (i == 1)
                {
                    rank[maxInd] = "Silver Medal";
                }

                else if (i == 2)
                {
                    rank[maxInd] = "Bronze Medal";
                }

                else
                {
                    rank[maxInd] = to_string(i+1);    
                }
                i++;        
            }
            return rank;
        }
};

int main(){
    system("cls");
    vector<int> score = {10,3,8,9,4};

    Solution s;
    for(auto i: s.findRelativeRanks(score)) cout<<i<<" ";
    // auto maxElement = max_element(score.begin(), score.end());
    // cout<<maxInd;
    
    return 0;
}
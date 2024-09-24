#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
    int stackSum(stack<int>& stk)
    {
        int sum = 0;
        while (!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
    
    public:
        int calPoints(vector<string>& operations) 
        {
            stack<int> stk;
            int newScore, poppedScore, num;

            for(auto i: operations)
            {
                if(i == "C")
                {
                    stk.pop();
                }
                else if (i == "D")
                {
                    newScore = 2*stk.top();
                    stk.push(newScore);
                }
                else if (i == "+")
                {
                    poppedScore = stk.top();
                    stk.pop();
                    newScore = poppedScore + stk.top();
                    stk.push(poppedScore);
                    stk.push(newScore);
                }
                else
                {
                    num = stoi(i);
                    stk.push(num);
                }
            }
            return stackSum(stk);
        }
};

int main(){
    system("cls");
    vector<string>ops = {"5","2","C","D","+"};

    Solution s;
    cout<<s.calPoints(ops);
    return 0;
}
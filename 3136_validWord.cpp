// https://leetcode.com/problems/valid-word/

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) 
    {
        if(word.length() < 3) return false;
        
        int vow = 0, cons = 0;
        for(int i = 0; i < word.length(); i++)
        {
            if(!isalnum(word[i])) return false;

            if(tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || tolower(word[i]) == 'i' || tolower(word[i]) == 'o' || tolower(word[i]) == 'u') vow++;

            else if(isalpha(word[i])) cons++;
        }
        return ((vow > 0) && (cons > 0));
    }
};

int main(){
    system("cls");
    string word = "234$das";
    Solution S;
    cout << S.isValid(word) << endl;
    return 0;
}
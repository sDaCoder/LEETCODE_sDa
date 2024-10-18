#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool match(char a, char b){
        if(a == '(' && b == ')') return true;
        if(a == '[' && b == ']') return true;
        if(a == '{' && b == '}') return true;
        else return false;
    }

    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if(!st.empty() && match(st.top(), s[i])) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main(){
    system("cls");
    // cout<<"It's SDA"<<endl;
    string s = "]";
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}
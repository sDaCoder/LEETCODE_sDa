#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        string str = "";
              
        for(int i = 0; i < s.length(); i++){
            if(isalnum(s[i]))
            {
                if(s[i] >= 'A' && s[i] <= 'Z') str += (tolower((s[i])));
                else str += (s[i]);
            }
        }

        bool isPal = true;
        for(int i = 0, j = str.length() - 1; i < j; i++, j--){
            if(str[i] != str[j]) {
                isPal = false;
                break;
            }
        }
        return isPal;
    }
};

int main(){
    system("cls");
    cout<<"It's SDA"<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {

    bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
	}

	int prec(char c) {
		if (c == '+' || c == '-') return 1;
		else if (c == '/' || c == '*' || c == '%') return 2;
		else return 0;
	}
    
public:

    string postfix(string infix) {
		string result;
		stack<char>S;

		S.push('(');
		infix.push_back(')');

		for (int i = 0; infix[i] != '\0'; i++) {

			if (infix[i] == '(') {
				S.push('(');
			}

			else if (isdigit(infix[i]) || isalpha(infix[i])) {
				result.push_back(infix[i]);
			}

			else if (infix[i] == ')') {
				while (S.top() != '(') {
					result.push_back(S.top());
					S.pop();
				}
				S.pop();
			}

			else if (isOperator(infix[i])) {
				while (S.top() != '(' && (prec(S.top()) >= prec(infix[i]))) {
					result.push_back(S.top());
					S.pop();
				}
				S.push(infix[i]);
			}
		}
		return result;
	}

    int calculate(string s) {
        string newExp = postfix(s);
		stack<int> S;
		int a, b;
	
		for (int i = 0; i < newExp.length(); i++) {
			if (isdigit(newExp[i])) {
				S.push(newExp[i] - '0');
			} 
			
			else {
				a = S.top();
				S.pop();
				b = S.top();
				S.pop();
				
				if (newExp[i] == '+') {
					S.push(b + a);
				} 
				
				else if (newExp[i] == '-') {
					S.push(b - a);
				} 
				
				else if (newExp[i] == '*') {
					S.push(b * a);
				} 
				
				else if (newExp[i] == '/') {
					S.push(b / a);
				} 
				
				else if (newExp[i] == '%') {
					S.push(b % a);
				}
			}
		}
		return S.top();
    }
};

int main()
{
    
    string s("-'(2 + 3)");
    Solution S;
    cout << S.postfix(s) << endl;
    cout << S.calculate(s) << endl;
    return 0;
}
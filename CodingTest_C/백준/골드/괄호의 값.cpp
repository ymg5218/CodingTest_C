// 2504

#include <iostream>
#include <stack>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	stack<char> stk;
	int result = 0;
	string s;
	cin >> s;

	int tmp = 1;
	for (int i = 0; i < s.length(); i++) {
		char now = s[i];
		if (stk.empty() && (now == ')' || now == ']')) {
			cout << 0;
			return 0;
		}
		
		if (now == '(') {
			tmp *= 2;
			stk.push('(');
		}
		else if (now == '[') {
			tmp *= 3;
			stk.push('[');
		}
		else if (now == ')') {
			if (stk.top() == '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(') {
				result += tmp;
				tmp /= 2;
				stk.pop();
			}
			else {
				tmp /= 2;
				stk.pop();
			}
		}
		else {
			if (stk.top() == '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[') {
				result += tmp;
				tmp /= 3;
				stk.pop();
			}
			else {
				tmp /= 3;
				stk.pop();
			}
			
		}	
	}
	
	if (stk.size() != 0)
		cout << 0;
	else 
		cout << result;
	
}
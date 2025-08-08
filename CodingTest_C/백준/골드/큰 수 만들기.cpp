// 2812

#include <iostream>
#include <stack>
#include <string>
#define endl "\n"

using namespace std;

int N, K;
string num;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N >> K;
	cin >> num;
	stack<char> stk;
	for (int i = 0; i < N; i++) {
		char now = num[i];
		while (!stk.empty() && stk.top() < now && K > 0) {
			stk.pop();
			K--;
		}
		stk.push(now);
	}

	while (K--) {
		stk.pop();
	}
	
	stack<char> res;
	while (!stk.empty()) {
		res.push(stk.top());
		stk.pop();
	}
	
	while (!res.empty() && res.top() == '0') {
		res.pop();
	}

	if (res.empty()) {
		cout << 0 << endl;
	}
	else {
		while (!res.empty()) {
			cout << res.top() << "";
			res.pop();
		}
		cout << endl;
	}
}
// 1294

#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

int N;
priority_queue<string, vector<string>, greater<string>> pq;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		s += 'z';
		pq.push(s);
	}
	
	while (!pq.empty()) {
		string top = pq.top();
		pq.pop();
		cout << top[0];
		top = top.substr(1);
		if (top.size() != 1)
			pq.push(top);
	}
}
#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N * N; i++) {
		int x;
		cin >> x;
		if (pq.size() < N)
			pq.push(x);
		else if (pq.top() < x) {
			pq.pop();
			pq.push(x);
		}
	}
	cout << pq.top();
}
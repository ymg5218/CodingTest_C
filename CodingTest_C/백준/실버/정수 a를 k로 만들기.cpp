// 25418

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int A, K; cin >> A >> K;
	vector<int> dp(1000001);
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x + 1 == K) {
			cout << dp[x] + 1;
			break;
		}
		if (x * 2 == K) {
			cout << dp[x] + 1;
			break;
		}
		if (dp[x + 1] == 0) {
			q.push(x + 1);
			dp[x + 1] = dp[x] + 1;
		}
		if (x * 2 < K && dp[x * 2] == 0) {
			q.push(x * 2);
			dp[x * 2] = dp[x] + 1;
		}
	}
}
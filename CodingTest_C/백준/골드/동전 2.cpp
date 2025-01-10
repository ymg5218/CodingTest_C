// 2294

#include <iostream>
using namespace std;

int main(void) {
	int n, k;
	int dp[10001] = { 0, };
	int coin[100] = { 0, };
	int c;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c > k) continue;
		coin[i] = c;
		dp[coin[i]] = 1;
	}

	if (coin[0] == 0) cout << -1;
	else {
		for (int idx = 0; idx <= k; idx++) {
			if (dp[idx] == 1) continue;
			for (int i = 0; i < n; i++) {
				if (coin[i] <= idx) {
					if (dp[idx] == 0 and dp[idx - coin[i]] != 0) {
						dp[idx] = dp[idx - coin[i]] + 1;
					}
					else if (dp[idx] > 0 and dp[idx - coin[i]] != 0) {
						dp[idx] = min(dp[idx], dp[idx - coin[i]] + 1);
					}
				}
			}
		}
		if (dp[k] == 0) cout << -1;
		else cout << dp[k];
	}
}
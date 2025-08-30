// 1106

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 1'000'000'000

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int C, N;
	cin >> C >> N;

	vector<pair<int, int>> list(N);
	
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}

	vector<int> dp(C + 1, INF);
	dp[0] = 0;
	for (int i = 0; i <= C; i++) {
		for (auto [cost, cus] : list) {
			if (i - cus >= 0) dp[i] = min(dp[i], dp[i - cus] + cost);
			else dp[i] = min(dp[i], cost);
		}
	}

	cout << dp[C] << endl;
}
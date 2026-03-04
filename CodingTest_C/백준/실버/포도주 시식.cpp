// 2156

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> arr(n + 1);
	
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	if (n >= 2) {
		dp[2] = dp[1] + arr[2];
	}
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n];

}
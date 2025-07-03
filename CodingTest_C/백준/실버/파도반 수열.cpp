// 9461

#include <iostream>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	ll dp[100];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	
	int T;
	cin >> T;
	
	while (T--) {
		int idx;
		cin >> idx;
		cout << dp[idx - 1] << endl;
	}
}
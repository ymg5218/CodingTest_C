// 15988

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T; 
	cin >> T;
	
	vector<ll> dp(1'000'001, 0);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1'000'000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1'000'000'009;
	}
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}
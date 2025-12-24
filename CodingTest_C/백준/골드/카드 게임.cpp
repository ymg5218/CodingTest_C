#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int N;
vector<ll> c;
vector<ll> p_sum;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		c.resize(N); p_sum.resize(N);
		vector<vector<ll>> dp(N, vector<ll>(N));
		cin >> c[0];
		p_sum[0] = c[0];
		for (int i = 1; i < N; i++) {
			cin >> c[i];
			p_sum[i] = p_sum[i - 1] + c[i];
		}

		for (int len = 1; len <= N; len++) {
			for (int i = 0; i < N - len + 1; i++) {
				int j = i + len - 1;
				ll currentSum;
				if (i == 0) currentSum = p_sum[j];
				else currentSum = p_sum[j] - p_sum[i - 1];

				if (len == 1)
					dp[i][j] = c[i];
				else {
					dp[i][j] = currentSum - min(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[0][N - 1] << endl;
	}
}
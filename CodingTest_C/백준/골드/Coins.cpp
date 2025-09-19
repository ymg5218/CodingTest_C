// 3067

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int T;
int N, M;
vector<int> coins;
vector<vector<int>> dp;

void init() {
	cin >> N;
	coins.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	cin >> M;
	dp.assign(N + 1, vector<int>(M + 1, 0));
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		int now_coin = coins[i - 1];
		for (int j = 1; j <= M; j++) {
			if (j < now_coin) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			dp[i][j] = dp[i -1][j] + dp[i][j - now_coin];
		}
	}

	cout << dp[N][M] << endl;
} 

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> T;
	while (T--) {
		init();
		solution();
	}

}
// 11660

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<vector<int>> nums;
vector<vector<int>> dp;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	nums.assign(N + 1, vector<int>(N + 1, 0));
	dp.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nums[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + nums[i][j];
		}
	}

	int x1, y1, x2, y2;
	int res;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		res = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << res << endl;
	}
}
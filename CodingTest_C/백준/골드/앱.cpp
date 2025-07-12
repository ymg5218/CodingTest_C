// 7579

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

vector<vector<ll>> dp;
int N, M;
vector<int> mem;
vector<int> cost;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	mem.resize(N + 1);
	cost.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> mem[i];
	}
	int total_cost = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		total_cost += cost[i];
	}
	dp.resize(N + 1, vector<ll>(total_cost + 1, 0));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= total_cost; j++) {
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (i == N && dp[i][j] >= M) {
				cout << j << endl;
				return 0;
			}
		}
	}	
}
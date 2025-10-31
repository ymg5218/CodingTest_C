// 2533

#include <iostream>
#include <vector>
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)

using namespace std;

int N;
vector<vector<int>> tree;
vector<pair<int, int>> dp; // {자신이 얼리어답터, 얼리어답터 아님}
vector<bool> visited;


void init() {
	cin >> N;
	tree.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dp.resize(N + 1, {1, 0});
	visited.resize(N + 1, false);
}

void solution(int x) {
	visited[x] = true;
	for (auto next_x : tree[x]) {
		if (!visited[next_x]) {
			solution(next_x);
			dp[x].first += min(dp[next_x].first, dp[next_x].second);
			dp[x].second += dp[next_x].first;
		}
	}
}

int main() {
	FASTIO;
	init();
	solution(1);
	cout << min(dp[1].first, dp[1].second) << endl;
}
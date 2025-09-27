// 2188

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<vector<int>> cows;
vector<bool> visited;
vector<int> checked;

void init() {
	cin >> N >> M;
	cows.resize(N + 1);
	checked.resize(M + 1, 0);
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			cows[i].push_back(x);
		}
	}
}

int dfs(int now_v) {
	for (const auto& x : cows[now_v]) {
		if (visited[x]) continue;
		visited[x] = true;
		if (!checked[x] || dfs(checked[x])) {
			checked[x] = now_v;
			return 1;
		}
	}
	return 0;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	init();
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		visited.assign(M + 1, false);
		cnt += dfs(i);
	}
	cout << cnt << endl;
}
// 1298

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<vector<int>> stu;
vector<bool> visited;
vector<int> checked;

void init() {
	cin >> N >> M;
	stu.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		stu[a].push_back(b);
	}
	checked.resize(N + 1, 0);
}

int dfs(int x) {
	for (const auto& now_v : stu[x]) {
		if (visited[now_v]) continue;
		visited[now_v] = true;
		if (!checked[now_v] || dfs(checked[now_v])) {
			checked[now_v] = x;
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
		visited.assign(N + 1, false);
		cnt += dfs(i);
	}
	cout << cnt << endl;
}
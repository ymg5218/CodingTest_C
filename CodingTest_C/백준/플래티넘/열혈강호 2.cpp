// 11376

#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> emp;
vector<bool> visited;
vector<int> checked;

void init() {
	cin >> N >> M;
	emp.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int K;
		cin >> K;
		emp[i].resize(K);
		for (int j = 0; j < K; j++) {
			cin >> emp[i][j];
		}
	}
	checked.resize(M + 1, 0);
}

int dfs(int now_v) {
	for (const auto& x : emp[now_v]) {
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
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			visited.assign(M + 1, false);
			result += dfs(i);
		}
		
	}
	cout << result;
}
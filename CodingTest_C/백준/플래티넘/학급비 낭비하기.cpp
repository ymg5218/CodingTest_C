// 14498

#include <iostream>
#include <vector>
using namespace std;

struct Requirement {
	int n_i, m_i, c_i;
};

vector<vector<int>> graph; // 이분 그래프. [선호] - [선호 안함]
vector<Requirement> req; // 각 학생들의 요구사항
vector<int> checked;
vector<bool> visited;

int dfs(int now_v) {
	for (const auto& x : graph[now_v]) {
		if (visited[x]) continue;
		visited[x] = true;

		if (checked[x] == -1 || dfs(checked[x])) {
			checked[x] = now_v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	int n, m, k; cin >> n >> m >> k;
	graph.assign(k, {});
	req.assign(k, {});
	checked.assign(k, -1);
	for (int i = 0; i < k; i++) {
		int n_, m_, c_; cin >> n_ >> m_ >> c_;
		req[i] = { n_, m_, c_ };
	}

	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (req[i].n_i == req[j].n_i || req[i].m_i == req[j].m_i) {	// 각자 고른건 같은데
				if (req[i].c_i != req[j].c_i) {	// 선호하는 방향성이 다름 -> 의견 충돌
					if (req[i].c_i) {	// [선호] - [선호 안함] 형태로 이을 것
						graph[i].push_back(j);
					}
					else {
						graph[j].push_back(i);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		visited.assign(k, false);
		if (dfs(i)) ans++;
	}
	cout << ans;
}
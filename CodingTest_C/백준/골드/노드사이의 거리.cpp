// 1240

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define INF 1e9

using namespace std;

int N, M;
vector<vector<pair<int ,int>>> tree;

void bfs(int start_v, int end_v) {
	vector<int> dis(N + 1, INF);
	dis[start_v] = 0;
	queue<int> q;
	q.push(start_v);
	while (!q.empty()) {
		int now_v = q.front();
		q.pop();
		for (auto& next : tree[now_v]) {
			auto [next_v, next_c] = next;
			if (dis[next_v] == INF) {
				if (next_v == end_v) {
					cout << dis[now_v] + next_c << endl;
					return;
				}
				q.push(next_v);
				dis[next_v] = dis[now_v] + next_c;
			}
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	
	tree.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		tree[u].push_back({ v, c });
		tree[v].push_back({ u, c });
	}

	while (M--) {
		int u, v;
		cin >> u >> v; 
		bfs(u, v);
	}

}
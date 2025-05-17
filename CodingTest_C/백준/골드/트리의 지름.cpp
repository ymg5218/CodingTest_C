// 1167

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int farest;
int max_len = -1;

void dfs(int now_v, int total_len) {
	if (max_len < total_len) {
		max_len = total_len;
		farest = now_v;
	}
	for (auto& next : graph[now_v]) {
		int next_v = next.first;
		int next_w = next.second;
		if (!visited[next_v]) {
			visited[next_v] = true;
			dfs(next_v, total_len + next_w);
			visited[next_v] = false;
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	graph.resize(N + 1);
	visited.resize(N + 1);
	
	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		while (true) {
			int u, w;
			cin >> u;
			if (u == -1) break;
			cin >> w;
			graph[v].push_back({ u, w });
		}
	}
	
	visited[1] = true;
	dfs(1, 0);
	visited = vector<bool>(N + 1, false);
	max_len = -1;
	visited[farest] = true;
	dfs(farest, 0);
	cout << max_len;
}
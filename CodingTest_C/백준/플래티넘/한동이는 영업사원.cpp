// 8012

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n"

using namespace std;

int n;
int max_depth;
vector<vector<int>> graph;
vector<int> depth;
vector<vector<pair<int, int>>> parent; // {정점 번호, 해당 정점 번호까지의 거리}
vector<bool> visited;

void dfs(int node, int d) {
	depth[node] = d;
	for (int nxt : graph[node]) {
		if (visited[nxt]) continue;
		visited[nxt] = true;
		parent[nxt][0] = {node, 1};
		dfs(nxt, d + 1);
	}
}

void set_connect() {
	for (int p = 1; p <= max_depth; p++) {
		for (int cur = 1; cur <= n; cur++) {
			auto [prev, prev_d] = parent[cur][p - 1];
			if (prev == 0) 
				continue;

			auto [anc, anc_d] = parent[prev][p - 1];
			parent[cur][p] = { anc, anc_d + prev_d };
		}
	}
}

void init() {
	cin >> n;
	max_depth = ceil(log2(n)) + 1;
	graph.assign(n + 1, {});
	depth.assign(n + 1, 0);
	parent.assign(n + 1, vector<pair<int, int>>(max_depth + 1, {0, 0}));
	visited.assign(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;
	parent[1][0] = { 0, 0 };
	dfs(1, 0);
	set_connect();
}

int LCA(int x, int y) {
	if (x == y) return 0;

	if (depth[x] < depth[y]) swap(x, y);
	
	int len = 0;

	for (int i = max_depth - 1; i >= 0; i--) {
		if (depth[x] - depth[y] >= (1 << i)) {
			len += parent[x][i].second;
			x = parent[x][i].first;
		}
	}

	if (x == y) return len;

	for (int i = max_depth - 1; i >= 0; i--) {
		if (parent[x][i].first != parent[y][i].first) {
			len += parent[x][i].second;
			x = parent[x][i].first;

			len += parent[y][i].second;
			y = parent[y][i].first;
		}
	}

	len += parent[x][0].second + parent[y][0].second;
	return len;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	int m;
	cin >> m;
	long long sum = 0;
	int now_v = 1;
	while (m--) {
		int x;
		cin >> x;
		sum += LCA(now_v, x);
		now_v = x;
	}
	cout << sum << endl;
}
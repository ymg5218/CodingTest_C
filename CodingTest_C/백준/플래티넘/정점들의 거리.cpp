// 1761

#include <iostream>
#include <vector>
#include <cmath>

#define endl "\n"

using namespace std;

int N, M;
vector <vector<pair<int, int>>> graph;
vector<vector<int>> parent;
vector<vector<int>> length;
vector<int> depth;
vector<bool> visited;

int max_depth;
int root = 1;

void dfs(int node, int d) {
	depth[node] = d;
	for (int i = 0; i < graph[node].size(); i++) {
		auto [cnode, next_len] = graph[node][i];
		if (visited[cnode]) continue;
		visited[cnode] = true;
		parent[cnode][0] = node;
		length[cnode][0] = next_len;
		dfs(cnode, d + 1);
	}
}

void set_connect() {
	for (int p = 1; p <= max_depth; p++) {
		for (int cur = 1; cur <= N; cur++) {
			int prevParent = parent[cur][p - 1];
			if (prevParent == 0) continue;
			parent[cur][p] = parent[prevParent][p - 1];

			if (parent[prevParent][p - 1] == 0) continue;

			int prevLength = length[cur][p - 1];
			length[cur][p] = prevLength + length[prevParent][p - 1];
		}
	}
}

void init() {
	cin >> N;
	graph.assign(N + 1, {});
	max_depth = ceil(log2(N));
	parent.assign(N + 1, vector<int>(max_depth + 1));
	length.assign(N + 1, vector<int>(max_depth + 1));
	depth.assign(N + 1, 0);
	visited.assign(N + 1, false);
	for (int i = 0; i < N - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}
	parent[1][0] = 0;
	length[1][0] = 0;
	visited[1] = true;
}

int LCA(int xnode, int ynode) {
	if (depth[xnode] < depth[ynode])
		swap(xnode, ynode);

	int lenSum = 0;

	for (int i = max_depth; i >= 0; i--) {
		if (depth[xnode] - depth[ynode] >= (1 << i)) {
			lenSum += length[xnode][i];
			xnode = parent[xnode][i];
		}
	}

	if (xnode == ynode) return lenSum;

	for (int i = max_depth; i >= 0; i--) {
		if (parent[xnode][i] != parent[ynode][i]) {
			lenSum += length[xnode][i];
			xnode = parent[xnode][i];

			lenSum += length[ynode][i];
			ynode = parent[ynode][i];
		}
	}

	lenSum += length[xnode][0] + length[ynode][0];

	return lenSum;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	dfs(1, 0);
	set_connect();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << endl;
	}
}
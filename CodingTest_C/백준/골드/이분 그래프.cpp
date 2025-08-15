// 1707

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define FAST_IO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define UNDEFINED -1
#define RED 0
#define BLACK 1

using namespace std;

struct color {
	int c;
};

vector<vector<int>> graph_init(int V, int E) {
	vector<vector<int>> graph(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	return graph;
}

vector<color> vertex_init(int V) {
	vector<color> vertex_color(V + 1, { UNDEFINED });
	return vertex_color;
}

bool bfs(const vector<vector<int>>& graph, vector<color>& vertex_color, int start_v) {
	queue<int> q;
	vertex_color[start_v].c = RED;
	q.push(start_v);
	
	while (!q.empty()) {
		int now_v = q.front();
		int now_color = vertex_color[now_v].c;
		q.pop();
		for (auto& next_v : graph[now_v]) {
			if (vertex_color[next_v].c == vertex_color[now_v].c) return false;
			else if (vertex_color[next_v].c == UNDEFINED) {
				q.push(next_v);
				vertex_color[next_v].c = vertex_color[now_v].c == RED ? BLACK : RED;
			}
		}
	}
	return true;
}

bool solution() {
	int V, E;
	cin >> V >> E;
	auto graph = graph_init(V, E);
	auto vertex_color = vertex_init(V);
	
	for (int i = 1; i <= V; i++) {
		if (vertex_color[i].c != UNDEFINED) continue;
		bool is_bigraph = bfs(graph, vertex_color, i);
		if (!is_bigraph) return false;
	}
	return true;
}

int main(void) {
	FAST_IO;
	
	int T;
	cin >> T;
	while (T--) {
		if (solution()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

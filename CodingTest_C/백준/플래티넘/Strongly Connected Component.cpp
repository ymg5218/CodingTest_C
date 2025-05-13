// 2150

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<bool> visited;
vector<int> stack;
vector<vector<int>> graph;
vector<int> parent;
vector<vector<int>> result;
int seq = 0;
int dfs(int now_v) {
	stack.push_back(now_v);
	if (parent[now_v] == 0)	parent[now_v] = ++seq;
	int p = parent[now_v];
	for (auto next_v : graph[now_v]) {
		if (visited[next_v]) continue;
		if (parent[next_v] == 0) {
			p = min(p, dfs(next_v));
		}
		else if (!visited[next_v]) {
			p = min(p, parent[next_v]);
		}
	}

	if (p == parent[now_v]) {
		vector<int> SCC;
		while (true) {
			int v = stack.back();
			stack.pop_back();
			SCC.push_back(v);
			visited[v] = true;
			if (v == now_v) break;
		}
		sort(SCC.begin(), SCC.end());
		SCC.push_back(-1);
		result.push_back(SCC);
	}
	return p;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;
	
	graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}
	parent.resize(V + 1, 0);
	//for (int i = 1; i <= V; i++) {
	//	parent[i] = i;
	//}
	visited.resize(V + 1);
	for (int start_v = 1; start_v <= V; start_v++) {
		if (parent[start_v] != 0) continue;
		dfs(start_v);
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (auto v : result[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}
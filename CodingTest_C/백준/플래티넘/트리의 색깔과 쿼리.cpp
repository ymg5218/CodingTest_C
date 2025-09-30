// 17469

#include <iostream>
#include <vector>
#include <unordered_set>
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)

using namespace std;

int N, Q;
vector<int> parent;
vector<int> color;
vector<int> adj;
vector<unordered_set<int>> adj_color;
vector<pair<int, int>> Querys;

void init() {
	cin >> N >> Q;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	adj.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		cin >> adj[i];	// i번 정점의 부모
	}
	color.resize(N + 1);
	adj_color.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> color[i];
		adj_color[i].insert(color[i]);
	}
	Q += (N - 1);
	Querys.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> Querys[i].first >> Querys[i].second;
	}
}

int get_parent(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = get_parent(parent[x]);
}

void set_union(int node, int p_node) {
	int np = get_parent(node);
	int pnp = get_parent(p_node);
	if (np == pnp) return;

	// 항상 np가 더 작은 집합이 되도록
	if (adj_color[np].size() > adj_color[pnp].size())
		swap(np, pnp);

	// 작은 집합(np) -> 큰 집합(pnp)
	parent[np] = pnp;

	for (int c : adj_color[np])
		adj_color[pnp].insert(c);
	adj_color[np].clear();
}

void solution() {
	vector<int> result;
	while(!Querys.empty()) {
		auto [cmd, node] = Querys.back();
		Querys.pop_back();
		if (cmd == 1) {							// node의 원래 부모와 연결을 다시 이음
			int p_node = adj[node];
			set_union(node, p_node);
		}
		else {									// node와 연결된 모든 정점들의 색 종류 출력
			int p_node = get_parent(node);
			result.push_back(adj_color[p_node].size());
		}
	}
	while (!result.empty()) {
		cout << result.back() << endl;
		result.pop_back();
	}
}

int main() {
	FASTIO;
	init();
	solution();
}

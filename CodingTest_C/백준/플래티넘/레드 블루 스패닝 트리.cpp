// 4792

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX_VERTEX_COUNT 1001
#define MAX_EDGE_COUNT 1000 * 999 / 2

using namespace std;

struct Edge {
	int cost, u, v;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
		
	}
};

int n, m, k;
vector<Edge> Edges_minBlue(MAX_EDGE_COUNT);
vector<Edge> Edges_maxBlue(MAX_EDGE_COUNT);
vector<int> parent(MAX_VERTEX_COUNT);


void init() {
	for (int i = 0; i < m; i++) {
		char color; int u, v;
		cin >> color >> u >> v;
		if (color == 'B') {
			Edges_minBlue[i] = { 1, u, v };
			Edges_maxBlue[i] = { 0, u, v };
		}
		else {
			Edges_minBlue[i] = { 0, u, v };
			Edges_maxBlue[i] = { 1, u, v };
		}
	}
	sort(Edges_minBlue.begin(), Edges_minBlue.begin() + m);
	sort(Edges_maxBlue.begin(), Edges_maxBlue.begin() + m);
}

int get_parent(int v) {
	if (parent[v] == v) return v;
	return parent[v] = get_parent(parent[v]);
}

void set_union(int u, int v) {
	int up = get_parent(u);
	int vp = get_parent(v);
	if (up > vp) swap(up, vp);
	parent[vp] = up;
}

int kruskal(vector<Edge> edges) {
	int cost_sum = 0;
	
	for (int i = 0; i < m; i++) {
		auto [cost, u, v] = edges[i];
		if (get_parent(u) != get_parent(v)) {
			set_union(u, v);
			cost_sum += cost;
		}
	}

	return cost_sum;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	while (true) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;
		
		init();

		for (int i = 1; i <= n; i++) 
			parent[i] = i;
		
		int cost_sum;
		cost_sum = kruskal(Edges_minBlue);
		
		int min_blueCnt = cost_sum;

		for (int i = 1; i <= n; i++) 
			parent[i] = i;
		
		cost_sum = kruskal(Edges_maxBlue);
		
		int max_blueCnt = n - 1 - cost_sum;
		
		if (min_blueCnt <= k && k <= max_blueCnt) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
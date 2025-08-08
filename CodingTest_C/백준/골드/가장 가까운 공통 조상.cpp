// 3584

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

vector<int> parent;
vector<vector<int>> children;
vector<int> depth;
int N;


int LCA(int v, int u) {
	int v_depth = depth[v];
	int u_depth = depth[u];
	while (v != u) {
		if (v_depth > u_depth) {
			v = parent[v];
			v_depth = depth[v];
		}
		else {
			u = parent[u];
			u_depth = depth[u];
		}
	}
	return v;
}

int get_root(int v) {
	int pv = v;
	while (parent[pv] != 0) {
		pv = parent[pv];
	}
	parent[pv] = -1;
	return pv;
}

void set_depth(int root) {
	depth[root] = 1;
	queue<pair<int, int>> q;
	q.push({ root, 1 });
	while (!q.empty()) {
		auto [now_v, now_depth] = q.front();
		q.pop();
		for (auto& next_v : children[now_v]) {
			if (depth[next_v] == 0) {
				depth[next_v] = now_depth + 1;
				q.push({ next_v, now_depth + 1 });
			}
		}
	}
}

int main(void){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		
		cin >> N;
		parent.clear();
		parent.resize(N + 1, 0);
		children.clear();
		children.resize(N + 1);
		depth.clear();
		depth.resize(N + 1, 0);

		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
			children[a].push_back(b);
		}
		int root = get_root(1);
		set_depth(root);
		int v, u;
		cin >> v >> u;
		cout << LCA(v, u) << endl;
	}
}
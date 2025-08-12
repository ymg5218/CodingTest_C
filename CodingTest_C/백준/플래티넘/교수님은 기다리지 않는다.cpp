// 3830

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;


vector<int> parent;
vector<ll> dist;

int getParent(int x) {
	if (parent[x] == x) return x;
	int x_p = getParent(parent[x]);
	dist[x] += dist[parent[x]];
	return parent[x] = x_p;
}

void unionParent(int x, int y, int w) {
	int x_p = getParent(x);
	int y_p = getParent(y);
	
	if (x_p != y_p) {
		dist[y_p] = -dist[y] + dist[x] + w;
		parent[y_p] = x_p;
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	while (true) {
		int N, M;
		cin >> N >> M;
		if (N + M == 0) break;

		parent.clear();
		parent.resize(N + 1);
		for (int i = 1; i <= N; i++)
			parent[i] = i;

		dist.clear();
		dist.resize(N + 1, 0);

		while (M--) {
			char cmd;
			int u, v;
			cin >> cmd >> u >> v;
			if (cmd == '!') {
				int w;
				cin >> w;
				unionParent(u, v, w);
			}
			else {
				if (getParent(u) != getParent(v)) cout << "UNKNOWN" << endl;
				else {
					cout << dist[v] - dist[u] << endl;
				}
			}
		}
	}
}
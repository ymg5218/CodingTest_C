// 11438

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<vector<int>> tree;

const int LOG = 17;
int height[100001];
int parent[100001][LOG + 1];
int visited[100001] = { false, };
int N;
int M;

void set_height() {
	height[1] = 1;
	parent[1][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1] = true;

	while (!q.empty()) {
		auto [now_h, now_v] = q.front();
		q.pop();

		for (auto& next_v : tree[now_v]) {
			if (!visited[next_v]) {
				q.push({ now_h + 1, next_v });
				height[next_v] = now_h + 1;
				visited[next_v] = true;
				parent[next_v][0] = now_v;
			}
		}
	}
}

void set_parent() {
	for (int k = 1; k <= LOG; k++) {
		for (int idx = 2; idx <= N; idx++) {
			if (parent[idx][k - 1] != 0) parent[idx][k] = parent[parent[idx][k - 1]][k - 1];
		}
	}
}


void LCA(int x, int y) {
	if (height[x] != height[y]) {
		if (height[x] < height[y])
			swap(x, y);

		int dif = height[x] - height[y];
		int i = 0;
		while (dif > 0) {
			if (dif % 2 == 1) {
				x = parent[x][i];
			}
			dif = dif >> 1;
			i++;
		}
	}
	
	if (x != y) {
		for (int k = LOG; k >= 0; k--) {
			if (parent[x][k] != 0 && parent[x][k] != parent[y][k]) {
				x = parent[x][k];
				y = parent[y][k];
			}

		}
		x = parent[x][0];
	}
	cout << x << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	tree.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	set_height();
	set_parent();

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		LCA(x, y);
	}
}
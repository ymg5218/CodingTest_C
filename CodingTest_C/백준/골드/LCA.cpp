// 11437

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

vector<vector<int>> tree;
int height[50001];
int parent[50001];
int visited[50001] = { false, };

void set_height() {
	height[1] = 1;
	parent[1] = -1;
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
				parent[next_v] = now_v;
			}
		}
	}
}


void LCA(int x, int y) {
	while (true) {
		if (x == y) {
			cout << x << endl;
			break;
		}
		if (height[x] < height[y]) {
			y = parent[y];
		}
		else {
			x = parent[x];
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	tree.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	set_height();

	for (int i = 1; i <= N; i++) {
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		LCA(x, y);
	}
}
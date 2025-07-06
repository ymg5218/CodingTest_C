// 21278

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 987654321

using namespace std;

vector<vector<int>> floyd;
vector<vector<int>> graph;
int N, M;

void compute_floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				floyd[j][i] = floyd[i][j];
			}
		}
	}
}

void solution() {
	int min_v, min_u, min_dis;
	min_dis = INF;
	for (int v = 1; v < N; v++) {
		for (int u = v + 1; u <= N; u++) {
			int dis = 0;
			for (int x = 1; x <= N; x++) {
				dis += min(floyd[v][x], floyd[u][x]);
			}
			if (min_dis > dis) {
				min_dis = dis;
				min_v = v;
				min_u = u;
			}
		}
	}

	cout << min_v << " " << min_u << " " << min_dis << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	floyd.resize(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i <= N; i++) {
		floyd[i][i] = 0;
	}
	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
		floyd[v][u] = 2;
		floyd[u][v] = 2;
	}

	compute_floyd();
	solution();
}
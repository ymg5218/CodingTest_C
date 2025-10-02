// 5719

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)

using namespace std;

int N, M;
int S, D;
vector<vector<pair<int, int>>> graph;
vector<int> SP;
vector<vector<int>> SPlist;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });

}

int main() {
	FASTIO;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) return;
		graph.assign(N, {});
		SPlist.assign(N, {});
		cin >> S >> D;

		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back({ v, p });
		}
	}
}
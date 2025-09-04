// 1504

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define INF 1e9
#define ll long long

using namespace std;

int N, E;
vector<vector<pair<int, int>>> graph;
int v1, v2;


vector<ll> bfs(int s) {
	vector<ll> dis(N + 1, INF);
	queue<int> q;
	q.push(s);
	dis[s] = 0;

	while (!q.empty()) {
		int now_v = q.front();
		q.pop();
		for (const auto& next : graph[now_v]) {
			auto [next_v, d] = next;
			if (dis[next_v] > dis[now_v] + d) {
				dis[next_v] = dis[now_v] + d;
				q.push(next_v);
			}
		}
	}
	return dis;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> E;
	graph.resize(N + 1);
	
	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	cin >> v1 >> v2;
	auto dis_v1 = bfs(v1);
	auto dis_v2 = bfs(v2);
	// 1 -> v1 -> v2 -> N
	ll res1 = dis_v1[1] + dis_v1[v2] + dis_v2[N];
	
	// 1 -> v2 -> v1 -> N
	ll res2 = dis_v2[1] + dis_v2[v1] + dis_v1[N];
	
	ll res = min(res1, res2);
	if (res >= INF) cout << -1;
	else cout << res;
}
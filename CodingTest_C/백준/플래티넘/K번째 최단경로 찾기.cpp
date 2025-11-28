// 1854

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> city;
vector<priority_queue<int>> dist;

void init() {
	cin >> n >> m >> k;
	city.assign(n + 1, {});
	dist.assign(n + 1, {});
	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		city[u].push_back({ t, v });
	}
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	dist[1].push(0);

	while (!pq.empty()) {
		auto [now_time, now_v] = pq.top(); 
		pq.pop();

		for (auto [next_time, next_v] : city[now_v]) {
			next_time += now_time;
			if (dist[next_v].size() < k) {
				dist[next_v].push(next_time);
				pq.push({ next_time, next_v });
			}
			else if (dist[next_v].top() > next_time) {
				dist[next_v].pop();
				dist[next_v].push(next_time);
				pq.push({ next_time, next_v });
			}
		}
	}
}

void solution() {
	dijkstra();
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << -1 << endl;
		else cout << dist[i].top() << endl;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	solution();
}
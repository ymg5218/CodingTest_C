// 10282

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000 * 1000 + 1
#define endl "\n"

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> network, int start_v) {
	/*int max_dis = 0;*/
	int cnt = 0;
	vector<int> distance(network.size(), INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start_v });
	distance[start_v] = 0;
	cnt++;
	while (!pq.empty()) {
		auto [now_dis, now_v] = pq.top();
		now_dis *= -1;
		pq.pop();
		for (auto& [next_v, next_dis] : network[now_v]) {
			if (distance[next_v] == INF) cnt++;
			if (distance[next_v] > distance[now_v] + next_dis) {
				distance[next_v] = distance[now_v] + next_dis;
				pq.push({ -(now_dis + next_dis), next_v });
			}
		}
	}
	
	int max_dis = -1;

	for (auto& d : distance) {
		if (d != INF) {
			max_dis = max(max_dis, d);
		}
	}
	cout << cnt << " " << max_dis << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n, d, c;
		cin >> n >> d >> c;
		vector<vector<pair<int, int>>> network(10001);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			network[b].push_back({ a, s });
		}
		dijkstra(network, c);
	}
}
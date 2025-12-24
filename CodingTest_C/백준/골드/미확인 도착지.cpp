// 9370

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h;
vector<vector<pair<int, int>>> graph;	// {이어진 정점, 정점 사이의 거리}
vector<int> s_dist;
vector<int> e_cand;
vector<int> g_dist;
vector<int> h_dist;
int s_to_g;
int s_to_h;
int g_h_dist;

vector<int> dijkstra(int x) {
	vector<int> dist(n + 1, INF);
	dist[x] = 0;
	priority_queue<int> pq;
	for (auto& [next_v, next_dis] : graph[x]) {
		dist[next_v] = next_dis;
		pq.push(next_v);
	}
	
	while (!pq.empty()) {
		int now_v = pq.top();
		pq.pop();
		for (auto& [next_v, next_dis] : graph[now_v]) {
			if (dist[next_v] <= dist[now_v] + next_dis) continue;
			dist[next_v] = dist[now_v] + next_dis;
			pq.push(next_v);
		}
	}
	return dist;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		graph.assign(n + 1, {});	// 그래프 사이즈 초기화
		cin >> s >> g >> h;
		if (g > h) swap(g, h);
		while (m--) {
			int a, b, d;
			cin >> a >> b >> d;
			graph[a].push_back({ b, d });
			graph[b].push_back({ a, d });
			if (a > b) swap(a, b);
			if (a == g && b == h) g_h_dist = d;
		}
		e_cand.clear();
		while (t--) {
			int e;
			cin >> e;
			e_cand.push_back(e);
		}
		sort(e_cand.begin(), e_cand.end());

		s_dist = dijkstra(s);
		g_dist = dijkstra(g);
		h_dist = dijkstra(h);
		s_to_g = s_dist[g];
		s_to_h = s_dist[h];
		
		for (auto& e : e_cand) {
			if (min(s_to_g + g_h_dist + h_dist[e], s_to_h + g_h_dist + g_dist[e]) <= s_dist[e])
				cout << e << " ";
		}
		cout << endl;
	}
}
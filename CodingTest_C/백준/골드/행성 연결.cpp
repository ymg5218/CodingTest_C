// 16398

#include <iostream>
#include <vector>
#include <queue>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"
#define ll long long

using namespace std;

int N;
vector<vector<ll>> graph;
vector<bool> is_mst;
int is_mst_cnt = 0;

void init() {
	cin >> N;
	graph.assign(N, vector<ll>(N, 0));
	is_mst.assign(N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
}

ll prim() {
	ll result = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty() || is_mst_cnt < N) {
		auto [now_dis, now_v] = pq.top();
		pq.pop();
		if (is_mst[now_v]) continue;
		result += now_dis;
		is_mst_cnt++;
		is_mst[now_v] = true;
		for (int next_v = 0; next_v < N; next_v++) {
			if (next_v != now_v && !is_mst[next_v]) {
				pq.push({ graph[now_v][next_v], next_v });
			}
		}
	}

	return result;
}

int main() {
	FASTIO;
	init();
	cout << prim() << endl;
}

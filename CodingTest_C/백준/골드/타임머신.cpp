// 11657

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

const int INF = 1 << 30;

vector<vector<pair<int, int>>> graph;
vector<int> d;
vector<bool> inq;
vector<int> cnt;
int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	graph.resize(N + 1);
	d.resize(N + 1, 0);
	inq.resize(N + 1, false);
	cnt.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int v1, v2, dis;
		cin >> v1 >> v2 >> dis;
		graph[v1].emplace_back(make_pair( v2, dis ));
	}

	queue<int> q;
	q.push(1);
	inq[1] = true;
	while (!q.empty()) {
		int now_v = q.front();
		q.pop();
		inq[now_v] = false;
		if (++cnt[now_v] >= N || d[now_v] < -INF) {
			cout << -1 << endl;
			return 0;
		}
		for (auto n : graph[now_v]) {
			int next_v = n.first;
			int dis = n.second;
			if (d[now_v] + dis < d[next_v]) {
				d[next_v] = d[now_v] + dis;
				if (!inq[next_v]) {
					q.push(next_v);
					inq[next_v] = true;
				}
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << (d[i] == INF ? -1 : d[i]) << endl;
	}
}
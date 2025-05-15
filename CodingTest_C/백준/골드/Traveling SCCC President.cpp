// 28119

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> meeting;
vector<bool> isMST;
int isMSTcnt;

void Prim(int start) {
	// min-heap
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	int min_dis = 0;
	
	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		int now_v = now.second;
		if (isMST[now_v]) continue;
		isMST[now_v] = true;
		isMSTcnt--;
		min_dis += -now.first;
		if (isMSTcnt <= 0) {
			break;
		}
		for (auto n : graph[now_v]) {
			int next_v = n.first;
			if (isMST[next_v]) continue;
			int weight = n.second;
			pq.push({ -weight, next_v });
		}
	}
	cout << min_dis;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M, S;
	cin >> N >> M >> S;
	graph.resize(N + 1);
	isMST.resize(N + 1, false);
	isMSTcnt = N;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[v].push_back({ u, w });
		graph[u].push_back({ v, w });
	}
	
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		meeting.push_back(a);
	}
	Prim(S);
}
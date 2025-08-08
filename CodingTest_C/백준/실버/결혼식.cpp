// 5567

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

vector<vector<int>> net;
vector<bool> visited;
int N, M;

int bfs() {
	queue<pair<int, int>> q;
	q.push({1, 0});    //  {사람 번호, 본인 (= 0) or 친구 (= 1) or 친구의 친구 (= 2)}
	visited[1] = true;
	
	int cnt = 0;
	while (!q.empty()) {
		auto[now_v, dis] = q.front();
		q.pop();
		for (auto& next_v : net[now_v]) {
			if (!visited[next_v]) {
				visited[next_v] = true;
				if (dis + 1 < 2)
					q.push({ next_v, dis + 1 });
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	net.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		net[u].push_back(v);
		net[v].push_back(u);
	}

	cout << bfs() << endl;;
}
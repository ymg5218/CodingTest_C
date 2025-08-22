// 1516

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<int> t;
vector<int> total_time;
vector<int> in_degree; // 진입 차수
vector<vector<int>> graph;

void init() {
	t.assign(N + 1, 0);
	total_time.assign(N + 1, 0);
	in_degree.assign(N + 1, 0);
	graph.assign(N + 1, {});

	for (int i = 1; i <= N; i++){
		while (true) {
			int x;
			cin >> x;
			if (x == -1) break;
			if (t[i] == 0) t[i] = x;
			else {
				graph[x].push_back(i);
				in_degree[i]++;
			}
		}
	}
}

void solution() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push({i, t[i]});
			total_time[i] = t[i];
		}
			
	}
	
	while (!q.empty()) {
		auto [now_v, now_time] = q.front();
		q.pop();
		
		for (auto& next_v : graph[now_v]) {
			in_degree[next_v]--;
			total_time[next_v] = max(total_time[next_v], now_time + t[next_v]);
			if (in_degree[next_v] == 0) 
				q.push({ next_v, total_time[next_v] });
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	
	init();

	solution();

	for (int i = 1; i <= N; i++) {
		cout << total_time[i] << endl;
	}
}
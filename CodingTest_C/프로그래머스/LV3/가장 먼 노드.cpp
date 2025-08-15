#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define endl "\n"

using namespace std;

vector<vector<int>> init(int n, vector<vector<int>> edge) {
	vector<vector<int>> graph(n + 1);

	for (auto e : edge) {
		int u = 0, v = 0;
		u = e[0];
		v = e[1];

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	return graph;
}

int bfs(int n, vector<vector<int>> graph, int start_v) {
	int far_len = 0;
	int cnt = 0;

	queue<int> q;
	q.push(1);
	vector<int> dist(n + 1, INF);
	dist[1] = 0;

	while (!q.empty()) {
		int now_v = q.front();
		q.pop();
		
		for (auto next_v : graph[now_v]) {
			if (dist[next_v] > dist[now_v] + 1) {
				q.push(next_v);
				dist[next_v] = dist[now_v] + 1;
				if (far_len < dist[next_v]) {
					cnt = 1;
					far_len = dist[next_v];
				}
				else if (far_len == dist[next_v])
					cnt++;
			}
		}
	}

	return cnt;
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	auto graph = init(n, edge);
	answer = bfs(n, graph, 1);

	return answer;
}

int main(void) {
	int n = 6;
	vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };
	
	cout << solution(n, edge) << endl;
}
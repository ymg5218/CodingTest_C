// 9372

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, int M) {
	vector<int> graph[1001];
	bool visited[1001]{ false };
	queue<int> q;
	int cnt = 0;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	q.push(1);
	visited[1] = true;
	int now_v, next_v;
	while (!q.empty()) {
		now_v = q.front();
		q.pop();
		for (int idx = 0; idx < graph[now_v].size(); idx++) {
			next_v = graph[now_v][idx];
			if (!visited[next_v]) {
				q.push(next_v);
				cnt++;
				visited[next_v] = true;
			}
		}
	}

	return cnt;

}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int T;
	cin >> T;
	
	int N, M;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << solution(N, M) << '\n';
	}
}
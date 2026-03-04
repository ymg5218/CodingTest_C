// 12851

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1e9
#define endl "\n"

using namespace std;

vector<int> visited(200000, MAX);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, K; cin >> N >> K;

	int cnt = -1;
	int method_cnt = 0;

	queue<int> q; q.push(N);
	visited[N] = 0;
	while (!q.empty()) {
		auto now_n = q.front(); q.pop();
		if (now_n == K) {
			if (cnt == -1) {
				cnt = visited[now_n];
				method_cnt = 1;
			}
			else {
				if (cnt == visited[now_n]) method_cnt++;
				else if (cnt > visited[now_n]) {
					cnt = visited[now_n];
					method_cnt = 1;
				}
			}
		}
		else {
			if (cnt != -1 && visited[now_n] >= cnt) continue;
			if (now_n - 1 >= 0 && visited[now_n - 1] >= visited[now_n] + 1) {
				q.push(now_n - 1);
				visited[now_n - 1] = visited[now_n] + 1;
			}
			if (now_n < K && visited[now_n + 1] >= visited[now_n] + 1) {
				q.push(now_n + 1);
				visited[now_n + 1] = visited[now_n] + 1;
			}
				
			if (now_n < K && visited[now_n * 2] >= visited[now_n] + 1) {
				q.push(now_n * 2);
				visited[now_n * 2] = visited[now_n] + 1;
			}
				
		}
	}
	cout << cnt << endl << method_cnt;
	
}
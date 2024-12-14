// 2206

#include <iostream>
#include <string>
#include <queue>
using namespace std;

// row, col
int graph[1000][1000];
// [row][col][0] = 벽을 부수지 않으면서 [row][col]까지 도달
// [row][col][1] = 벽을 한 번 부수면서 [row][col]까지 최단거리
int dist[1000][1000][2];

int bfs(int N, int M) {
	// 동 남 서 북
	int d_row[4] = { 0, 1, 0, -1 };
	int d_col[4] = { 1, 0, -1, 0 };

	// { {row, col}, is_broken }
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;

	int now_row, now_col, is_broken;
	int next_row, next_col;
	while (!q.empty()) {
		now_row = q.front().first.first;
		now_col = q.front().first.second;
		is_broken = q.front().second;
		q.pop();

		if (now_row == N - 1 and now_col == M - 1) {
			return dist[now_row][now_col][is_broken];
		}

		for (int i = 0; i < 4; i++) {
			next_row = now_row + d_row[i];
			next_col = now_col + d_col[i];
			
			// 유효한 좌표인 경우
			if (0 <= next_row and next_row < N and 0 <= next_col and next_col < M) {
				// 벽이 없고, 아직 방문하지 않은 경우
				if (graph[next_row][next_col] == 0 and dist[next_row][next_col][is_broken] == 0) {
					dist[next_row][next_col][is_broken] = dist[now_row][now_col][is_broken] + 1;
					q.push({ {next_row, next_col}, is_broken });
				}

				// 벽이 있고, 아직까지 벽을 부순 적이 없는 경우
				else if (graph[next_row][next_col] == 1 and is_broken == 0) {
					dist[next_row][next_col][1] = dist[now_row][now_col][is_broken] + 1;
					q.push({ {next_row, next_col}, 1 });
				}
			}
		}
	}


	return -1;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M;
	cin >> N >> M;

	string now_row;
	for (int row = 0; row < N; row++) {
		cin >> now_row;
		for (int col = 0; col < M; col++) {
			graph[row][col] = int(now_row[col]) - int('0');
		}
	}
	
	cout << bfs(N, M);
	
}
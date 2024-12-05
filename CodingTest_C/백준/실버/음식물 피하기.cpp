// 1743

#include <iostream>
#include <queue>
#include <array>
using namespace std;

int bfs(int** graph, int N, int M) {
	// µ¿ ³² ¼­ ºÏ
	int d_row[] = { 0, 1, 0, -1 };
	int d_col[] = { 1, 0, -1, 0 };
	queue<pair<int, int>> q;
	int now_row, now_col;
	int next_row, next_col;
	int now_size, max_size;
	max_size = 0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (graph[row][col] == 1) {
				q.push(make_pair(row, col));
				graph[row][col] = 0;
				now_size = 0;
				while (!q.empty()) {
					now_row = q.front().first;
					now_col = q.front().second;
					q.pop();
					now_size++;
					for (int i = 0; i < 4; i++) {
						next_row = now_row + d_row[i];
						next_col = now_col + d_col[i];
						if (0 <= next_row and next_row < N and 0 <= next_col and next_col < M) {
							if (graph[next_row][next_col] == 1) {
								q.push(make_pair(next_row, next_col));
								graph[next_row][next_col] = 0;
							}
						}
					}
				}
				max_size = max(max_size, now_size);
			}
		}
	}

	return max_size;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int** graph;
	graph = new int* [N];
	
	for (int i = 0; i < N; i++) {
		graph[i] = new int [M] {0};
	}
	int row, col;
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		graph[row - 1][col - 1] = 1;
	}

	cout << bfs(graph, N, M);
	
	delete[] graph;
}

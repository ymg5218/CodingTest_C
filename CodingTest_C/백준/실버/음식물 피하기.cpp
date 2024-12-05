// 1743

#include <iostream>
#include <queue>
#include <array>
using namespace std;

void bfs(int** graph, bool** visited, int N, int M) {
	// µ¿ ³² ¼­ ºÏ
	int d_row[] = { 0, 1, 0, -1 };
	int d_col[] = { 1, 0, -1, 0 };
	queue<array<int, 2>> queue;
	int now_row, now_col;
	int next_row, next_col;
	int now_size, max_size;
	max_size = 0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (graph[row][col] == 1 and !visited[row][col]) {
				queue.push({row, col});
				visited[row][col] = true;
				now_size = 0;
				while (!queue.empty()) {
					now_row = queue.front()[0];
					now_col = queue.front()[1];
					queue.pop();
					now_size++;
					for (int i = 0; i < 4; i++) {
						next_row = now_row + d_row[i];
						next_col = now_col + d_col[i];
						if (0 <= next_row and next_row < N and 0 <= next_col and next_row < M) {
							if (graph[next_row][next_col] == 1 and !visited[next_row][next_col]) {
								queue.push({next_row, next_col});
								visited[next_row][next_col] = true;
							}
						}
					}
				}
				max_size = max(max_size, now_size);
			}
		}
	}

	cout << max_size;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int** graph;
	graph = new int*[N];
	bool** visited;
	visited = new bool* [N];
	
	for (int i = 0; i < M; i++) {
		graph[i] = new int[M] {0};
		visited[i] = new bool[M] {false};
	}
	int row, col;
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		graph[row - 1][col - 1] = 1;
	}

	bfs(graph, visited, N, M);
}

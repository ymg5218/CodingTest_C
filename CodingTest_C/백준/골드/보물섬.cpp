// 2589

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;

int d_row[] = { 0, 1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };

bool is_valid(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= M) return false;
	if (board[row][col] == 'W') return false;
	if (visited[row][col]) return false;
	return true;
}

int bfs(int start_row, int start_col) {
	int max_dis = 0;
	queue<tuple<int, int, int>> q;	// {row, col, now_dis}
	q.push({ start_row, start_col, 0 });
	visited[start_row][start_col] = true;
	while (!q.empty()){
		auto [now_row, now_col, now_dis] = q.front();
		q.pop();
		max_dis = max(max_dis, now_dis);
		for (int i = 0; i < 4; i++) {
			int next_row = now_row + d_row[i];
			int next_col = now_col + d_col[i];
			if (is_valid(next_row, next_col)) {
				visited[next_row][next_col] = true;
				q.push({ next_row, next_col, now_dis + 1 });
			}
		}
	}
	return max_dis;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> N >> M;
	board.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int max_dis = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (board[row][col] == 'L') {
				visited.assign(N, vector<bool>(M, false));
				int dis = bfs(row, col);
				max_dis = max(max_dis, dis);
			}
		}
	}

	cout << max_dis;
}
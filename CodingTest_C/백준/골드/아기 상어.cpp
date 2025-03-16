// 16236

#include <iostream>
#include <queue>

using namespace std;

int board[20][20];
int N;
int now_row, now_col;
int now_size = 2;
int eat_cnt = 0;
int result_time = 0;
queue<pair<int, int>> q;

// ºÏ ¼­ ³² µ¿
int d_row[] = { -1, 0, 1, 0 };
int d_col[] = { 0, -1, 0, 1 };

bool is_valid(int row, int col) {
	if (0 <= row and row < N and 0 <= col and col < N) {
		if (board[row][col] <= now_size) {
			return true;
		}
	}
	return false;
}

void bfs() {
	int r, c;
	int next_r = N;
	int next_c = N;
	queue<pair<int, int>> next_q;
	int move_time = 0;

	bool visited[20][20] = { false };
	while (!q.empty()) {
		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;
			visited[r][c] = true;
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (is_valid(r + d_row[i], c + d_col[i]) and visited[r + d_row[i]][c + d_col[i]] == false) {
					next_q.push({ r + d_row[i], c + d_col[i] });
					visited[r + d_row[i]][c + d_col[i]] = true;
					if (0 < board[r + d_row[i]][c + d_col[i]] and board[r + d_row[i]][c + d_col[i]] < now_size) {
						if (next_r > r + d_row[i]) {
							next_r = r + d_row[i];
							next_c = c + d_col[i];
						}
						else if (next_r == r + d_row[i]) {
							if (next_c > c + d_col[i]) {
								next_r = r + d_row[i];
								next_c = c + d_col[i];
							}
						}
					}
				}
			}
		}
		move_time++;
		if (next_r < N) {
			now_row = next_r;
			now_col = next_c;
			result_time += move_time;
			return;
		}

		while (!next_q.empty()) {
			q.push({ next_q.front().first, next_q.front().second });
			next_q.pop();
		}
	}

	now_row = -1;
	return;
}

void solution() {

	while (true) {
		while (!q.empty()) {
			q.pop();
		}
		q.push({ now_row, now_col });
		bfs();
		if (now_row == -1) {
			cout << result_time;
			return;
		}

		// ³È³È
		board[now_row][now_col] = 0;
		eat_cnt++;
		if (now_size == eat_cnt) {
			now_size++;
			eat_cnt = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL); cin.sync_with_stdio(NULL);
	
	cin >> N;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> board[row][col];
			if (board[row][col] == 9) {
				now_row = row;
				now_col = col;
				board[row][col] = 0;
			}
		}
	}

	solution();
}
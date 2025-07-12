// 17070

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl "\n"

using namespace std;

int N;
vector<vector<int>> board;


void bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 1, 0}); // 0 : 가로, 1 : 대각선, 2 : 세로

	// 가로 1칸, 대각선 1칸, 세로 1칸
	int d_row[] = { 0, 1, 1 };
	int d_col[] = { 1, 1, 0 };

	int cnt = 0;

	while (!q.empty()){
		int now_row, now_col, now_dir;
		tie(now_row, now_col, now_dir) = q.front();
		q.pop();

		if (now_row == N - 1 && now_col == N - 1)
			cnt++;
		
		int next_row, next_col, next_dir;
		if (now_dir == 0) {
			for (int i = 0; i < 2; i++) {
				next_row = now_row + d_row[i];
				next_col = now_col + d_col[i];
				next_dir = i;
				if (next_row >= N || next_col >= N || board[next_row][next_col] == 1)
					continue;
				if (i == 1) {
					if (board[next_row][now_col] == 1 || board[now_row][next_col] == 1)
						continue;
				}
				q.push({ next_row, next_col, i });
			}
		}
		else if (now_dir == 1) {
			for (int i = 0; i < 3; i++) {
				next_row = now_row + d_row[i];
				next_col = now_col + d_col[i];
				next_dir = i;
				if (next_row >= N || next_col >= N || board[next_row][next_col] == 1)
					continue;
				if (i == 1) {
					if (board[next_row][now_col] == 1 || board[now_row][next_col] == 1)
						continue;
				}
				q.push({ next_row, next_col, i });
			}
		}
		else {
			for (int i = 1; i < 3; i++) {
				next_row = now_row + d_row[i];
				next_col = now_col + d_col[i];
				next_dir = i;
				if (next_row >= N || next_col >= N || board[next_row][next_col] == 1)
					continue;
				if (i == 1) {
					if (board[next_row][now_col] == 1 || board[now_row][next_col] == 1)
						continue;
				}
				q.push({ next_row, next_col, i });
			}
		}
	}

	cout << cnt;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N;
	board.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n == 1)
				board[i][j] = 1;
		}
	}

	bfs();

}
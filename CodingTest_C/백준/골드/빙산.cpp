// 2573

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int board[300][300];
int N, M;

struct P {
	int row, col;
	P(int row, int col) : row(row), col(col) {}
};

struct melt_P {
	int row, col;
	int adjcnt;
	melt_P(int row, int col, int adjcnt) : row(row), col(col), adjcnt(adjcnt) {}
};

int bfs() {
	bool visited[300][300] = { false, };
	vector<melt_P> will_melt;
	int d_row[] = { 0, 1, 0, -1 };
	int d_col[] = { 1, 0, -1, 0 };

	int land = 0;
	bool is_empty = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && board[i][j]) {
				is_empty = false;
				queue<P> q;
				q.push(P(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					P now = q.front();
					q.pop();
					int now_row = now.row;
					int now_col = now.col;
					int adj_zero = 0;
					for (int i = 0; i < 4; i++) {
						int next_row = now_row + d_row[i];
						int next_col = now_col + d_col[i];
						if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M)
							continue;
						if (visited[next_row][next_col])
							continue;
						if (board[next_row][next_col] == 0)
							adj_zero++;
						else{
						q.push(P(next_row, next_col));
						visited[next_row][next_col] = true;
						}
					}

					if (adj_zero > 0)
						will_melt.push_back(melt_P(now_row, now_col, adj_zero));
				}
				land++;
			}
		}
	}

	if (is_empty)
		return -1;

	for (auto& p : will_melt) {
		int row = p.row;
		int col = p.col;
		int adjcnt = p.adjcnt;
		board[row][col] = board[row][col] - adjcnt <= 0 ? 0 : board[row][col] - adjcnt;
	}
	return land;
}

void solution() {
	int year = 0;
	
	while (true) {
		int res = bfs();
		if (res == -1) {
			cout << 0 << endl;
			return;
		}
		if (res >= 2)
			break;
		year++;
	}

	cout << year;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];
	}
	
	solution();
}
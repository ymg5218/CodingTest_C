// 13460

#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int N, M;
vector<vector<char>> board;
int R_row, R_col, B_row, B_col;
int end_row, end_col;

struct NowState{
	int R_row, R_col, B_row, B_col;
	int cnt;
};

void init() {
	cin >> N >> M;
	board.assign(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				R_row = i;
				R_col = j;
			}
			if (board[i][j] == 'B') {
				B_row = i;
				B_col = j;
			}
			if (board[i][j] == 'O') {
				end_row = i;
				end_col = j;
			}
		}
	}
}

NowState goUp(NowState& now) {	// 위로
	NowState next;

	auto [nR_row, nR_col, nB_row, nB_col, nCnt] = now;
	int nxR_row, nxR_col, nxB_row, nxB_col, nxCnt;

	// B구슬의 도착지 -> row만 1씩 줄어듬
	for (int row = nB_row - 1; row >= 0; row--) {
		if (row == end_row && nB_col == end_col) {
			next.cnt = -1;
			return next;
		}
		if (board[row][nB_col] == '#') {
			nxB_row = row + 1;
			break;
		}
		nxB_row = row;
	}
	nxB_col = nB_col;

	// R구슬의 도착지 -> row만 1씩 줄어듬
	for (int row = nR_row - 1; row >= 0; row--) {
		if (row == end_row && nR_col == end_col) {
			next.cnt = 0;
			return next;
		}
		if (nCnt == 10) {
			next.cnt = -1;
			return next;
		}
		if (board[row][nR_col] == '#') {
			nxR_row = row + 1;
			break;
		}
		nxR_row = row;
	}
	nxR_col = nR_col;

	if (nxR_row == nxB_row && nxR_col == nxB_col) {
		if (nR_row > nB_row) {
			nxR_row++;
		}
		else {
			nxB_row++;
		}
	}
	next = { nxR_row, nxR_col, nxB_row, nxB_col, nCnt + 1 };
	return next;
}

NowState goDown(NowState& now) {	// 아래로
	NowState next;

	auto [nR_row, nR_col, nB_row, nB_col, nCnt] = now;
	int nxR_row, nxR_col, nxB_row, nxB_col, nxCnt;

	// B구슬의 도착지 -> row만 1씩 늘어남
	for (int row = nB_row + 1; row < N; row++) {
		if (row == end_row && nB_col == end_col) {
			next.cnt = -1;
			return next;
		}
		if (board[row][nB_col] == '#') {
			nxB_row = row - 1;
			break;
		}
		nxB_row = row;
	}
	nxB_col = nB_col;

	// R구슬의 도착지 -> row만 1씩 늘어남
	for (int row = nR_row + 1; row < N; row++) {
		if (row == end_row && nR_col == end_col) {
			next.cnt = 0;
			return next;
		}
		if (nCnt == 10) {
			next.cnt = -1;
			return next;
		}
		if (board[row][nR_col] == '#') {
			nxR_row = row - 1;
			break;
		}
		nxR_row = row;
	}
	nxR_col = nR_col;

	if (nxR_row == nxB_row && nxR_col == nxB_col) {
		if (nR_row < nB_row) {
			nxR_row--;
		}
		else {
			nxB_row--;
		}
	}
	next = { nxR_row, nxR_col, nxB_row, nxB_col, nCnt + 1 };
	return next;
}

NowState goLeft(NowState& now) {	// 왼쪽으로
	NowState next;

	auto [nR_row, nR_col, nB_row, nB_col, nCnt] = now;
	int nxR_row, nxR_col, nxB_row, nxB_col, nxCnt;

	// B구슬의 도착지 -> col만 1씩 줄어듬
	for (int col = nB_col - 1; col >= 0; col--) {
		if (nB_row == end_row && col == end_col) {
			next.cnt = -1;
			return next;
		}
		if (board[nB_row][col] == '#') {
			nxB_col = col + 1;
			break;
		}
		nxB_col = col;
	}
	nxB_row = nB_row;

	// R구슬의 도착지 -> col만 1씩 줄어듬
	for (int col = nR_col - 1; col >= 0; col--) {
		if (nR_row == end_row && col == end_col) {
			next.cnt = 0;
			return next;
		}
		if (nCnt == 10) {
			next.cnt = -1;
			return next;
		}
		if (board[nR_row][col] == '#') {
			nxR_col = col + 1;
			break;
		}
		nxR_col = col;
	}
	nxR_row = nR_row;

	if (nxR_row == nxB_row && nxR_col == nxB_col) {
		if (nR_col < nB_col) {
			nxB_col++;
		}
		else {
			nxR_col++;
		}
	}
	next = { nxR_row, nxR_col, nxB_row, nxB_col, nCnt + 1 };
	return next;
}

NowState goRight(NowState& now) {	// 오른쪽으로
	NowState next;

	auto [nR_row, nR_col, nB_row, nB_col, nCnt] = now;
	int nxR_row, nxR_col, nxB_row, nxB_col, nxCnt;

	// B구슬의 도착지 -> col만 1씩 늘어남
	for (int col = nB_col + 1; col < M; col++) {
		if (nB_row == end_row && col == end_col) {
			next.cnt = -1;
			return next;
		}
		if (board[nB_row][col] == '#') {
			nxB_col = col - 1;
			break;
		}
		nxB_col = col;
	}
	nxB_row = nB_row;

	// R구슬의 도착지 -> col만 1씩 늘어남
	for (int col = nR_col + 1; col < M; col++) {
		if (nR_row == end_row && col == end_col) {
			next.cnt = 0;
			return next;
		}
		if (nCnt == 10) {
			next.cnt = -1;
			return next;
		}
		if (board[nR_row][col] == '#') {
			nxR_col = col - 1;
			break;
		}
		nxR_col = col;
	}
	nxR_row = nR_row;

	if (nxR_row == nxB_row && nxR_col == nxB_col) {
		if (nR_col > nB_col) {
			nxB_col--;
		}
		else {
			nxR_col--;
		}
	}
	next = { nxR_row, nxR_col, nxB_row, nxB_col, nCnt + 1 };
	return next;
}

void bfs() {
	queue<NowState> q;
	q.push({ R_row, R_col, B_row, B_col, 0 });

	while (!q.empty()) {
		NowState now = q.front();
		q.pop();
		NowState next;
		// 위로
		next = goUp(now);
		if (next.cnt == 0) {
			cout << now.cnt + 1 << endl;
			return;
		}
		if (next.cnt != -1) {
			q.push(next);
		}

		// 아래로
		next = goDown(now);
		if (next.cnt == 0) {
			cout << now.cnt + 1 << endl;
			return;
		}
		if(next.cnt != -1) {
			q.push(next);
		}

		// 왼쪽으로
		next = goLeft(now);
		if (next.cnt == 0) {
			cout << now.cnt + 1 << endl;
			return;
		}
		if (next.cnt != -1) {
			q.push(next);
		}

		// 오른쪽으로
		next = goRight(now);
		if (next.cnt == 0) {
			cout << now.cnt + 1 << endl;
			return;
		}
		if (next.cnt != -1) {
			q.push(next);
		}
	}

	cout << -1 << endl;
	return;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	bfs();
}
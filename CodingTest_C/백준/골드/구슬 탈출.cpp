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

void bfs() {
	
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	bfs();
}
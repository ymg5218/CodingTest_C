// 1520

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> dp;

int d_row[] = { 0, -1, 0, 1 };
int d_col[] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + d_row[i];
			int ny = y + d_col[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] < board[x][y])
				dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

void solution() {
	cout << dfs(0, 0) << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	// NÇà M¿­
	cin >> N >> M;

	board.resize(N, vector<int>(M));
	dp.resize(N, vector<int>(M));

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
			dp[row][col] = -1;
		}
	}

	solution();

}
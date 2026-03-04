// 3109

#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<string> board;
vector<vector<bool>> visited;
int dr[] = { -1, 0, 1 };
int dc[] = { 1, 1, 1 };

bool dfs(int r, int c) {
    visited[r][c] = true;

    if (c == C - 1) 
		return true;

    for (int i = 0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc < C) {
            if (board[nr][nc] == '.' && !visited[nr][nc]) {
                if (dfs(nr, nc)) 
					return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> R >> C;
    board.resize(R);
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) cin >> board[i];

    int cnt = 0;
    for (int i = 0; i < R; i++) {
        if (dfs(i, 0)) cnt++;
    }

    cout << cnt;
    return 0;
}
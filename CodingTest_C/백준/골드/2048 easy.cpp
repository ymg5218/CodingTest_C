#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int max_block = 0;

void move(vector<vector<int>>& board, int dir) {
    vector<vector<bool>> merged(N, vector<bool>(N, false));

    if (dir == 0) { // Up
        for (int col = 0; col < N; ++col) {
            for (int row = 1; row < N; ++row) {
                if (board[row][col] == 0) continue;
                int nr = row;
                while (nr > 0 && board[nr - 1][col] == 0) {
                    board[nr - 1][col] = board[nr][col];
                    board[nr][col] = 0;
                    nr--;
                }
                if (nr > 0 && board[nr - 1][col] == board[nr][col] && !merged[nr - 1][col]) {
                    board[nr - 1][col] *= 2;
                    board[nr][col] = 0;
                    merged[nr - 1][col] = true;
                }
            }
        }
    }
    else if (dir == 1) { // Down
        for (int col = 0; col < N; ++col) {
            for (int row = N - 2; row >= 0; --row) {
                if (board[row][col] == 0) continue;
                int nr = row;
                while (nr < N - 1 && board[nr + 1][col] == 0) {
                    board[nr + 1][col] = board[nr][col];
                    board[nr][col] = 0;
                    nr++;
                }
                if (nr < N - 1 && board[nr + 1][col] == board[nr][col] && !merged[nr + 1][col]) {
                    board[nr + 1][col] *= 2;
                    board[nr][col] = 0;
                    merged[nr + 1][col] = true;
                }
            }
        }
    }
    else if (dir == 2) { // Left
        for (int row = 0; row < N; ++row) {
            for (int col = 1; col < N; ++col) {
                if (board[row][col] == 0) continue;
                int nc = col;
                while (nc > 0 && board[row][nc - 1] == 0) {
                    board[row][nc - 1] = board[row][nc];
                    board[row][nc] = 0;
                    nc--;
                }
                if (nc > 0 && board[row][nc - 1] == board[row][nc] && !merged[row][nc - 1]) {
                    board[row][nc - 1] *= 2;
                    board[row][nc] = 0;
                    merged[row][nc - 1] = true;
                }
            }
        }
    }
    else if (dir == 3) { // Right
        for (int row = 0; row < N; ++row) {
            for (int col = N - 2; col >= 0; --col) {
                if (board[row][col] == 0) continue;
                int nc = col;
                while (nc < N - 1 && board[row][nc + 1] == 0) {
                    board[row][nc + 1] = board[row][nc];
                    board[row][nc] = 0;
                    nc++;
                }
                if (nc < N - 1 && board[row][nc + 1] == board[row][nc] && !merged[row][nc + 1]) {
                    board[row][nc + 1] *= 2;
                    board[row][nc] = 0;
                    merged[row][nc + 1] = true;
                }
            }
        }
    }
}

void dfs(vector<vector<int>> board, int depth) {
    if (depth == 5) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                max_block = max(max_block, board[i][j]);
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        vector<vector<int>> new_board = board;
        move(new_board, dir);
        dfs(new_board, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    dfs(board, 0);
    cout << max_block << "\n";
    return 0;
}

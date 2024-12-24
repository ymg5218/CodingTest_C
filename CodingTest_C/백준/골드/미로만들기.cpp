// 2665

#include <iostream>
#include <string>
#include <queue>
#define INF 2501
using namespace std;

string room[50];
bool visited[50][50]{ false };
int broken[50][50];
queue<pair<int, int>> q;

// ºÏ µ¿ ³² ¼­
int d_row[] = { -1, 0, 1, 0 };
int d_col[] = { 0, 1, 0, -1 };

bool is_valid(int row, int col, int n) {
	if (0 <= row and row < n and 0 <= col and col < n) {
		if (!visited[row][col]) {
			return true;
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> room[i];
		for (int j = 0; j < n; j++) {
			broken[i][j] = INF;
		}
	}

	q.push({0, 0});
	visited[0][0] = true;
	broken[0][0] = 0;

	int now_row, now_col;
	int next_row, next_col;
	while (!q.empty()) {
		now_row = q.front().first;
		now_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = now_row + d_row[i];
			next_col = now_col + d_col[i];
			if (is_valid(next_row, next_col, n)) {
				if (room[next_row][next_col] == '1') {
					if (broken[next_row][next_col] > broken[now_row][now_col]) {
						broken[next_row][next_col] = broken[now_row][now_col];
						q.push({ next_row, next_col });
					}
					
				}
				else {
					if (broken[next_row][next_col] > broken[now_row][now_col] + 1) {
						broken[next_row][next_col] = broken[now_row][now_col] + 1;
						q.push({ next_row, next_col });
					}
				}
			}
		}
	}

	cout << broken[n - 1][n - 1];
}
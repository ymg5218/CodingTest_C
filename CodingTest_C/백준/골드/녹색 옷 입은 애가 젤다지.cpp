// 4485

#include <iostream>
#include <queue>
#define INF 125 * 125 * 9
using namespace std;

int map[125][125];
int score[125][125];
int n;

// µ¿ ³² ¼­ ºÏ
int d_row[] = {0, 1, 0, -1};
int d_col[] = {1, 0, -1, 0}; 

bool is_valid(int row, int col) {
	if (0 <= row and row < n and 0 <= col and col < n) {
		return true;
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int seq = 0;
	while (true) {
		cin >> n;
		if (n == 0) break;
		seq++;

		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				cin >> map[row][col];
				score[row][col] = INF;
			}
		}

		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		score[0][0] = map[0][0];

		int now_row, now_col;
		int next_row, next_col;
		while (!q.empty()) {
			now_row = q.front().first;
			now_col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				next_row = now_row + d_row[i];
				next_col = now_col + d_col[i];
				if (is_valid(next_row, next_col)) {
					if (score[next_row][next_col] > score[now_row][now_col] + map[next_row][next_col]) {
						score[next_row][next_col] = score[now_row][now_col] + map[next_row][next_col];
						q.push({ next_row, next_col });
					}
				}
			}
		}
		
		cout << "Problem " << seq << ": " << score[n - 1][n - 1] << "\n";
	}
}
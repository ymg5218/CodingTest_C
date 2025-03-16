// 16234

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int land[50][50];

bool visited[50][50];

// µ¿ ³² ¼­ ºÏ
int d_row[4] = { 0, 1, 0, -1 };
int d_col[4] = { 1, 0, -1, 0 };

int bfs(int start_row, int start_col) {
	int now_row, now_col;
	int next_row, next_col, gap;
	int groupCnt = 0;
	int totalPopulation = 0;
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;

	q.push({ start_row, start_col });
	visited[start_row][start_col] = true;
	totalPopulation += land[start_row][start_col];
	
	while (!q.empty()) {
		v.push_back({ q.front().first, q.front().second });
		now_row = q.front().first; now_col = q.front().second;
		groupCnt += 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = now_row + d_row[i]; next_col = now_col + d_col[i];
			if (0 <= next_row and next_row < N and 0 <= next_col and next_col < N) {
				if (!visited[next_row][next_col]) {
					gap = abs(land[now_row][now_col] - land[next_row][next_col]);
					if (L <= gap and gap <= R) {
						q.push({ next_row, next_col });
						visited[next_row][next_col] = true;
						totalPopulation += land[next_row][next_col];
					}
				}
				
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		land[v[i].first][v[i].second] = totalPopulation / groupCnt;
	}

	return groupCnt;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	cin >> N >> L >> R;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> land[r][c];
			visited[r][c] = false;
		}
	}

	int date = 0;
	bool isMove = false;
	while (true) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (!visited[row][col]) {
					if (bfs(row, col) > 1) isMove = true;
				}
				
			}
		}
		if (!isMove) break;
		date++;
		isMove = false;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				visited[r][c] = false;
			}
		}
	}

	cout << date;
}
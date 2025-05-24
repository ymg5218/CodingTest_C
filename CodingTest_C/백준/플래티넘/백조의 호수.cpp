// 3197

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#define endl "\n"

using namespace std;

vector<vector<int>> lake;
int R, C;
int L1_row = -1; int L1_col = -1;
int L2_row = -1; int L2_col = -1;

// µ¿ ³² ¼­ ºÏ
int d_row[] = { 0, 1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };

vector<vector<bool>> ch;
queue<pair<int, int>> sq, wq, tmpSQ, tmpWQ;

bool swanBFS() {
	while (!sq.empty()) {
		auto [r, c] = sq.front();
		sq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + d_row[i];
			int nc = c + d_col[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || ch[nr][nc]) continue;
			if (nr == L2_row && nc == L2_col) return true;
			ch[nr][nc] = true;
			if (lake[nr][nc] == 1) tmpSQ.push({ nr, nc });
			else sq.push({ nr, nc });
		}
	}
	return false;
}

void waterBFS() {
	while (!wq.empty()) {
		auto [r, c] = wq.front();
		wq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + d_row[i];
			int nc = c + d_col[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (lake[nr][nc] == 1) {
				lake[nr][nc] = 0;
				tmpWQ.push({ nr, nc });
			}
		}
	}
}

void solution() {
	int day = 0;
	while (true) {
		if (swanBFS()) {
			cout << day;
			return;
		}
		waterBFS();
		sq = tmpSQ;
		wq = tmpWQ;
		while (!tmpSQ.empty()) tmpSQ.pop();
		while (!tmpWQ.empty()) tmpWQ.pop();

		day++;
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> R >> C;
	lake.resize(R, vector<int>(C));
	ch.resize(R, vector<bool>(C));
	for (int i = 0; i < R; i++) {
		string r;
		cin >> r;
		for (int j = 0; j < C; j++) {
			if (r[j] == 'L') {
				if (L1_row == -1) {
					L1_row = i; L1_col = j;
					sq.push({ i, j });
					wq.push({ i, j });
					ch[i][j] = true;
				}
				else {
					L2_row = i; L2_col = j;
					wq.push({ i, j });
				}
			}
			else if (r[j] == 'X') {
				lake[i][j] = 1;
			}
			else {
				wq.push({ i, j });
			}
		}
	}

	// cout << L1_row << " " << L1_col << endl << L2_row << " " << L2_col << endl;
	
	solution();
}
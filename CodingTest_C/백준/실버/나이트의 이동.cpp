// 7562

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Board {
private:
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	int visited[300][300] = { 0, };
	int goal_row; int goal_col;
	int size;

	
	int d_row[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int d_col[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

public:
	Board(int start_row, int start_col, int goal_row, int goal_col, int size) {
		this->v.push_back({ start_row, start_col });
		this->q.push({ start_row, start_col });
		this->goal_row = goal_row;
		this->goal_col = goal_col;
		this->visited[start_row][start_col] = 1;
		this->size = size;
	}

	int BFS() {
		int now_row; int now_col;
		int next_row; int next_col;
		int now_seq;
		while (!this->q.empty()) {
			now_row = q.front().first;
			now_col = q.front().second;
			q.pop();
			if (now_row == this->goal_row && now_col == this->goal_col) return 0;

			now_seq = visited[now_row][now_col];
			for (int i = 0; i < 8; i++) {
				next_row = now_row + this->d_row[i];
				next_col = now_col + this->d_col[i];
				if (isValid(next_row, next_col)) {
					if (next_row == this->goal_row && next_col == this->goal_col) return now_seq;
					q.push({ next_row, next_col });
					visited[next_row][next_col] = now_seq + 1;
				}
			}
		}
		// error checker
		return -1;
	}

	bool isValid(int row, int col) {
		if (0 <= row && row < size && 0 <= col && col < size) {
			if (visited[row][col] == 0) {
				return true;
			}
		}
		return false;
	}

};

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	cout.tie(nullptr);

	int T;
	int I;
	int now_row; int now_col;
	int goal_row; int goal_col;
	int result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I;
		cin >> now_row >> now_col >> goal_row >> goal_col;
		Board board(now_row, now_col, goal_row, goal_col, I);
		result = board.BFS();
		if (result != -1) {
			cout << result << "\n";
		}
		else {
			cout << "Error" << "\n";
		}
	}
}
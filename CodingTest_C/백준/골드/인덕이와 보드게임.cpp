// 33926

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

enum Color {White, Black};
vector<vector<int>> board;
vector<vector<Color>> color;
// {ÃÖ¼Ú°ª, ÃÖ´ñ°ª}
vector<vector<pair<ll, ll>>> score;
int N, M;

void solution() {
	score[0][0] = { board[0][0], board[0][0] };

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (row == 0 && col == 0) continue;

			if (row == 0) {
				ll now_score;
				now_score = score[row][col - 1].first + board[row][col];
				if (color[row][col] == Black) now_score *= -1;
				score[row][col] = make_pair(now_score, now_score);
			}
			else if (col == 0) {
				ll now_score;
				now_score = score[row - 1][col].first + board[row][col];
				if (color[row][col] == Black) now_score *= -1;
				score[row][col] = make_pair(now_score, now_score);
			}
			else {
				if (color[row][col] == Black) {
					score[row][col].first = min(-1 * (score[row - 1][col].second + board[row][col]), -1 * (score[row][col - 1].second + board[row][col]));
					score[row][col].second = max(-1 * (score[row - 1][col].first + board[row][col]), -1 * (score[row][col - 1].first + board[row][col]));
				}
				else {
					score[row][col].first = min(score[row - 1][col].first, score[row][col - 1].first) + + board[row][col];
					score[row][col].second = max(score[row - 1][col].second, score[row][col - 1].second) + board[row][col];
				}
			}
		}
	}
	//cout << "*******ÃÖ´ñ°ª**********" << endl;
	//for (auto row : score) {
	//	for (auto col : row) {
	//		cout << col.second <<  " ";
	//	}
	//	cout << endl;
	//}

	//cout << "*******ÃÖ¼Ú°ª**********" << endl;
	//for (auto row : score) {
	//	for (auto col : row) {
	//		cout << col.first << " ";
	//	}
	//	cout << endl;
	//}

	cout << score[N - 1][M - 1].second;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	
	cin >> N >> M;
	board.resize(N, vector<int>(M));
	color.resize(N, vector<Color>(M));
	score.resize(N, vector<pair<ll, ll>>(M));
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			int c;
			cin >> c;
			if (!c) color[row][col] = White;
			else color[row][col] = Black;
		}
	}

	solution();
}
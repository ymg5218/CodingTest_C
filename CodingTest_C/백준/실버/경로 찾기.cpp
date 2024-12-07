// 11403

#include <iostream>
using namespace std;

void floyd_warshhall(int board[100][100], int N) {
	for (int _v = 0; _v < N; _v++) {
		for (int v1 = 0; v1 < N; v1++) {
			for (int v2 = 0; v2 < N; v2++) {
				if (board[v1][_v] && board[_v][v2]) board[v1][v2] = 1;
			}
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N;
	cin >> N;

	int board[100][100];
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> board[row][col];
		}
	}

	floyd_warshhall(board, N);
}
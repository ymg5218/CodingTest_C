// 14500

#include <iostream>
#include <algorithm>
using namespace std;

long long board[500][500];

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);
	
	int N, M;
	cin >> N >> M;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
		}
	}

	long long max_sum = 0;
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			/*
				бсбсбсбс

				бс
				бс
				бс
				бс
			*/
			if (col + 3 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row][col + 2] + board[row][col + 3]);
			}
			if (row + 3 < N) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row + 2][col] + board[row + 3][col]);
			}

			/*
				бсбс
				бсбс
			*/
			if (row + 1 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row][col + 1] + board[row + 1][col + 1]);
			}
			/*
				бс
				бс
				бсбс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row + 2][col] + board[row + 2][col + 1]);
			}
			/*
				  бс
				  бс
				бсбс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col + 1] + board[row + 1][col + 1] + board[row + 2][col + 1] + board[row + 2][col]);
			}
			/*
				бсбсбс
				бс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row][col + 2] + board[row + 1][col]);
			}
			
			/*
				бсбсбс
				    бс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row][col + 2] + board[row + 1][col + 2]);
			}

			/*
				бсбс
				  бс
				  бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row + 1][col + 1] + board[row + 2][col + 1]);
			}

			/*
				бсбс
				бс
				бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row + 1][col] + board[row + 2][col]);
			}
			/*
				    бс
				бсбсбс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col + 2] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 1][col + 2]);
			}

			/*
				бс
				бсбсбс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 1][col + 2]);
			}

			/*
				бс
				бсбс
				  бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 2][col + 1]);
			}

			/*
				  бс
				бсбс
			    бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col + 1] + board[row + 1][col + 1] + board[row + 1][col] + board[row + 2][col]);
			}
			/*
				  бсбс
				бсбс
			*/

			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col + 1] + board[row][col + 2] + board[row + 1][col] + board[row + 1][col + 1]);
			}

			/*
				бсбс
				  бсбс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row + 1][col + 1] + board[row + 1][col + 2]);
			}

			/*
				бсбсбс
				  бс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col] + board[row][col + 1] + board[row][col + 2] + board[row + 1][col + 1]);
			}
			/*
				бс
				бсбс
				бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col] + board[row + 1][col] + board[row + 2][col] + board[row + 1][col + 1]);
			}

			/*
				  бс
				бсбс
				  бс
			*/
			if (row + 2 < N and col + 1 < M) {
				max_sum = max(max_sum, board[row][col + 1] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 2][col + 1]);
			}

			/*
				  бс
				бсбсбс
			*/
			if (row + 1 < N and col + 2 < M) {
				max_sum = max(max_sum, board[row][col + 1] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 1][col + 2]);
			}
		}
	}
	cout << max_sum;
}
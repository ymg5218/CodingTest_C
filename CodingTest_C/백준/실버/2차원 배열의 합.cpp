// 2167

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M;
	cin >> N >> M;

	int matrix[301][301];
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= M; col++) {
			cin >> matrix[row][col];
		}
	}

	int K;
	cin >> K;
	
	int i, j, x, y;
	long long result;
	for (int seq = 0; seq < K; seq++) {
		result = 0;
		cin >> i >> j >> x >> y;
		for (int row = i; row <= x; row++) {
			for (int col = j; col <= y; col++) {
				result += matrix[row][col];
			}
		}
		cout << result << "\n";
	}
}
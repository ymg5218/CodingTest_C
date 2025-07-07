// 10942

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

bool dp[2000][2000];

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N;
	vector<int> seq(N);
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j <= i + 1; j++) {
			if (i == j) {
				dp[i][j] = true;
				if (i == N - 1)
					break;
			}
				
			else {
				if (seq[i] == seq[j])
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
		}
	}
	
	for (int gap = 2; gap < N; gap++) {
		for (int i = 0; i < N - gap; i++) {
			int j = i + gap;
			if (seq[i] == seq[j]) {
				dp[i][j] = dp[i + 1][j - 1] ? true : false;
			}
			else
				dp[i][j] = false;
		}
	}


	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		if (S > E)
			swap(S, E);
		
		if (dp[S - 1][E - 1])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}
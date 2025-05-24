// 11047

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K / coins[i] > 0) {
			cnt += K / coins[i];
			K %= coins[i];
			if (K == 0) break;
		}
	}
	cout << cnt;
}
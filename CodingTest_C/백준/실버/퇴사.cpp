// 14501

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<int> T(N + 2);
	vector<int> P(N + 2);
	
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	vector<int> dp(N + 2, 0);
	for (int i = 1; i <= N; i++) {
		int now_t = T[i];
		int now_p = P[i];

		dp[i + 1] = max(dp[i + 1], dp[i]);

		int next_t = i + now_t;
		if (next_t <= N + 1 ) {
			dp[next_t] = max(dp[next_t], dp[i] + now_p);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}
// 2631

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> arr(N, 0);
	vector<int> dp(N, 1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[j] = max(dp[j], dp[j] + 1);
		}
	}

	cout << N - *max_element(dp.begin(), dp.end());
}
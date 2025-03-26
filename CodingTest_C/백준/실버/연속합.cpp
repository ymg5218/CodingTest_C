// 1912

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n);
	
	for (int i{ 0 }; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int max_sum = dp[0];
	for (int i{ 1 }; i < n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		max_sum = max(dp[i], max_sum);
	}

	cout << max_sum << endl;
	
}
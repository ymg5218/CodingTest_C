// 16287

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<bool, int, int>> dp;
vector<int> arr;
int w, n;


int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> w >> n;
	arr.resize(n);
	dp.resize(w + 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] <= w) {
				dp[arr[i] + arr[j]] = { true, i, j };
			}
				
		}
	}
	
	bool is_valid = false;
	for (int i = 1; i <= w; i++) {
		auto [is_exist_ab, a, b] = dp[i];
		auto [is_exist_cd, c, d] = dp[w - i];
		if (is_exist_ab && is_exist_cd) {
			if (a != c && a != d && b != c && b != d) {
				is_valid = true;
				break;
			}
		}
	}
	if (!is_valid) cout << "NO";
	else cout << "YES";
}
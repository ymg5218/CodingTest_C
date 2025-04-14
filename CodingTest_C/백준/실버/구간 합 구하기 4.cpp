// 11659

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	vector<int> arr;
	arr.push_back(0);
	vector<int> dp;
	dp.push_back(0);
	for (int i{ 1 }; i <= N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		dp.push_back(dp[i - 1] + num);
	}
	
	for (int i{ 0 }; i < M; i++) {
		int L, R;
		int sum;
		cin >> L >> R;
		
		if (L != 0) sum = dp[R] - dp[L - 1];
		else sum = dp[R];

		cout << sum << endl;
	}
}

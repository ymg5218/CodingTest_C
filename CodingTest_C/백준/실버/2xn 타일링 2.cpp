// 11727

#include <iostream>
#define ll long long
using namespace std;


int main(void) {
	ll dp[1001];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}
	cout << dp[N];
	
}
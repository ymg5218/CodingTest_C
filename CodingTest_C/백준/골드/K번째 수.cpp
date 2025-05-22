// 1300

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	ll int N, K;
	cin >> N >> K;
	ll int left = 1;
	ll int right = N * N;
	ll int res = 0;
	while (left <= right) {
		ll int mid = (left + right) / 2;
		ll int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		if (cnt >= K) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << res << endl;
}
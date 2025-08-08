#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

ll solution(int n, vector<int> times) {
	ll length = times.size();

	ll left = 1;
	ll right = (ll) *max_element(times.begin(), times.end()) * n;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < length; i++) {
			cnt += mid / (ll) times[i];
		}
		if (cnt >= n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n = 6;
	vector<int> times = { 7, 10 };

	cout << solution(n, times) << endl;
}
// 3841

#include <iostream>
#include <deque>
#include <vector>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"
#define ll long long

using namespace std;

int n;
deque<ll> dq; // dq.front() = minimum value
vector<ll> arr;
vector<ll> arr2;

int init() {
	dq.clear();
	cin >> n;
	if (n == 0) {
		return 0;
	}
	arr.assign(n, 0);
	arr2.assign(n * 2, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
		arr2[i + n] = arr[i];
	}

	return 1;
}

vector<ll> set_pfsum() {
	vector<ll> prefix_sum(2 * n + 1, 0);
	for (int i = 0; i < 2 * n; i++) {
		prefix_sum[i + 1] = prefix_sum[i] + arr2[i];
	}

	return prefix_sum;
}

int solution() {
	int cnt = 0;
	auto prefix_sum = set_pfsum();

	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && prefix_sum[dq.back()] > prefix_sum[i]) dq.pop_back();
		dq.push_back(i);
	}

	for (int k = 0; k < n; k++) {
		if (prefix_sum[dq.front()] - prefix_sum[k] >= 0) cnt++;

		// 슬라이딩 윈도우
		while (!dq.empty() && dq.front() == k + 1)
			dq.pop_front();
		int new_idx = k + n + 1;
		while (!dq.empty() && prefix_sum[dq.back()] > prefix_sum[new_idx])
			dq.pop_back();
		dq.push_back(new_idx);
	}

	return cnt;
}

int main() {
	FASTIO;

	while (init()) {
		cout << solution() << endl;
	}
}
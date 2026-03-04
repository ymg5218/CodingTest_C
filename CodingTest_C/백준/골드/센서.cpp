// 2212

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define ll long long

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N; cin >> N;
	int K; cin >> K;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++) {
		diff[i] = arr[i + 1] - arr[i];
	}
	sort(diff.begin(), diff.end());
	
	ll min_len = 0;
	for (int i = 0; i < N - K; i++) {
		min_len += diff[i];
	}
	cout << min_len << endl;
}
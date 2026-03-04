// 2437

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	int res = 1;
	for (int x : arr) {
		if (res < x) {
			cout << res;
			return 0;
		}
		res += x;
	}
	cout << res;
	return 0;
}
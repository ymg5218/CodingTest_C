// 1806

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, S;
	
	cin >> N >> S;
	vector<int> arr(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		arr[i] = arr[i - 1] + n;
	}
	
	int min_len = 100001;
	int left = 1;
	int right = 1;
	
	while (true) {
		if (min_len == 1) {
			cout << min_len << endl;
			break;
		}
		if (left > right) {
			right = left;
		}
		if (left == N + 1 || right == N + 1) {
			if (min_len == 100001) cout << 0 << endl;
			else {
				cout << min_len << endl;
			}
			break;
		}
		ll int now_sum = arr[right] - arr[left - 1];
		if (now_sum >= S) {
			min_len = min(min_len, right - left + 1);
			left++;
		}
		else {
			right++;
		}
	}
}
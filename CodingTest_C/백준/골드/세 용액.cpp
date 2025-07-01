// 2473

#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int N;
vector<int> arr;

void solution() {
	int min_fix;
	int min_left;
	int min_right;
	ll min_sum = 3e9 + 1;
	for (int fix = 0; fix < N; fix++) {
		ll fixed = arr[fix];
		int left = 0; int right = N - 1;
		while (left < right) {
			if (left == fix) {
				left++;
				continue;
			}
			else if (right == fix) {
				right--;
				continue;
			}
			ll sum = fixed;
			sum += (arr[left] + arr[right]);
			if (min_sum > abs(sum)) {
				min_sum = abs(sum);
				min_fix = fix;
				min_left = left;
				min_right = right;
			}
			if (abs(arr[left + 1] + arr[right] + fixed) <= abs(arr[left] + arr[right - 1] + fixed))
				left++;
			else
				right--;
			
			if (min_sum == 0) 
				break;
		}

	}

	vector<ll> result(3);
	result[0] = arr[min_fix]; result[1] = arr[min_left]; result[2] = arr[min_right];
	sort(result.begin(), result.end());
	cout << result[0] << " " << result[1] << " " << result[2] << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	solution();
}
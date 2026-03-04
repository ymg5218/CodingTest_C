// 13164

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		arr[i] = arr[i + 1] - arr[i];
	}
	arr.pop_back();

	sort(arr.begin(), arr.end());
	
	int sum = 0;
	for (int i = 0; i < N - K; i++) {
		sum += arr[i];
	}
	cout << sum;
}
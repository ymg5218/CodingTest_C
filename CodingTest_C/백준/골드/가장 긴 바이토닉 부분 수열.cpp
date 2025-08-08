// 11054

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<int> arr;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int max_res = 0;
	
	
	// LIS
	vector<int> dp_LIS(N, 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp_LIS[i] = max(dp_LIS[i], dp_LIS[j] + 1);
		}
	}
	// LDS
	vector<int> dp_LDS(N, 1);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i]) dp_LDS[i] = max(dp_LDS[i], dp_LDS[j] + 1);
		}
	}
	
	for (int i = 0; i < N; i++) {
		max_res = max(max_res, dp_LIS[i] + dp_LDS[i] - 1);
	}
	
	
	cout << max_res << endl;
}
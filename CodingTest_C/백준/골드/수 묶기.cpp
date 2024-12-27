// 1744

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N;
	vector<long long> arr_plus;
	vector<long long> arr_minus;
	long long num;
	long long result = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num <= 0) arr_minus.push_back(num);
		else arr_plus.push_back(num);
	}

	sort(arr_plus.rbegin(), arr_plus.rend());
	sort(arr_minus.begin(), arr_minus.end());

	int arr_minus_size = arr_minus.size();
	int arr_plus_size = arr_plus.size();

	for (int idx = 0; idx < arr_minus_size; idx += 2) {
		if (idx == arr_minus_size - 1) {
			result += arr_minus[idx];
		}
		else if (arr_minus[idx + 1] == 0) {
			continue;
		}
		else {
			result += (arr_minus[idx] * arr_minus[idx + 1]);
		}
	}

	for (int idx = 0; idx < arr_plus.size(); idx += 2) {
		if (idx == arr_plus_size - 1) {
			result += arr_plus[idx];
		}
		else if (arr_plus[idx + 1] == 1) {
			result += arr_plus[idx];
			result += arr_plus[idx + 1];
		}
		else {
			result += (arr_plus[idx] * arr_plus[idx + 1]);
		}
	}

	cout << result;
}
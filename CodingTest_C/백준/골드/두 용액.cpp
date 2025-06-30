// 2470

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> solution(N);

	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}

	sort(solution.begin(), solution.end());

	int minimum_sum = 2e9 + 1;
	int min_left = -1, min_right = -1;
	int left = 0, right = N - 1;

	while (left < right) {
		if (minimum_sum > abs(solution[left] + solution[right])) {
			minimum_sum = abs(solution[left] + solution[right]);
			min_left = left;
			min_right = right;
		}
		// 다음 어떤 포인터를 shift 할지 정함.
		if (abs(solution[left + 1] + solution[right]) < abs(solution[left] + solution[right - 1])) { // left를 shift했을 때가 right를 shift했을 때보다 더 0에 가까우면 left를 shift
			left++;
		}
		else {                                                                                       // 아니라면 right를 shift
			right--;
		}
	}
	cout << solution[min_left] << " " << solution[min_right] << endl;
}
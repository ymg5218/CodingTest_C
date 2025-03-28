// 1450

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, C;

void combine(int left, int right, vector<int>& set, vector<int> arr, int sum) {
	if (sum > C) return;
	if (left > right) {
		set.push_back(sum);
		return;
	}
	combine(left + 1, right, set, arr,sum);
	combine(left + 1, right, set, arr, sum + arr[left]);
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	long long answer = 0;
	cin >> N >> C;
	vector<int> arr(N);
	vector<int> setA;
	vector<int> setB;

	
	for (int i{ 0 }; i < N; i++) {
		cin >> arr[i];
	}

	combine(0, N/2, setA, arr, 0);
	combine(N / 2 + 1, N - 1, setB, arr, 0);
	
	sort(setB.begin(), setB.end());
	for (int i{ 0 }; i < setA.size(); i++) {
		answer += upper_bound(setB.begin(), setB.end(), C - setA[i]) - setB.begin();
	}

	cout << answer << endl;
}
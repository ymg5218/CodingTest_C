// 10819

#include <iostream>
#include <vector>
#include <cmath>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int N;
vector<int> arr;
vector<bool> used;
int max_sum = 0;

void init() {
	cin >> N;
	arr.assign(N, 0);
	used.assign(N, false);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void backtracking(int idx, vector<int> combi) {
	if (combi.size() == N) {
		int now_sum = 0;
		for (int i = 1; i < N; i++) {
			now_sum += abs(combi[i - 1] - combi[i]);
		}
		max_sum = max(max_sum, now_sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		combi.push_back(arr[i]);
		used[i] = true;
		backtracking(i, combi);
		used[i] = false;
		combi.pop_back();
	}
}

int main() {
	FASTIO;
	init();
	backtracking(0, {});
	cout << max_sum << endl;
}
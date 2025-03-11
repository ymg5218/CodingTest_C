// 15652

#include <iostream>
#include <vector>

using namespace std;

int N, M;

void backtracking(vector<int> arr, int cnt, int start_idx) {
	if (cnt == M) {
		for (int i{ 0 }; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i{ start_idx }; i <= N; i++) {
		arr.push_back(i);
		backtracking(arr, cnt + 1, i);
		arr.pop_back();
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> arr;
	
	cin >> N >> M;
	
	backtracking(arr, 0, 1);
}
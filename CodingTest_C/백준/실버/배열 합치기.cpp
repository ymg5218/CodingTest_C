// 11728

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void init() {
	int N, M;
	cin >> N >> M;
	arr.assign(N + M, 0);
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	sort(arr.begin(), arr.end());
	for (int x : arr)
		cout << x << " ";
}
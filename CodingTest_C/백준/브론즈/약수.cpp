// 1037

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	cout << arr[0] * arr[N - 1] << endl;
}
// 1041

#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define A arr[0]
#define B arr[1]
#define C arr[2]
#define D arr[3]
#define E arr[4]
#define F arr[5]

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	ll N; cin >> N;
	vector<int> arr(6);
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	
	ll res = 0;

	if (N == 1) {
		sort(arr.begin(), arr.end());
		for (int i = 0; i < 5; i++) {
			res += arr[i];
		}
	}
	else {
		vector<ll> mins(3);
		mins[0] = min(A, F); mins[1] = min(B, E); mins[2] = min(C, D);
		sort(mins.begin(), mins.end());
		ll three_side = mins[0] + mins[1] + mins[2];
		ll two_side = mins[0] + mins[1];
		ll one_side = mins[0];

		res = three_side * 4 
			+ two_side * (4 + ((N - 2) * 4) * 2) 
			+ one_side * ((N - 2) * 4 + (N - 2) * (N - 2) * 5);
	}
	cout << res;
}
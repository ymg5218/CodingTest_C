// 21920

#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> arr;

int gcd(int x, int y) {
	if (x > y) swap(x, y);
	
	int z;
	while (y != 0) {
		z = x % y;
		x = y;
		y = z;
	}
	return x;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;
	
	double sum = 0;
	double cnt = 0;

	for (int i = 0; i < N; i++) {
		if (gcd(arr[i], X) == 1) {
			cnt++;
			sum += arr[i];
		}
	}
	cout << fixed;
	cout.precision(6);
	double res = sum / cnt;
	cout << res;
}
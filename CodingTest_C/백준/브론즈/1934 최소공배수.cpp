// 1943

#include <iostream>

using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (x % y != 0) {
		int _y = y;
		y = x % y;
		x = _y;
		if (x < y) swap(x, y);
	}
	return y;
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;

		int GCD = gcd(x, y);
		cout << (x * y) / GCD << "\n";
	}

// 9020

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"

using namespace std;

int T, n;
vector<bool> is_prime(10001, true);

void init() {
	is_prime[0] = false; is_prime[1] = false;
	for (int i = 2; i < sqrt(10000); i++) {
		if (is_prime[i]) {
			int mul = 2;
			while (i * mul <= 10000) {
				is_prime[i * mul] = false;
				mul++;
			}
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();

	cin >> T;
	while (T--) {
		cin >> n;
		int left = n / 2; int right = n / 2;
		while (is_prime[left] == false || is_prime[right] == false) {
			left--;
			right++;
		}
		cout << left << " " << right << endl;
	}
}
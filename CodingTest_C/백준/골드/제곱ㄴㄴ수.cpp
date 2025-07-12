// 1016

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define ll long long

using namespace std;

ll l, r;

int main(void) {
	cin >> l >> r;

	vector<bool> isSqr(r - l + 1, false);

	int cnt = r - l + 1;

	for (ll i = 2; i * i <= r; i++) {
		ll ret = l / (i * i);
		if (l % (i * i) != 0)
			ret++;
		while (ret * (i * i) <= r) {
			if (!isSqr[ret * (i * i) - l]) {
				isSqr[ret * (i * i) - l] = true;
				cnt--;
			}
			ret++;
		}
	}

	cout << cnt;
}
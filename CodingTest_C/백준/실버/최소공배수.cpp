// 13241

#include <iostream>
#define endl "\n"
#define ll long long

using namespace std;

ll A, B;

ll GCD(ll x, ll y) {
	ll c;

	while (y != 0) {
		c = x % y;
		x = y;
		y = c;
	}

	return x;
}

ll solution() {
	cin >> A >> B;
	return A * B / GCD(A, B);
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cout << solution() << endl;
}
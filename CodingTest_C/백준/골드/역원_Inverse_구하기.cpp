// 14565

#include <iostream>
#define endl "\n"
#define ll long long

using namespace std;

ll xEuclid(ll N, ll A) {
	ll r1 = N, r2 = A;
	ll t1 = 0, t2 = 1;
	
	while (r2 != 0) {
		ll q = r1 / r2;
		ll r = r1 % r2;
		ll t = t1 - q * t2;

		r1 = r2;
		r2 = r;
		t1 = t2;
		t2 = t;
	}

	if (r1 != 1) return -1;

	if (t1 < 0) t1 += N;

	return t1;
	
}

int main(void) {
	ll N, A;
	cin >> N >> A;

	// µ¡¼À ¿ª¿ø
	cout << N - A << " ";

	// °ö¼À ¿ª¿ø
	cout << xEuclid(N, A);
}
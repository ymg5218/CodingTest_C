// 1735

#include <iostream>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define ll long long

using namespace std;

ll A, B, C, D;
ll X, Y;

ll gcd(ll a, ll b) {
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main() {
	FASTIO;
	cin >> A >> B >> C >> D;
	Y = B * D;
	X = A * D + B * C;
	
	ll g = gcd(X, Y);
	cout << X / g << " " << Y / g;
}
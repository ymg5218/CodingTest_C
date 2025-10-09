// 1629

#include <iostream>
#include <vector>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"
#define ll long long

using namespace std;

ll A, B, C;

void init() {
	cin >> A >> B >> C;
}

ll div_conq(ll a, ll b) {
	if (b == 0)
		return 1;
	a %= C;
	ll ans = div_conq(a, b / 2) % C;
	if (b % 2 == 0)
		return (ans * ans) % C;
	else
		return ((ans * ans) % C * a) % C;
}

int main() {
	FASTIO;
	init();
	cout << div_conq(A, B) << endl;
}
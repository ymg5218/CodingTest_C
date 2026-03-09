// 17446

#include <iostream>

#define ll long long

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, P; cin >> N >> P;
	ll res = 1;
	while (N > 0) {
		res *= N;
		res %= P;
		--N;
	}
	cout << res;
}
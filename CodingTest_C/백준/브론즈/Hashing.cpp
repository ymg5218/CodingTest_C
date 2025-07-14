// 15829
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
#define ll long long

using namespace std;

ll pow(int x, int a, int M) {
	ll res = 1;
	while (a--) {
		res *= x;
		res %= M;
	}
	return res;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int L;
	cin >> L;

	string s;
	cin >> s;

	int r = 31;
	ll M = 1234567891;

	ll res = 0;
	for (int i = 0; i < L; i++) {
		res += ((int(s[i]) - int('a') + 1) * pow(r, i, M) % M);
		res %= M;
	}
	cout << res % M;
	
}
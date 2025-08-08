// 31994

#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	string res;
	int maxcnt = -1;
	for (int i = 0; i < 7; i++) {
		string s;
		int n;
		cin >> s >> n;

		if (maxcnt < n) {
			res = s;
			maxcnt = n;
		}
	}
	cout << res;
}
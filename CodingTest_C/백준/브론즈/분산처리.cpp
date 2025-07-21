// 1009

#include <iostream>
#define endl "\n"
using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	while (T--) {
		int a, b;
		cin >> a >> b;
		int n = 1;
		while (b--) {
			n *= a;
			n %= 10;
		}
		n = n == 0 ? 10 : n;
		cout << n << endl;
	}
	
}
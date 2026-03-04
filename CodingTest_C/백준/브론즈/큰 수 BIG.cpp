#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	string a;
	cin >> a;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans = (ans * 10 + (a[i] - '0')) % 20000303;
	}
	cout << ans;
}
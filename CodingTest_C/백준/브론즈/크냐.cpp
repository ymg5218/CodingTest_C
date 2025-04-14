// 4101

#include <iostream>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a > b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
// 10953

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int T;
	cin >> T;
	string s;

	for (int i = 0; i < T; i++) {
		cin >> s;
		cout << int(s[0]) - int('0') + int(s[2]) - int('0') << endl;
	}
}
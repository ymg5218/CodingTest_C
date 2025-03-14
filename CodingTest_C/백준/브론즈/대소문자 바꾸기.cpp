// 2744

#include <iostream>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 90) cout << char(s[i] + (97 - 65));
		else cout << char(s[i] - (97 - 65));
	}
}
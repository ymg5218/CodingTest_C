// 1264

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	while (true) {
		getline(cin, s);
		if (s[0] == '#') break;

		int result = 0;

		for (int idx = 0; idx < s.length(); idx++) {
			if (s[idx] == 'a' or s[idx] == 'e' or s[idx] == 'i' or s[idx] == 'o' or s[idx] == 'u' or s[idx] == 'A' or s[idx] == 'E' or s[idx] == 'I' or s[idx] == 'O' or s[idx] == 'U') result++;
		}

		cout << result << '\n';
	}
	
}
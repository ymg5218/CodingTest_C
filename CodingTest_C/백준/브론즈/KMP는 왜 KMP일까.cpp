// 2902

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	string result = "";

	for (int idx = 0; idx < s.length() - 1; idx++) {
		if (idx == 0) result += s[idx];
		else if (s[idx] == '-') result += s[idx + 1];
	}

	cout << result;
}
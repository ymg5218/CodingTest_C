// 1357

#include <iostream>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

int main(void) {
	string X, Y;
	cin >> X >> Y;
	
	int dgt = 1;
	int re_X = 0;
	for (auto c : X) {
		re_X += int(c - '0') * dgt;
		dgt *= 10;
	}
	dgt = 1;
	int re_Y = 0;
	for (auto c : Y) {
		re_X += int(c - '0') * dgt;
		dgt *= 10;
	}
	int result = re_X + re_Y;
	string re_result = to_string(result);
	bool is_zero = true;
	for (int i = re_result.size() - 1; i >= 0; i--) {
		if (is_zero && re_result[i] == '0') continue;
		if (is_zero && re_result[i] != '0') is_zero = false;
		cout << re_result[i];
	}
	
}
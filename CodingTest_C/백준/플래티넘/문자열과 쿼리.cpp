// 13713

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

vector<int> Z(const string& s) {
	int length = s.length();
	vector<int> z(length);
	z[0] = length;
	for (int i = 1, l = 0, r = 0; i < length; i++) {
		if (i > r) {
			r = l = i;
			while (r < length && s[r] == s[r - i]) r++;
			z[i] = r - l; r--;
		}
		else {
			int k = i - l;
			if (z[k] < r - i + 1) z[i] = z[k];
			else {
				l = i;
				while (r < length && s[r] == s[r - i]) r++;
				z[i] = r - l; r--;
			}
		}
	}
	return z;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int length = s.length();
	reverse(s.begin(), s.end());
	int M;
	cin >> M;
	auto z = Z(s);
	while (M--) {
		int q;
		cin >> q;
		cout << z[length - q] << endl;
	}
}
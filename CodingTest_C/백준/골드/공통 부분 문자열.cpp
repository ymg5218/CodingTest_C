// 5582

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;


vector<vector<int>> lcs;

void LCS() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	lcs.resize(s2.size() + 1, vector<int>(s1.size() + 1));

	int result = 0;
	for (int i = 1; i <= s2.size(); i++) {
		char now = s2[i - 1];
		for (int j = 1; j <= s1.size(); j++) {
			if (now == s1[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				result = max(lcs[i][j], result);
			}
			else {
				lcs[i][j] = 0;
			}
		}
	}

	cout << result;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	LCS();
}
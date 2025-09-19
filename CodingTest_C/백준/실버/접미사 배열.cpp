#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

string S;
vector<string> sa;
int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		sa.push_back(S.substr(i));
	}
	sort(sa.begin(), sa.end());
	for (const auto& x : sa) {
		cout << x << endl;
	}
}
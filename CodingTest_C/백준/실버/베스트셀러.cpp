// 1302

#include <iostream>
#include <vector>
#include <map>
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)

using namespace std;

int N;
map<string, int> mp;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (mp.find(s) != mp.end()) {
			mp[s]++;
		}
		else {
			mp[s] = 1;
		}
	}
}

string solution() {
	string res = "";
	int max_cnt = 0;
	for (auto& [x, cnt] : mp) {
		if (max_cnt < cnt) {
			max_cnt = cnt;
			res = x;
		}
		else if (max_cnt == cnt) {
			if (res == "" or res > x) {
				max_cnt = cnt;
				res = x;
			}
		}
	}

	return res;
}
int main() {
	FASTIO;
	init();
	cout << solution() << endl;
}
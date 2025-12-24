// 25955

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

vector<string> p;
vector<string> diff;
string tier = "BSGPD";

bool cmp(string& s1, string& s2) {
	if (s1[0] != s2[0]) {
		return tier.find(s1[0]) < tier.find(s2[0]);
	}
	else {
		int n1 = stoi(s1.substr(1, s1.length() - 1));
		int n2 = stoi(s2.substr(1, s2.length() - 1));
		return n1 > n2;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N; cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		p.push_back(s);
	}
	
	diff = p;

	sort(diff.begin(), diff.end(), cmp);
	
	vector<string> res;
	for (int i = 0; i < N; i++) {
		if (p[i] != diff[i]) {
			res.push_back(diff[i]);
		}
	}

	if (res.size() == 0) cout << "OK" << endl;
	else {
		cout << "KO" << endl;
		cout << res[0] << " " << res[1] << endl;
	}
}
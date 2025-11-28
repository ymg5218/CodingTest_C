// 4493

#include <iostream>
#define endl "\n"
using namespace std;

int result(const char& p1, const char& p2) {
	if (p1 == 'R') {
		if (p2 == 'R') return 0;
		else if (p2 == 'S') return 1;
		else return 2;
	}
	
	if (p1 == 'S') {
		if (p2 == 'R') return 2;
		else if (p2 == 'S') return 0;
		else return 1;
	}

	if (p1 == 'P') {
		if (p2 == 'P') return 0;
		else if (p2 == 'S') return 2;
		else return 1;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int p1_cnt = 0;
		int p2_cnt = 0;

		while (n--) {
			char p1, p2;
			cin >> p1 >> p2;
			int res = result(p1, p2);
			if (res == 1) p1_cnt++;
			else if (res == 2) p2_cnt++;
		}
		if (p1_cnt > p2_cnt) cout << "Player 1" << endl;
		else if (p1_cnt < p2_cnt) cout << "Player 2" << endl;
		else cout << "TIE" << endl;
	}
}
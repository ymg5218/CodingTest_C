// 31882

#include <iostream>
#define ll long long
using namespace std;

ll compute_score(ll cnt) {
	ll res = 0;
	ll score = 1;
	while (cnt > 0) {
		res += (score * cnt);
		score++;
		cnt--;
	}
	return res;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	cin >> s;
	ll score = 0;
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == '2') cnt++;
		else {
			if (cnt >= 1) {
				score += compute_score(cnt);
				cnt = 0;
			}
		}
	}
	if (cnt >= 1) {
		score += compute_score(cnt);
	}
	cout << score;
}
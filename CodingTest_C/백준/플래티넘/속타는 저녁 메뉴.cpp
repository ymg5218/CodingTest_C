// 11585

#include <iostream>
#include <vector>

using namespace std;

int N;
string text;
string pattern;

vector<int> failure() {
	vector<int> pi(N);
	pi[0] = 0;
	int i = 1, j = 0;
	while (i < N) {
		while (j > 0 and pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j]) {
			j++;
			pi[i] = j;
		}
		i++;
	}

	return pi;
}

int KMP(vector<int> pi) {
	int match_cnt = 0;

	int i = 0, j = 0;
	while (i < size(text)) {
		while (j > 0 and text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == N - 1) {
				match_cnt++;
				j = pi[j];
			}
			else
				j++;
		}

		i++;
	}

	return match_cnt;
}

int get_gcd(int a, int b) {
	if (a < b) swap(a, b);
	
	if (a % b == 0)
		return b;
	else
		return get_gcd(b, a % b);
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		pattern += c;
	}
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		text += c;
	}
	for (int i = 0; i < N - 1; i++) {
		text += text[i];
	}
}

void solution() {
	int cnt;

	auto pi = failure();
	cnt = KMP(pi);

	int gcd = get_gcd(N, cnt);
	
	cout << cnt / gcd << "/" << N / gcd;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	solution();
}

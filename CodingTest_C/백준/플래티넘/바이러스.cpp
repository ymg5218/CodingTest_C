#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int N, K;
vector<vector<int>> codes;
vector<vector<int>> reversed_codes;
int base_idx = -1;
int base_len = 10001;

void init() {
	cin >> N >> K;
	codes.assign(N, {});
	for (int i = 0; i < N; i++) {
		int size;
		cin >> size;
		if (base_len > size) {
			base_len = size;
			base_idx = i;
		}

		codes[i].assign(size, 0);
		for (int j = 0; j < size; j++) {
			cin >> codes[i][j];
		}
	}

	reversed_codes = codes;
	for (auto& code : reversed_codes) {
		reverse(code.begin(), code.end());
	}
}

vector<int> pi_table(const int s, const int e) {
	vector<int> failure(K);
	failure[0] = 0;
	int j = 0;

	for (int i = s + 1; i <= e; i++) {
		while (j > 0 && codes[base_idx][i] != codes[base_idx][j + s])
			j = failure[j - 1];

		if (codes[base_idx][i] == codes[base_idx][j + s])
			j++;

		failure[i - s] = j;
	}
	return failure;
}

bool KMP(const int T_idx, const vector<int>& pi, const int s, const int e, const vector<vector<int>>& target_set) {
	int j = 0;

	for (int i = 0; i < target_set[T_idx].size(); i++) {
		while (j > 0 && target_set[T_idx][i] != codes[base_idx][j + s])
			j = pi[j - 1];

		if (target_set[T_idx][i] == codes[base_idx][j + s])
			j++;

		if (j == K)
			return true;
	}
	return false;
}

void solution() {
	if (K > base_len) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i <= base_len - K; i++) {
		const int s = i, e = i + K - 1;

		auto pi = pi_table(s, e);

		bool matched_all = true;

		for (int now_idx = 0; now_idx < N; now_idx++) {
			if (now_idx == base_idx) continue;

			if (KMP(now_idx, pi, s, e, codes)) continue;
			if (KMP(now_idx, pi, s, e, reversed_codes)) continue;

			matched_all = false;
			break;
		}

		if (matched_all) {
			cout << "YES" << endl;
			return;
		}
	}

	swap(codes, reversed_codes);

	for (int i = 0; i <= base_len - K; i++) {
		const int s = i, e = i + K - 1;

		auto pi = pi_table(s, e);

		bool matched_all = true;

		for (int now_idx = 0; now_idx < N; now_idx++) {
			if (now_idx == base_idx) continue;

			if (KMP(now_idx, pi, s, e, codes)) continue;
			if (KMP(now_idx, pi, s, e, reversed_codes)) continue;

			matched_all = false;
			break;
		}

		if (matched_all) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main() {
	FASTIO;
	init();
	solution();

	return 0;
}